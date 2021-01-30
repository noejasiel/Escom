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

int CrearLigamemoria( void );
int DestruyeMemoriaCompartida( int id_Memoria , int *buffer );
sem_t * CrearSemaforo(  char *name , int val );

int main( int argc , char *argv[] ){
    if( argc < 2 ){
        printf( "Uso: %s No_productores\n",argv[0] );
        exit(1);
    }
    pid_t pid;
    int id, ultimo = 0, Nproductores = atoi( argv[1] );
    char *name1 = "consumidor_zona1", *name2 = "productor_zona1";
    char *name3 = "consumidor_zona2", *name4 = "productor_zona2";
    char *name5 = "consumidos";
    sem_t *consumidor_zona1 , *productor_zona1, *consumidor_zona2 , *productor_zona2, *consumidos;

    consumidor_zona1 = CrearSemaforo( name1 , 0 );
    productor_zona1 = CrearSemaforo( name2 , 1 );
    consumidor_zona2 = CrearSemaforo( name3 , 0 );
    productor_zona2 = CrearSemaforo( name4 , 1 );
    consumidos = CrearSemaforo( name5 , 1 );
    id = CrearLigamemoria();

    for( ;  ; ){
        sem_wait( consumidos );
        if( Memoria[2] < RANGO * Nproductores ){
            if( Memoria[2] == ( RANGO * Nproductores - 1 ) )
                ultimo = 1;
            Memoria[2]++;
        }
        else{
            sem_post( consumidos );
            break;
        }
        while( 1 ){
            if( sem_wait( consumidor_zona1 ) == 0 ){
                printf("Consumidor de zona 1: %d\n", Memoria[0] );
                sem_post( productor_zona1 );
                break;
            }
            else if( sem_wait( consumidor_zona2 ) == 0 ){
                printf("Consumidor de zona 2: %d\n", Memoria[1] );
                sem_post( productor_zona2 );
                break;
            }
        }
        sem_post( consumidos );
    }
    sem_unlink( name1 );
    sem_close( productor_zona1 );
    sem_unlink( name2 );
    sem_close( consumidor_zona1 );
    sem_unlink( name3 );
    sem_close( productor_zona2 );
    sem_unlink( name4 );
    sem_close( consumidor_zona2 );
    sem_unlink( name5 );
    sem_close( consumidos );
    
    if( ultimo ){
        DestruyeMemoriaCompartida( id , Memoria );
        sem_destroy( productor_zona1 );
        sem_destroy( consumidor_zona1 );
        sem_destroy( productor_zona2 );
        sem_destroy( consumidor_zona2 );
        sem_destroy( consumidos );
    }
    
    return 0;
}

int CrearLigamemoria( void ){
    int key2,shmid;
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
    else
        printf("Creo la memoria con id: %d\n",shmid);
    //Se liga a la zona de memoria compartida
    if( ( Memoria = (int*)shmat( shmid , (int*) 0 , 0 ) ) == (void*)-1 ){
        perror("shmat \n");
        exit(1);
    }

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