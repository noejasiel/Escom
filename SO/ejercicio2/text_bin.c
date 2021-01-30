#include<stdio.h> 
#include<string.h> 
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int* ascii(char* cadena, int num_elemetos); 
int* binario(int *n, int num_elemetos);
char* convertir(int *bufer,char* buf, int cont);

int main(){

    int fd[2];
    int buf[2000];
    pipe(fd);
    int num;
    //int num_elemetos;

    int pid = fork();
    if (pid == 0){

    FILE *flujo = fopen("prueba.txt", "rb");
    if(flujo == NULL){
        printf("f bro error 33");
        return 1;
    }

    fseek(flujo, 0, SEEK_END); //se movera al final de elementos
    int num_elemetos = ftell(flujo);
    rewind(flujo); // se ira otra vez al inicio de mi archivo

    char* cadena = (char *) calloc(sizeof(char), num_elemetos);
    if(cadena == NULL){
        perror("error en la me,memoria");
        return 2;
    }

    //guardar
    int num_elemetos_leidos = fread(cadena, sizeof(char),num_elemetos, flujo);
    if(num_elemetos_leidos != num_elemetos){
        perror("error al leer memoria");
        return 3;
    }
    int* arr  = (int*) calloc(sizeof(int), num_elemetos + 1);
    //int arr[num_elemetos];
    if(arr == NULL){
        perror("error en la me,memoria");
        return 2;
    }
    arr = ascii(cadena, num_elemetos);
    
    
    /*int* bin  = (int*) calloc(sizeof(int), num_elemetos);
    bin = binario(arr, num_elemetos);
     for (int i = 0; i < num_elemetos; ++i)
    {
       // printf("%d j", bin[i]);
    }*/

       // printf("\n el resultado es %ld, y contenido es: %d\n",sizeof(arr), *arr );

    for (int i = 0; i <= num_elemetos; ++i){
        if(num_elemetos - i == 1){
            arr[i + 1] = -1;
        }
       // printf("%d aq ", arr[i]);

    }

        close(fd[0]);
        write(fd[1], arr, sizeof(arr)*num_elemetos);
        close(fd[1]);
        wait(NULL);
        free(cadena);
        fclose(flujo);

            
    }else{
        int cont = 0;

        FILE* copia = fopen("copia.txt", "r+");
        close(fd[1]);
        //int* bufer_p = (int*)malloc(sizeof(int),)
        num = read(fd[0], buf, sizeof(buf));

        //printf("%li\n",sizeof(buf) );
        for(int i = 0; i< 300; i++){
            if(buf[i] == -1){
               break; 
            }
            cont++;
        }
        char* bufer_p = (char*)calloc(sizeof(char),cont);
        /*for(int i = 0; i< cont; i++){
            bufer_p[i] = (char)buf[i];
          //  printf("%d ", bufer_p[i]);
        }*/
        bufer_p = convertir(buf,bufer_p, cont);
        //printf("%d ", cont);
        close(fd[0]);
        printf("\nexito\n");
        fputs(bufer_p, copia);
        free(bufer_p);
        fflush(copia);
        fclose(copia);

    }
    
    return 0;
}


char* convertir(int *bufer,char* bufer_p, int cont){
   
    for(int i = 0; i< cont; i++){
        bufer_p[i] = (char)bufer[i];
        //printf("%d ", bufer_p[i]);
    }
    return bufer_p;
}



int* ascii(char* cadena, int num_elemetos){
   // printf("%s",cadena );
    int* copia = (int*) calloc(sizeof(int), num_elemetos);
    if(copia == NULL){
        perror("error en la me,memoria");
        exit(2);
    }
    //printf("%d\n",num_elemetos );
    //obtener codigo ascii
    int num = 0;
    for (int i = 0; i < num_elemetos; i++)
    {
        copia[i] = (int)cadena[i];
       // printf(" %d", copia[i]);
        
    }
    //printf("ojo %ls", copia);
    return copia;
    free(copia);
}

int* binario(int *num,int num_elemetos){
    int* reves  = (int*) calloc(sizeof(int), num_elemetos);
    int l = 0;
    for (int i = num_elemetos; i >=0; i--){
      
        //printf("%d  ",num[i]);
        reves[l] = num[i];
        l++;

    }
    for(int i = 0; i <= num_elemetos; i++){
       // printf("%d p",reves[i] );
    }

    int aux2 = num_elemetos;
    int bin[999];
    int aux[aux2];
    int i;
    
    
    for(int j =0;j<num_elemetos;j++){
        
        while (reves[j] != 0) {
            bin[i] = reves[j] % 2;
            reves[j] = reves[j] / 2;
            i++;
        }
        aux[j]= i-1;
    }
    
   // printf("\n%d esta es i i", i);
    //i es el controlador se guarda en un arreglo
    
    //printf("\n%d esta es i i", i);
    //printf("Binario: ");   
    
    for(int i =0; i < aux2; i++){
    //    printf("%d<--- ", aux[i]-1);
    }
    
     while (i>=0)
    {
   //       printf("%i",bin[i]);
          i--;
    }
    return reves;
}
    
