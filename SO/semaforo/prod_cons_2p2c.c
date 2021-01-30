#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/types.h>

sem_t *sem1, *sem2, *sem3, *sem4;

int main(){
    key_t key, key2;
    int id, id2;
    int *buffer[2];
    pid_t pid, pid2;
    // Memoria compartida 1
    key = ftok("dev/null", 65);
    id = shmget(id, sizeof(int), 0644 | IPC_CREAT);
    if( id < 0 ){
        perror("Error creando memoria compartida");
        exit(0);
    }
    buffer[0] = shmat(id, NULL, 0);
    *buffer[0] = 100;

    // Memoria compartida 2
    key2 = ftok("dev/null", 65);
    id2 = shmget(id2, sizeof(int), 0644 | IPC_CREAT);
    if( id2 < 0 ){
        perror("Error creando memoria compartida");
        exit(0);
    }
    buffer[1] = shmat(id2, NULL, 0);
    *buffer[1] = 100;

    // Semaforos seccion critica 1
    sem1 = sem_open("/sem_prod", O_CREAT, 0644, 1);
    sem2 = sem_open("/sem_cons", O_CREAT, 0644, 0);
    if( sem1 == (sem_t*)-1 || sem2 == (sem_t*)-1 ){
        perror("Error creando semaforos");
        sem_unlink("/sem_prod");
        sem_unlink("/sem_cons");
        exit(0);
    }

    // Semaforos seccion critica 2
    sem3 = sem_open("/sem_prod2", O_CREAT, 0644, 1);
    sem4 = sem_open("/sem_cons2", O_CREAT, 0644, 0);
    if( sem3 == (sem_t*)-1 || sem4 == (sem_t*)-1 ){
        perror("Error creando semaforos");
        sem_unlink("/sem_prod2");
        sem_unlink("/sem_cons2");
        exit(0);
    }
    
    // ------------------------------------------------------- Procesos principales -------------------------------------------------------
    pid = fork();
   if(pid < 0){
       printf("Error creando hijo\n");
       exit(1);
   }else if( pid == 0 ){
       // HIJO - PRODUCTOR
       for(int i=0;i<10;i++){
           sem_wait(sem1);
           *buffer[0] = i;
           printf("Productor 1 produjo: %d\n", *buffer[0]);
           sem_post(sem2);
       }        
   }else{

       pid2 = fork();
       if( pid2 < 0 ){
        printf("Error creando hijo\n");
        exit(1);
       }else if( pid2 == 0 ){
           // HIJO - PRODUCTOR 2
            for(int i=0;i<10;i++){
                sem_wait(sem1);
                *buffer[0] = i+10;
                printf("Productor 2 produjo: %d\n", *buffer[0]);
                sem_post(sem2);
            }     
       }else{
           // PADRE - CONSUMIDOR
            for(int i=0;i<20;i++){
                sem_wait(sem2);
                printf("Consumidor consumió: %d\n", *buffer[0]);
                sem_post(sem1);
            }
            
            // Eliminar semaforos y memoria compartida
            shmdt( buffer[0] );
            shmdt( buffer[1] );
            shmctl( id, IPC_RMID, 0 );
            shmctl( id2, IPC_RMID, 0 );
            sem_unlink( "sem_prod" );
            sem_unlink( "sem_prod2" );
            sem_unlink( "sem_cons" );
            sem_unlink( "sem_cons2" );
            sem_close(sem1);
            sem_close(sem2);
            sem_close(sem3);
            sem_close(sem4);
       }
   }

    return 0;
}