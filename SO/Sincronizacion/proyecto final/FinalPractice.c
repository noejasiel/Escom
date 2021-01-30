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
#define RANGE 10000
#define NoPRODUCERS 5
#define NoCONSUMERS 3

int *Memory;

int getSharedBlock();
int * attachMemoryBlock();
int detachMemoryBlock(int *);
int destroyMemoryBlock();

sem_t * mkSemaphore (char *, int); //Función inicializadora de semaforos
void clsSemaphore(char *, sem_t *); //Funcion removedora de semaforos

void saveProducts(sem_t *, int, int, int, FILE *); //Funcion que graba la producción en un archivo

int main()
{
    sem_t *ProdZone1, *ConsZone1, *ProdZone2, *ConsZone2; //Semaforos
    sem_t *ProdZone3, *ConsZone3, *ProdZone4, *ConsZone4; //Semaforos
    sem_t *Count; // Semaforo Contador
    sem_t *File; //Semafoto Archivo
    pid_t pid; //Id de procesos
    char *nameProd1, *nameCons1, *nameProd2, *nameCons2;  //Nombre de Semaforos
    char *nameProd3, *nameCons3, *nameProd4, *nameCons4;  //Nombre de Semaforos
    char *nameCount; //Semaforo Contador
    char *nameFile;  //Semaforo Archivo
    int flagZone1, flagZone2, flagZone3, flagZone4; //Estatus de los semaforos
    int a; //Manipulación de los argumentos
    int x, y; //Control de Loop
    int last; //BAndera para ultimo dato
    int p; //Produccion
    FILE *doc; //Apuntador a Archivo
    
    destroyMemoryBlock(Memory);
    
    //Inicialización de Variables
    nameCons1 = "ConsZone1";
    nameProd1 = "ProdZone1";
    nameCons2 = "ConsZone2";
    nameProd2 = "ProdZone2";
    nameCons3 = "ConsZone3";
    nameProd3 = "ProdZone3";
    nameCons4 = "ConsZone4";
    nameProd4 = "ProdZone4";
    nameCount = "Account";
    nameFile  = "File";
    
    //Inicialización de Semaforos
    ConsZone1 = mkSemaphore(nameCons1, 0);
    ProdZone1 = mkSemaphore(nameProd1, 1);
    ConsZone2 = mkSemaphore(nameCons2, 0);
    ProdZone2 = mkSemaphore(nameProd2, 1);
    ConsZone3 = mkSemaphore(nameCons3, 0);
    ProdZone3 = mkSemaphore(nameProd3, 1);
    ConsZone4 = mkSemaphore(nameCons4, 0);
    ProdZone4 = mkSemaphore(nameProd4, 1);
    Count     = mkSemaphore(nameCount, 1);
    File      = mkSemaphore(nameFile, 1);
    
    //Toma el bloque de memoria compartida
    Memory = attachMemoryBlock();
    if(Memory == NULL)
    {
        printf("ERROR: couldn't get block\n");
        return -1;
    }
    
    //Zona de Productores
    for(x = 0; x < NoPRODUCERS; x++)
    {
        pid = fork();
        
        if(pid == -1)
            perror("ERROR: couldn't get child process\n");
        else if(pid == 0)
        {
            //Toma el bloque de memoria compartida
            Memory = attachMemoryBlock();
            if(Memory == NULL)
            {
            printf("ERROR: couldn't get block\n");
            return -1;
            }
            
            //Inicia ciclo de producción
            for(y = 0; y < RANGE; y++)
            {
                while(1)
                {
                    //Zona Critica 1
                    sem_getvalue(ProdZone1, &flagZone1);
                    if(flagZone1 == 1)
                    {
                        sem_wait(ProdZone1);
                        Memory[0] = (x+1) * 111;
                        printf("Prod No %d Prods %d Zona 1\n", x+1, Memory[0]);
                        sem_post(ConsZone1);
                        break;
                    }
                    //Zona Critica 2
                    sem_getvalue(ProdZone2, &flagZone2);
                    if(flagZone2 == 1)
                    {
                        sem_wait(ProdZone2);
                        Memory[1] = (x+1) * 111;
                        printf("Prod No %d Prods %d Zona 2\n", x+1, Memory[1]);
                        sem_post(ConsZone2);
                        break;
                    }
                    //Zona Critica 3
                    sem_getvalue(ProdZone3, &flagZone3);
                    if(flagZone3 == 1)
                    {
                        sem_wait(ProdZone3);
                        Memory[2] = (x+1) * 111;
                        printf("Prod No %d Prods %d Zona 3\n", x+1, Memory[2]);
                        sem_post(ConsZone3);
                        break;
                    }
                    //Zona Critica 4
                    sem_getvalue(ProdZone4, &flagZone4);
                    if(flagZone4 == 1)
                    {
                        sem_wait(ProdZone4);
                        Memory[3] = (x+1) * 111;
                        printf("Prod No %d Prods %d Zona 4\n", x+1, Memory[3]);
                        sem_post(ConsZone4);
                        break;
                    }
                }
            }
            clsSemaphore(nameCons1, ConsZone1);
            clsSemaphore(nameProd1, ProdZone1);
            clsSemaphore(nameCons2, ConsZone2);
            clsSemaphore(nameProd2, ProdZone2);
            clsSemaphore(nameCons3, ConsZone3);
            clsSemaphore(nameProd3, ProdZone3);
            clsSemaphore(nameCons4, ConsZone4);
            clsSemaphore(nameProd4, ProdZone4);
            
            detachMemoryBlock(Memory);
            
            exit(0);
        }
    }
    
    //Zona de Consumo
    for(x = 0; x < NoCONSUMERS; x++)
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
                if(Memory[4] < RANGE * NoPRODUCERS)
                {
                    //Verifica si estamos en el ultimo elemento
                    if(Memory[4] == ((RANGE * NoPRODUCERS)-1))
                        last = 1;
                    Memory[4]++;
                    printf("%d\n", Memory[4]);
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
                    sem_getvalue(ConsZone1, &flagZone1);
                    if(flagZone1 == 1)
                    {
                        sem_wait(ConsZone1);
                        printf("Cons No %d Conss %d Zona 1\n", x+1, Memory[0]);
                        saveProducts(File, Memory[0], x+1, Memory[4], doc);
                        sem_post(ProdZone1);
                        break;
                    }
                    //Zona Critica 2
                    sem_getvalue(ConsZone2, &flagZone2);
                    if(flagZone2 == 1)
                    {
                        sem_wait(ConsZone2);
                        printf("Cons No %d Conss %d Zona 2\n", x+1, Memory[1]);
                        saveProducts(File, Memory[1], x+1, Memory[4], doc);
                        sem_post(ProdZone2);
                        break;
                    }
                    //Zona Critica 3
                    sem_getvalue(ConsZone3, &flagZone3);
                    if(flagZone3 == 1)
                    {
                        sem_wait(ConsZone3);
                        printf("Cons No %d Conss %d Zona 3\n", x+1, Memory[2]);
                        saveProducts(File, Memory[2], x+1, Memory[4], doc);
                        sem_post(ProdZone3);
                        break;
                    }
                    //Zona Critica 4
                    sem_getvalue(ConsZone4, &flagZone4);
                    if(flagZone4 == 1)
                    {
                        sem_wait(ConsZone4);
                        printf("Cons No %d Conss %d Zona 4\n", x+1, Memory[3]);
                        saveProducts(File, Memory[3], x+1, Memory[4], doc);
                        sem_post(ProdZone4);
                        break;
                    }
                }
            }

            sem_unlink(nameCons1);
            sem_close(ConsZone1);
            sem_unlink(nameProd1);
            sem_close(ProdZone1);
            sem_unlink(nameCons2);
            sem_close(ConsZone2);
            sem_unlink(nameProd2);
            sem_close(ProdZone2);
            sem_unlink(nameCons3);
            sem_close(ConsZone3);
            sem_unlink(nameProd3);
            sem_close(ProdZone3);
            sem_unlink(nameCons4);
            sem_close(ConsZone4);
            sem_unlink(nameProd4);
            sem_close(ProdZone4);
            sem_unlink(nameFile);
            sem_close(File);
            sem_unlink(nameCount);
            sem_close(Count);
            
            detachMemoryBlock(Memory);
            
            if(last)
            {
                sem_destroy(ConsZone1);
                sem_destroy(ProdZone1);
                sem_destroy(ConsZone2);
                sem_destroy(ProdZone2);
                sem_destroy(ConsZone3);
                sem_destroy(ProdZone3);
                sem_destroy(ConsZone4);
                sem_destroy(ProdZone4);
                sem_destroy(Count);
                sem_destroy(File);
                destroyMemoryBlock();
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

int * attachMemoryBlock()
{
    int sharedBlockID = getSharedBlock();
    int *result;
    
    if(sharedBlockID == IPC_RESULT_ERROR)
        return NULL;
    
    //Map the shared block into this process's memory
    // and give a pointer to it
    result = shmat(sharedBlockID, NULL, 0);
    if(result == NULL)
        return NULL;
    
    return result;
}

int detachMemoryBlock(int *block)
{
    return (shmdt(block) != IPC_RESULT_ERROR);
    printf("OK");
}

int destroyMemoryBlock()
{
    int sharedBlockID = getSharedBlock();
    
    if(sharedBlockID == IPC_RESULT_ERROR)
        return IPC_RESULT_ERROR;
    
    return(shmctl(sharedBlockID, IPC_RMID, NULL) != IPC_RESULT_ERROR);
}

sem_t * mkSemaphore (char * name, int init)
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

void saveProducts(sem_t *File, int prod, int cons, int zone, FILE *doc)
{
    sem_wait(File);
    //Apertura de Archivo
    doc = fopen("bck.txt", "a");
    
    if(doc == NULL)
        perror("ERROR: couldn't get the file\n");
    
    fprintf(doc, "%d Consumer->%d Zone->%d\n", prod, cons, zone);
    
    //Clausura de Archivo
    fclose(doc);
    sem_post(File);
}
