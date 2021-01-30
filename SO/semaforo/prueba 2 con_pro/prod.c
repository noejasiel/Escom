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

#define TAM_MEM 3
#define RANGO 10
int *Memoria;

int CrearLigaMemoria( void );
int DestruyeMemoriaCompartida( int id_Memoria , int *buffer );
sem_t * CrearSemaforo(  char *name , int val );

int main( int argc , char *argv[] ){
    if( argc < 2 ){
        printf("Uso: %s Valor_Inicial_Produccion\n", argv[0]);
        exit(1);
    }
    pid_t pid;
    int id, j, produccion = atoi( argv[1] );
    char *name1 = "consumidor_zona1", *name2 = "productor_zona1";
    char *name3 = "consumidor_zona2", *name4 = "productor_zona2";
    sem_t *consumidor_zona1 , *productor_zona1, *consumidor_zona2 , *productor_zona2;

    consumidor_zona1 = CrearSemaforo( name1 , 0 );
    productor_zona1 = CrearSemaforo( name2 , 1 );
    consumidor_zona2 = CrearSemaforo( name3 , 0 );
    productor_zona2 = CrearSemaforo( name4 , 1 );
    id = CrearLigaMemoria();

    for( j = 0 ; j < RANGO ; j++ ){
        while ( 1 ){
            if( sem_wait( productor_zona1 ) == 0 ){
                Memoria[0] = produccion;
                printf("Productor en la zona 1: %d\n", produccion++ );
                sleep(1);
                sem_post( consumidor_zona1 );
                break;
            }
            else if( sem_wait( productor_zona2 ) == 0) {
                Memoria[1] = produccion;
                printf("Productor en la zona 2: %d\n", produccion++ );
                sleep(1);
                sem_post( consumidor_zona2 );
                break;
            }
        }
    }
    sem_unlink( name1 );
    sem_close( productor_zona1 );
    sem_unlink( name2 );
    sem_close( consumidor_zona1 );
    sem_unlink( name3 );
    sem_close( productor_zona2 );
    sem_unlink( name4 );
    sem_close( consumidor_zona2 );

    return 0;
}

int CrearLigaMemoria( void ){
    int key2,shmid,crear=0;
    key2 = ftok("/bin/ls",3);

    //Verifica si existe la zona de memoria
    if( ( shmid = shmget( key2 , sizeof( int ) * TAM_MEM , IPC_CREAT|IPC_EXCL|0666) ) == -1 ){
        // Si existe obtiene la memoria 
        if( ( shmid = shmget( key2 , sizeof( int ) * TAM_MEM , 0 ) ) == -1 ){
            perror("shmget \n");
            exit(1);
        }
        else
            printf("Se ligo a la memoria con id: %d\n",shmid);
    }
    else{
        printf("Creo la memoria con id: %d\n",shmid);
        crear = 1;
    }
    //Se liga a la zona de memoria compartida
    if( ( Memoria = (int*)shmat( shmid , (int*) 0 , 0 ) ) == (void*)-1 ){
        perror("shmat \n");
        exit(1);
    }
    if( crear )
        Memoria[2] = 0;

    return shmid; //Descriptor de la memoria
}

int DestruyeMemoriaCompartida( int id_Memoria , int *buffer ){
    if( id_Memoria != 0 || id_Memoria != -1 ){ //Valida si ya se destruyo
        shmdt( buffer );                       //Quita la liga hacia la memoria
        shmctl( id_Memoria , IPC_RMID , (struct shmid_ds *) NULL ); //Destruye la zona de memoria
        printf("Se destruyo la memoria\n");
    } 
    else{
        shmdt( buffer );
        printf("Se desligo la memoria\n");
    }
    
}

sem_t * CrearSemaforo( char *name , int val){
    sem_t *mut;
    if( ( mut = sem_open( name , O_CREAT | O_EXCL , 0666 , val ) ) == SEM_FAILED ){
        if( ( mut = sem_open( name , 0 ) ) == SEM_FAILED )
            printf("Error al abrir el semaforo\n");
        else
            printf("Ligado al semaforo correctamente %p\n", mut);
    }
    else{
        printf("Semaforo: %s creado: %p\n", name,mut);
        sem_init( mut , 1 , val );
    }

    return mut;
}