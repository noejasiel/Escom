#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/ipc.h>

#define TAM_MEM 1

int *Memoria;

int CrearLigaMemoria();
int DestruyeMemoriaCompartida(int id_Mem, int *buffer);
sem_t * CrearSemaforo(char *name, int val);

int main()
{
	pid_t pid;
	int i, j, id, inicio = 0, fin = 100, status, zona1, zona2;
	char *name1 = "consumidor_zona1",  *name2 = "productor_zona1";
	char *name3 = "consumidor_zona2", *name4 = "productor_zona2";
	sem_t *consumidor_zona1, *productor_zona1, *consumidor_zona2, *productor_zona2;
	
	consumidor_zona1 = CrearSemaforo(name1, 0);
	productor_zona1 = CrearSemaforo(name2, 1);
	consumidor_zona2= CrearSemaforo(name3, 0);
	productor_zona2 = CrearSemaforo(name4, 1);
	id = CrearLigaMemoria();
	
	for(i=0; i<3; i++)
	{
		pid = fork();
		if(pid<0)
		{
			printf("No se pudo crear al hijo.\n");
			exit(1);
		}
		else if(pid==0)//	Productor
		{
			id = CrearLigaMemoria();
			for(j=inicio; j<fin; j++)
			{
				while(1)
				{
					sem_getvalue(productor_zona1, &zona1);
					if(zona1 == 1)
					{
						sem_wait(productor_zona1);
						Memoria[0] = j;
						printf("\tProductor %d en la zona 1: %d\n", i+1, j);
						sem_post(consumidor_zona1);
						break;
					}
					sem_getvalue(productor_zona2, &zona2);
					if(zona2 == 1)
					{
						sem_wait(productor_zona2);
						Memoria[1] = j;
						printf("\tProductor %d en la zona 2: %d\n", i+1, j);
						sem_post(consumidor_zona2);
						break;
					}
				}
			}
			sem_unlink(name1);
			sem_unlink(name2);
			sem_unlink(name3);
			sem_unlink(name4);
			exit(0);
		}
		inicio += 100;
		fin += 100;
	}
//						Consumidor
	for(i=0; i<2; i++)
	{
		pid=fork();
		if(pid<0)
		{
			printf("No se pudo crear al hijo.\n");
			exit(1);
		}
		else if(pid == 0)
		{
			for(j=0; j<200; j++)
			{
				while(1)
				{
					sem_getvalue(consumidor_zona1, &zona1);
					if(zona1 == 1)
					{
						sem_wait(consumidor_zona1);
						printf("Consumidor %d de zona 1: %d\t\t%d\n", i+1, Memoria[0], j);
						sem_post(productor_zona1);
						break;
					}
					sem_getvalue(consumidor_zona2, &zona2);
					if(zona2 == 1)
					{
						sem_wait(consumidor_zona2);
						printf("Consumidor %d de zona 2: %d\t\t%d\n", i+1, Memoria[1], j);
						sem_post(productor_zona2);
						break;
					}
				}
			}
			sem_unlink(name1);
			sem_unlink(name2);
			sem_unlink(name3);
			sem_unlink(name4);
			exit(0);
		}
	}
		
	wait(&status);
	DestruyeMemoriaCompartida(id, Memoria);
	
	sem_close(productor_zona1);
	sem_destroy(productor_zona1);
	sem_close(consumidor_zona1);
	sem_destroy(consumidor_zona1);
	sem_close(productor_zona2);
	sem_destroy(productor_zona2);
	sem_close(consumidor_zona2);
	sem_destroy(consumidor_zona2);
	return 0;
}

int CrearLigaMemoria()
{
	int key2, shmid;
	key2 = ftok("/bin/ls", 3);
	
	if((shmid = shmget(key2, sizeof(int) * TAM_MEM, IPC_CREAT|IPC_EXCL|0666)) == -1)
	{
		if((shmid = shmget(key2, sizeof(int) * TAM_MEM, 0)) == -1)
		{
			perror("shmget");
			exit(1);
		}
		else
		{
			printf("\nSe ligo a la memoria con id: %d\n", shmid);
		}
	}
	else
	{
		printf("\nCreo la memoria con id: %d\n", shmid);
	}
	
	if((Memoria = (int *) shmat(shmid, (int *) 0, 0)) == (void *)-1)
	{
		perror("shmat\n");
		exit(1);
	}
	
	return shmid;
}

int DestruyeMemoriaCompartida(int id_Mem, int *buffer)
{
	if(id_Mem != 0 || id_Mem != -1)
	{
		shmdt(buffer);
		shmctl(id_Mem, IPC_RMID, (struct shmid_ds *)NULL);
		
		printf("\nSe destruyo la memoria\n");
	}
	else
	{
		shmdt(buffer);
		printf("\nSe Desligo de la memoria\n");
	}
}

sem_t * CrearSemaforo(char *name, int val)
{
	sem_t *mut;
	if((mut = sem_open(name, O_CREAT|O_EXCL, 0666, val)) == SEM_FAILED)
	{
		if((mut = sem_open(name, 0)) == SEM_FAILED)
		{
			printf("Error al abrir el semaforo\n");
		}
		else
		{
			printf("Ligado al semaforo correctamente %p\n", mut);
		}
	}
	else
	{
		printf("Semaforo creado: %p\n", mut);
		sem_init(mut, 1, val);
	}
	return mut;
}