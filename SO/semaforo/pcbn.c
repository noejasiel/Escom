#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>


void P(int semid,int sem);
void V(int semid,int sem);

int main(void){
	int semid = semget(0xa, 2, IPC_CREAT|IPC_EXCL|0600);

	if(errno == EEXIST){
		printf("ya esxisten los semaforos para esta key \n");
	}else{
		printf("el identificador es: %d \n", semid);
		semid = semget(0xa, 0, 0);
		if(semid != -1){
			semctl(semid, 0, SETVAL, 1);
			semctl(semid, 1, SETVAL, 0);
			/*printf(" semaforo 0 = %d \n",semctl(semid, 0, GETVAL));
			printf(" semaforo 1 = %d \n",semctl(semid, 1, GETVAL)); 
			se obtiene el valor del sem*/

			int pid = fork();
			int contador = 0;
			if (pid > 0){
				
				while(contador < 10){
				P(semid, 1);
				printf("recibiendo desde el hijo %d\n",contador );
				sleep(2);
				V(semid, 0);
				contador++;
				}
				
				
			}else{
				
				while(contador < 10){
					P(semid, 0);
					printf("enviando al padre %d\n",contador );
				sleep(2);
				V(semid, 1);
				contador++;
				}
				
				
				
			}
		}else{
			printf("error bro\n" );
		}
	}

	
	exit(0);
}




void P(int semid,int sem){
	struct sembuf buf;
	buf.sem_num = sem;
	buf.sem_op = -1;
	buf.sem_flg = 0;
	semop(semid, &buf, 1);
}
void V(int semid,int sem){
	struct sembuf buf;
	buf.sem_num = sem;
	buf.sem_op = 1;
	buf.sem_flg = 0;
	semop(semid, &buf, 1);
}