/*
Problema del productor-consumidor entre procesos.
Productor con espera activa.
Implementando semáforos (POSIX) con nombre
Compilar: gcc productor.c -lpthread -lrt */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/ipc.h>

#define TAM_MEM 34
#define RANGO 100000
char *Memoria;

int CrearLigaMemoria( void );
int DestruyeMemoriaCompartida( int id_Memoria , char *buffer );
sem_t * CrearSemaforo(  char *name , int val );
void InicializarSemaforos( sem_t ** prod_zona1 , sem_t **prod_zona2 , sem_t **con_zona1 , sem_t **con_zona2 );
void CerrarSemaforos( sem_t ** prod_zona1 , sem_t **prod_zona2 , sem_t **con_zona1 , sem_t **con_zona2 );

int main( int argc , char *argv[] ){
    if( argc < 2 ){
        printf("Uso: %s NoProductor (1 a 4) \n");
        exit(0);
    }
    sem_t **productor_zona1, **productor_zona2, **consumidor_zona1, **consumidor_zona2;
    sem_t *zona1, *zona2; 
    int n = atoi( argv[1] ),j, k, p, id , filas[5], salir=0;
    char produccion[3];
    productor_zona1 = ( sem_t ** ) malloc( 5 * sizeof(sem_t) );
    productor_zona2 = ( sem_t ** ) malloc( 5 * sizeof(sem_t) );
    consumidor_zona1 = ( sem_t ** ) malloc( 5 * sizeof(sem_t) );
    consumidor_zona2 = ( sem_t ** ) malloc( 5 * sizeof(sem_t) );
    switch( n ){
    case 1:
        memcpy( produccion , "aaa" , 3 );
        break;
    case 2:
        memcpy( produccion , "bbb" , 3 );
        break;
    case 3:
        memcpy( produccion , "ccc" , 3 );
        break;
    default:
        memcpy( produccion , "ddd" , 3 );
        break;
    }
    id = CrearLigaMemoria();
    InicializarSemaforos( productor_zona1 , productor_zona2 , consumidor_zona1 , consumidor_zona2 );

    for( j = 0 ; j < RANGO ; j++ ){
        salir = 0;
        while( 1 ){ // zona 1
            for( k = 0 , p = 0 ; k < 5 ; k++ , p += 3 ){
                sem_getvalue( productor_zona1[k] , &filas[k] );
                if( filas[k] == 1 ){
                    sem_wait( productor_zona1[k] );
                    printf( "Producción1: %c%c%c\n", produccion[0], produccion[1] , produccion[2] );
                    memcpy( Memoria + p , produccion , 3 );
                    sem_post( consumidor_zona1[k] );
                    salir = 1;
                    break;
                }
            }
            if( salir )
                break;
        }
        salir = 0;
        while( 1 ){ // zona 2
            for( k = 0 , p = 15 ; k < 5 ; k++ , p += 3 ){
                sem_getvalue( productor_zona2[k] , &filas[k] );
                if( filas[k] == 1 ){
                    sem_wait( productor_zona2[k] );
                    printf( "Produccion2: %c%c%c\n", produccion[0], produccion[1] , produccion[2] );
                    memcpy( Memoria + p , produccion , 3 );
                    sem_post( consumidor_zona2[k] );
                    salir = 1;
                    break;
                }
            }
            if( salir )
                break;
        }
    }

    CerrarSemaforos( productor_zona1 , productor_zona2 , consumidor_zona1 , consumidor_zona2 );
    return 0;
}

int CrearLigaMemoria( void ){
    int key2, shmid, crear=0, valor=0;
    key2 = ftok("/bin/ls",3);
    //Verifica si existe la zona de memoria
    if( ( shmid = shmget( key2 , sizeof( char ) * TAM_MEM , IPC_CREAT|IPC_EXCL|0666) ) == -1 ){
        // Si existe obtiene la memoria 
        if( ( shmid = shmget( key2 , sizeof( char ) * TAM_MEM , 0 ) ) == -1 ){
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
    if( ( Memoria = (char*)shmat( shmid , (char*) 0 , 0 ) ) == (void*)-1 ){
        perror("shmat \n");
        exit(1);
    }
    if( crear )
        memcpy( Memoria + 30 , &valor , 4 );

    return shmid; //Descriptor de la memoria
}

int DestruyeMemoriaCompartida( int id_Memoria , char *buffer ){
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
        printf("Semaforo: %s creado: %p\n", name,mut );
        sem_init( mut , 1 , val );
    }

    return mut;
}

void InicializarSemaforos( sem_t ** prod_zona1 , sem_t **prod_zona2 , sem_t **con_zona1 , sem_t **con_zona2 ){
    char nombreSemaforo[14];
    int j;
    for( j = 0; j < 5 ; j++ ){
        sprintf( nombreSemaforo , "P_Fila%d_zona1", j);
        prod_zona1[j] = CrearSemaforo( nombreSemaforo , 1 );
        sprintf( nombreSemaforo , "P_Fila%d_zona2", j);
        prod_zona2[j] = CrearSemaforo( nombreSemaforo , 1 );
        sprintf( nombreSemaforo , "C_Fila%d_zona1", j);
        con_zona1[j] = CrearSemaforo( nombreSemaforo , 0 );
        sprintf( nombreSemaforo , "C_Fila%d_zona2", j);
        con_zona2[j] = CrearSemaforo( nombreSemaforo , 0 );
    }
}

void CerrarSemaforos( sem_t ** prod_zona1 , sem_t **prod_zona2 , sem_t **con_zona1 , sem_t **con_zona2 ){
    char nombreSemaforo[14];
    int j;
    for( j = 0; j < 5 ; j++ ){
        sprintf( nombreSemaforo , "P_Fila%d_zona1", j);
        sem_unlink( nombreSemaforo );
        sem_close( prod_zona1[j] );
        sprintf( nombreSemaforo , "P_Fila%d_zona2", j);
        sem_unlink( nombreSemaforo );
        sem_close( prod_zona2[j] );
        sprintf( nombreSemaforo , "C_Fila%d_zona1", j);
        sem_unlink( nombreSemaforo );
        sem_close( con_zona1[j] );
        sprintf( nombreSemaforo , "C_Fila%d_zona2", j);
        sem_unlink( nombreSemaforo );
        sem_close( con_zona2[j] );
    }
}