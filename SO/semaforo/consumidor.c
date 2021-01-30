/*
Problema del productor-consumidor entre procesos.
Productor con espera activa.
Implementando semáforos (POSIX) con nombre
Compilar: gcc consumidor.c -lpthread -lrt */

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
void Guardar( sem_t **arch , int *archivo , char *consumido  );
int DestruyeMemoriaCompartida( int id_Memoria , char *buffer );
sem_t * CrearSemaforo(  char *name , int val );
void InicializarSemaforos( sem_t ** prod_zona1 , sem_t **prod_zona2 , sem_t **con_zona1 , sem_t **con_zona2 , sem_t **arch );
void CerrarSemaforos( sem_t ** prod_zona1 , sem_t **prod_zona2 , sem_t **con_zona1 , sem_t **con_zona2 ,int *archivos , sem_t **arch );

int main( int argc , char *argv[] ){
    if( argc < 2 ){
        printf("Uso: %s NoProductores\n");
        exit(0);
    }
    sem_t **productor_zona1, **productor_zona2, **consumidor_zona1, **consumidor_zona2 , **arch;
    sem_t *contador; 
    int NProductores = atoi( argv[1] ),j, n, p, id , filas[5], salir=0 , archivo[4], consumidos, cont , ultimo = 0;
    char nombreSemaforo[14] , produccion[3];
    productor_zona1 = ( sem_t ** ) malloc( 5 * sizeof(sem_t) );
    productor_zona2 = ( sem_t ** ) malloc( 5 * sizeof(sem_t) );
    consumidor_zona1 = ( sem_t ** ) malloc( 5 * sizeof(sem_t) );
    consumidor_zona2 = ( sem_t ** ) malloc( 5 * sizeof(sem_t) );
    arch = ( sem_t ** ) malloc( 5 * sizeof(sem_t) );

    id = CrearLigaMemoria();
    
    if( ( archivo[0] = open( "aaa.txt" , O_WRONLY|O_CREAT|O_APPEND , 0666 ) ) == -1 )
        perror( "aaa.txt: " );
    if( ( archivo[1] = open( "bbb.txt" , O_WRONLY|O_CREAT|O_APPEND , 0666 ) ) == -1 )
        perror( "bbb.txt: " );
    if( ( archivo[2] = open( "ccc.txt" , O_WRONLY|O_CREAT|O_APPEND , 0666 ) ) == -1 )
        perror( "ccc.txt: " );
    if( ( archivo[3] = open( "ddd.txt" , O_WRONLY|O_CREAT|O_APPEND , 0666 ) ) == -1 )
        perror( "ddd.txt: " );
    InicializarSemaforos( productor_zona1 , productor_zona2 , consumidor_zona1 ,consumidor_zona2 , arch );
    contador = CrearSemaforo( "contador" , 1 );

    while( 1 ){
        sem_wait( contador );
        memcpy( &cont , Memoria + 30 , 4 );
        if( cont < RANGO * NProductores ){
            if( cont ==  RANGO * NProductores - 1 )
                ultimo = 1;
            cont++;
            memcpy( Memoria + 30 , &cont , 4 );
        }
        else{
            sem_post( contador );
            break;
        }
        salir = 0;
        while( 1 ){ // zona 1
            for( n = 0 , p = 0 ; n < 5 ; n++ , p += 3 ){
                sem_getvalue( consumidor_zona1[n] , &filas[n] );
                if( filas[n] == 1 ){
                    sem_wait( consumidor_zona1[n] );
                    memcpy( produccion , Memoria + p , 3 );
                    printf("Consumio, zona1: %c%c%c\n",produccion[0],produccion[1],produccion[2]);
                    sem_post( productor_zona1[n] );
                    salir = 1;
                    break;
                }
            }
            if( salir )
                break;
        }
        Guardar( arch , archivo , produccion );
        salir = 0;
        while( 1 ){ // zona 2
            for( n = 0 , p = 15 ; n < 5 ; n++ , p += 3 ){
                sem_getvalue( consumidor_zona2[n] , &filas[n] );
                if( filas[n] == 1 ){
                    sem_wait( consumidor_zona2[n] );
                    memcpy( produccion , Memoria + p , 3 );
                    printf("Consumio, zona2: %c%c%c\n",produccion[0],produccion[1],produccion[2]);
                    sem_post( productor_zona2[n] );
                    salir = 1;
                    break;
                }
            }
            if( salir )
                break;
        }
        Guardar( arch , archivo , produccion );

        sem_post( contador );
    }

    CerrarSemaforos( productor_zona1 , productor_zona2 , consumidor_zona1 ,consumidor_zona2 , archivo , arch );
    sem_unlink("contador"); sem_close(contador);

    if( ultimo ){
        sem_destroy( contador );
        DestruyeMemoriaCompartida( id , Memoria);
        for( j = 0 ; j < 5 ; j++ ){
            sem_destroy( productor_zona1[j] );
            sem_destroy( productor_zona2[j] );
            sem_destroy( consumidor_zona1[j] );
            sem_destroy( consumidor_zona2[j] );
            sem_destroy( arch[j] );
        }
    }
    
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

void Guardar( sem_t **arch , int *archivo , char *consumido ){
    char aux[4];
    int file;

    if( !strncmp( consumido , "aaa" , 3 ) )
        file = 0;
    else if( !strncmp( consumido , "bbb" , 3 ) )
        file = 1;
    else if( !strncmp( consumido , "ccc" , 3 ) )
        file = 2;
    else if( !strncmp( consumido , "ddd" , 3 ) )
        file = 3;

    sem_wait( arch[file] );
    sprintf( aux , "%c%c%c\n" , consumido[0],consumido[1],consumido[2] );
    write( archivo[file] , aux , sizeof(aux) );
    sem_post( arch[file] );
}

void InicializarSemaforos( sem_t ** prod_zona1 , sem_t **prod_zona2 , sem_t **con_zona1 , sem_t **con_zona2 , sem_t **arch){
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
        sprintf( nombreSemaforo , "Archivo_%d", j);
        arch[j] = CrearSemaforo( nombreSemaforo , 1 );
    }
}

void CerrarSemaforos( sem_t ** prod_zona1 , sem_t **prod_zona2 , sem_t **con_zona1 , sem_t **con_zona2 ,int *archivo , sem_t **arch  ){
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
        sprintf( nombreSemaforo , "Archivo_%d", j);
        sem_unlink( nombreSemaforo );
        sem_close( arch[j] );
        close( archivo[j] );
    }
}