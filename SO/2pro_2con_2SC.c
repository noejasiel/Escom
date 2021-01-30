#include <fcntl.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>




int buildMemory( void );
sem_t * createSem(  char *nameSem , int value );
int killMemory( int ligaMemory , int *buf );

int *Memoria;
int main(){
    pid_t pid;
    int id, j = 0, i, status, inicio = 0 ,fin = 10, ultimo = 0;
    char *name1 = "consu_z1", *name2 = "pro_z1";
    char *name3 = "consu_z2", *name4 = "pro_z2";
    char *name5 = "consumidos";
    sem_t *consu_z1 , *pro_z1, *consu_z2 , *pro_z2, *consumidos;

    consu_z1 = createSem( name1 , 0 );
    pro_z1 = createSem( name2 , 1 );
    consu_z2 = createSem( name3 , 0 );
    pro_z2 = createSem( name4 , 1 );
    consumidos = createSem( name5 , 1 );
    id = buildMemory();
    Memoria[2] = 0;
    
    for( i = 0 ; i < 2 ; i++ ){
        pid = fork();
        if( pid == -1 )
            perror( "Error" );
        else if( pid == 0 ){
            id = buildMemory();
            for( j = inicio ; j < fin ; j++ ){
                while ( 1 ){
                    //sem_wait funcion ya predefinida evalua el valor del productor
                    // 0 o 1 y decide si lo deja entrar o no
                    if( sem_wait( pro_z1 ) == 0 ){
                        Memoria[0] = j;
                        printf("Soy el Productor %d y estoy en zonaCritica %d y el dato es: %d\n", i+1 ,i+1, j );
                        sleep(1);
                        //sem_post funcion ya predefinida y desbloquea a mi consumidor o sea aumenta su valor
                         // 0 -> 1
                        sem_post( consu_z1 );
                        printf("\n");
                        break;
                    }
                    //sem_wait funcion ya predefinida evalua el valor del productor
                    // 0 o 1 y decide si lo deja entrar o no
                    else if( sem_wait( pro_z2 ) == 0) {
                        Memoria[1] = j;
                        printf("Soy el Productor %d y estoy en zonaCritica 2 y el dato es: %d\n", i+1 , j );
                        sleep(1);
                        //sem_post funcion ya predefinida y desbloquea a mi consumidor o sea aumenta su valor
                         // 0 -> 1
                        sem_post( consu_z2 );
                        printf("\n");
                        break;
                    }
                }
            }
            
            exit(0);
        }
        inicio += 10;
        fin += 10;
    }

    for( i = 0 ; i < 2 ; i++ ){
        pid = fork();
        if ( pid == -1 )
            perror( "Error al crear el proceso hijo: " );
        else if( pid == 0 ){
            for( ;  ; ){
                sem_wait( consumidos );
                if( Memoria[2] < 10 * 2 ){
                    if( Memoria[2] == ( 10 * 2 - 1 ) )
                        ultimo = 1;
                    Memoria[2]++;
                    sem_post( consumidos );
                }
                else{
                    sem_post( consumidos );
                    break;
                }
                while( 1 ){
                    //sem_wait funcion ya predefinida evalua el valor del consumidor
                    // 0 o 1 y decide si lo deja entrar o no
                    if( sem_wait( consu_z1 ) == 0 ){
                        printf(" soy el Consumidor %d y estoy en zonaCritica %d y el dato es: %d\n", i , i+1, Memoria[0] );
                        sleep(1);
                        //sem_post funcion ya predefinida y desbloquea a mi productor o sea aumenta su valor
                         // 0 -> 1
                        sem_post( pro_z1 );
                        printf("\n");
                        break;
                    }
                    //sem_wait funcion ya predefinida evalua el valor del consumidor
                    // 0 o 1 y decide si lo deja entrar o no
                    else if( sem_wait( consu_z2 ) == 0 ){
                        printf("soy el Consumidor %d y estoy en zonaCritica 2 y el dato es: %d\n", i+1 , Memoria[1] );
                        sleep(1);
                        //sem_post funcion ya predefinida y desbloquea a mi productor o sea aumenta su valor
                         // 0 -> 1
                        sem_post( pro_z2 );
                        printf("\n");
                        break;
                    }
                }
            }

            sem_unlink( name1 );
            sem_close( pro_z1 );
            sem_unlink( name2 );
            sem_close( consu_z1 );
            sem_unlink( name3 );
            sem_close( pro_z2 );
            sem_unlink( name4 );
            sem_close( consu_z2 );
            
            if( ultimo ){
                killMemory( id , Memoria );
                sem_destroy( pro_z1 );
                sem_destroy( consu_z1 );
                sem_destroy( pro_z2 );
                sem_destroy( consu_z2 );
            }

            exit(0);
        }
    }
    return 0;
}

int buildMemory( void ){
    int key,shmid;
    key = ftok("/bin/ls",3);

    //existencia de memoria
    if( ( shmid = shmget( key , sizeof( int ) * 3 , IPC_CREAT|IPC_EXCL|0666) ) == -1 ){
        // obteniendo memoria 
        if( ( shmid = shmget( key , sizeof( int ) * 3 , 0 ) ) == -1 ){
            perror("shmget \n");
            exit(1);
        }
        else
            printf("\n");
    }
    else
        printf("Memoria  ID: %d\n",shmid);
    //se enlazan a la memoria compartida
    if( ( Memoria = (int*)shmat( shmid , (int*) 0 , 0 ) ) == (void*)-1 ){
        perror("shmat \n");
        exit(1);
    }
    return shmid; 
}

int killMemory( int id_Memoria , int *buffer ){
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

sem_t * createSem( char *name , int val){
    sem_t *mut;
    if( ( mut = sem_open( name , O_CREAT | O_EXCL , 0666 , val ) ) == SEM_FAILED ){
        if( ( mut = sem_open( name , 0 ) ) == SEM_FAILED )
            printf("Error al abrir el semaforo\n");
    }
    else{
        //printf(" %s creado: %p\n", name,mut);
        sem_init( mut , 1 , val );
    }

    return mut;
}