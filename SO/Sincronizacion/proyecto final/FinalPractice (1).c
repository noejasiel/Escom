#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/ipc.h>

#define IPC_RESULT_ERROR (-1)
#define TAM_MEM 5
#define RANGO 10000
#define NoPRODUCTORES 5
#define NoCONSUMIDORES 3

int *Memoria;

int getSharedBlock();
int * LigarMemoria();
int DesligarMemoria(int *);
int DestruirMemoria();

sem_t * CrearSemaforo (char *, int); //Función inicializadora de semaforos
void clsSemaphore(char *, sem_t *); //Funcion removedora de semaforos

void GuardarProductos(sem_t *, int, int, int, FILE *); //Funcion que graba la producción en un archivo

int main()
{
    sem_t *prod1, *Consu1, *prod2, *Consu2; //Semaforos
    sem_t *prod3, *Consu3, *prod4, *Consu4; //Semaforos
    sem_t *Count; // Semaforo Contador
    sem_t *archivo; //Semafoto archivo
    pid_t pid; //Id de procesos
    char *nameP1, *nameC1, *nameP2, *nameC2;  //Nombre de Semaforos
    char *nameP3, *nameC3, *nameP4, *nameC4;  //Nombre de Semaforos
    char *nameCuenta; //Semaforo Contador
    char *nameArchivo;  //Semaforo archivo
    int estado1, estado2, estado3, estado4; //Estatus de los semaforos
    int a; //Manipulación de los argumentos
    int x, y; //Control de Loop
    int last; //BAndera para ultimo dato
    int p; //Produccion
    FILE *doc; //Apuntador a archivo
    
    DestruirMemoria(Memoria);
    
    //Inicialización de Variables
    nameC1 = "Consu1";
    nameP1 = "prod1";
    nameC2 = "Consu2";
    nameP2 = "prod2";
    nameC3 = "Consu3";
    nameP3 = "prod3";
    nameC4 = "Consu4";
    nameP4 = "prod4";
    nameCuenta = "Cuenta";
    nameArchivo = "Archivo";
    
    //Inicialización de Semaforos
    Consu1 = CrearSemaforo(nameC1, 0);
    prod1 = CrearSemaforo(nameP1, 1);
    Consu2 = CrearSemaforo(nameC2, 0);
    prod2 = CrearSemaforo(nameP2, 1);
    Consu3 = CrearSemaforo(nameC3, 0);
    prod3 = CrearSemaforo(nameP3, 1);
    Consu4 = CrearSemaforo(nameC4, 0);
    prod4 = CrearSemaforo(nameP4, 1);
    Count = CrearSemaforo(nameCuenta, 1);
    archivo = CrearSemaforo(nameArchivo, 1);
    
    //Toma el bloque de memoria compartida
    Memoria = LigarMemoria();
    if(Memoria == NULL)
    {
        printf("ERROR: couldn't get block\n");
        return -1;
    }
    
    //Zona de Productores
    for(x = 0; x < NoPRODUCTORES; x++)
    {
        pid = fork();
        
        if(pid == -1)
            perror("ERROR: couldn't get child process\n");
        else if(pid == 0)
        {
            //Toma el bloque de memoria compartida
            Memoria = LigarMemoria();
            if(Memoria == NULL)
            {
            printf("ERROR: couldn't get block\n");
            return -1;
            }
            
            //Inicia ciclo de producción
            for(y = 0; y < RANGO; y++)
            {
                while(1)
                {
                    //Zona Critica 1
                    sem_getvalue(prod1, &estado1);
                    if(estado1 == 1)
                    {
                        sem_wait(prod1);
                        Memoria[0] = (x+1) * 111;
                        printf("Prod No %d Prods %d Zona 1\n", x+1, Memoria[0]);
                        sem_post(Consu1);
                        break;
                    }
                    //Zona Critica 2
                    sem_getvalue(prod2, &estado2);
                    if(estado2 == 1)
                    {
                        sem_wait(prod2);
                        Memoria[1] = (x+1) * 111;
                        printf("Prod No %d Prods %d Zona 2\n", x+1, Memoria[1]);
                        sem_post(Consu2);
                        break;
                    }
                    //Zona Critica 3
                    sem_getvalue(prod3, &estado3);
                    if(estado3 == 1)
                    {
                        sem_wait(prod3);
                        Memoria[2] = (x+1) * 111;
                        printf("Prod No %d Prods %d Zona 3\n", x+1, Memoria[2]);
                        sem_post(Consu3);
                        break;
                    }
                    //Zona Critica 4
                    sem_getvalue(prod4, &estado4);
                    if(estado4 == 1)
                    {
                        sem_wait(prod4);
                        Memoria[3] = (x+1) * 111;
                        printf("Prod No %d Prods %d Zona 4\n", x+1, Memoria[3]);
                        sem_post(Consu4);
                        break;
                    }
                }
            }
            clsSemaphore(nameC1, Consu1);
            clsSemaphore(nameP1, prod1);
            clsSemaphore(nameC2, Consu2);
            clsSemaphore(nameP2, prod2);
            clsSemaphore(nameC3, Consu3);
            clsSemaphore(nameP3, prod3);
            clsSemaphore(nameC4, Consu4);
            clsSemaphore(nameP4, prod4);
            
            DesligarMemoria(Memoria);
            
            exit(0);
        }
    }
    
    //Zona de Consumo
    for(x = 0; x < NoCONSUMIDORES; x++)
    {
        pid = fork();
        if(pid == -1)
            perror("ERROR: couldn't get child process\n");
        else if(pid == 0)
        {
            while(1)
            {
                //Zona critica Contador
                sem_wait(Count);
                //Verifica que no se haya consumido mas de la producción total
                if(Memoria[4] < RANGO * NoPRODUCTORES)
                {
                    //Verifica si estamos en el ultimo elemento
                    if(Memoria[4] == ((RANGO * NoPRODUCTORES)-1))
                        last = 1;
                    Memoria[4]++;
                    printf("%d\n", Memoria[4]);
                    sem_post(Count);
                }else
                {
                    printf("I'M IN\n");
                    sem_post(Count);
                    break;
                }
                
                while(1)
                {
                    //Zona Critica 1
                    sem_getvalue(Consu1, &estado1);
                    if(estado1 == 1)
                    {
                        sem_wait(Consu1);
                        printf("Cons No %d Conss %d Zona 1\n", x+1, Memoria[0]);
                        GuardarProductos(archivo, Memoria[0], x+1, Memoria[4], doc);
                        sem_post(prod1);
                        break;
                    }
                    //Zona Critica 2
                    sem_getvalue(Consu2, &estado2);
                    if(estado2 == 1)
                    {
                        sem_wait(Consu2);
                        printf("Cons No %d Conss %d Zona 2\n", x+1, Memoria[1]);
                        GuardarProductos(archivo, Memoria[1], x+1, Memoria[4], doc);
                        sem_post(prod2);
                        break;
                    }
                    //Zona Critica 3
                    sem_getvalue(Consu3, &estado3);
                    if(estado3 == 1)
                    {
                        sem_wait(Consu3);
                        printf("Cons No %d Conss %d Zona 3\n", x+1, Memoria[2]);
                        GuardarProductos(archivo, Memoria[2], x+1, Memoria[4], doc);
                        sem_post(prod3);
                        break;
                    }
                    //Zona Critica 4
                    sem_getvalue(Consu4, &estado4);
                    if(estado4 == 1)
                    {
                        sem_wait(Consu4);
                        printf("Cons No %d Conss %d Zona 4\n", x+1, Memoria[3]);
                        GuardarProductos(archivo, Memoria[3], x+1, Memoria[4], doc);
                        sem_post(prod4);
                        break;
                    }
                }
            }

            sem_unlink(nameC1);
            sem_close(Consu1);
            sem_unlink(nameP1);
            sem_close(prod1);
            sem_unlink(nameC2);
            sem_close(Consu2);
            sem_unlink(nameP2);
            sem_close(prod2);
            sem_unlink(nameC3);
            sem_close(Consu3);
            sem_unlink(nameP3);
            sem_close(prod3);
            sem_unlink(nameC4);
            sem_close(Consu4);
            sem_unlink(nameP4);
            sem_close(prod4);
            sem_unlink(nameArchivo);
            sem_close(archivo);
            sem_unlink(nameCuenta);
            sem_close(Count);
            
            DesligarMemoria(Memoria);
            
            if(last)
            {
                sem_destroy(Consu1);
                sem_destroy(prod1);
                sem_destroy(Consu2);
                sem_destroy(prod2);
                sem_destroy(Consu3);
                sem_destroy(prod3);
                sem_destroy(Consu4);
                sem_destroy(prod4);
                sem_destroy(Count);
                sem_destroy(archivo);
                DestruirMemoria();
            }
        }
    }
    return 0;
}

int getSharedBlock()
{
    key_t aux, key;
    
    //Request a key
    //The key is linked to a filename, so that others programs can acces it
    key = ftok("/bin/ls", 0);
    
    if(key == IPC_RESULT_ERROR)
        return IPC_RESULT_ERROR;
    
    //get shared block --- create if it doesn't exist
    return shmget(key, sizeof(int)*5, 0644|IPC_CREAT);
}

int * LigarMemoria()
{
    int sharedBlockID = getSharedBlock();
    int *result;
    
    if(sharedBlockID == IPC_RESULT_ERROR)
        return NULL;
    
    //Map the shared block into this process's Memoria
    // and give a pointer to it
    result = shmat(sharedBlockID, NULL, 0);
    if(result == NULL)
        return NULL;
    
    return result;
}

int DesligarMemoria(int *block)
{
    return (shmdt(block) != IPC_RESULT_ERROR);
    printf("OK");
}

int DestruirMemoria()
{
    int sharedBlockID = getSharedBlock();
    
    if(sharedBlockID == IPC_RESULT_ERROR)
        return IPC_RESULT_ERROR;
    
    return(shmctl(sharedBlockID, IPC_RMID, NULL) != IPC_RESULT_ERROR);
}

sem_t * CrearSemaforo (char * name, int init)
{
	sem_t * auxS;

	if((auxS = sem_open(name, O_CREAT|O_EXCL, 0666, init)) == SEM_FAILED)
	{
		if((auxS = sem_open(name, 0)) == SEM_FAILED)
			perror("Error al abrir semaforo\n");
		else
			printf("Semaforo ligado de manera correcta\n");
	}else
	{
		printf("Semaforo con nombre %s creado de manera correcta\n", name);
		sem_init(auxS, 1, init);
	}

	return auxS;
}

void clsSemaphore(char *name, sem_t * semaphore)
{
    sem_unlink(name);
    sem_close(semaphore);
}

void GuardarProductos(sem_t *archivo, int prod, int cons, int zone, FILE *doc)
{
    sem_wait(archivo);
    //Apertura de archivo
    doc = fopen("bck.txt", "a");
    
    if(doc == NULL)
        perror("ERROR: couldn't get the file\n");
    
    fprintf(doc, "%d Consumer->%d Zone->%d\n", prod, cons, zone);
    
    //Clausura de archivo
    fclose(doc);
    sem_post(archivo);
}
