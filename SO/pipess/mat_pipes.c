#include<stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include<time.h>
#include<sys/wait.h>



int main(){


    int fd[2];
    char buf[20];
    int buf2[5];
    pipe(fd);
    int mostrar_numero_p[15];
    int solucion[50];
    int aumentar = 0;
    int arr_aux[1];
    int num;


    int filas, columnas, filasB, columnasB, procesos;
    int espera;
    printf("dame valor de la filas matriz A: ");
    scanf("%d", &filas);
    printf("\n dame valor de las columnas matriz A: ");
    scanf("%d", &columnas);

    printf("dame valor de la filas matriz B: ");
    scanf("%d", &filasB);
    printf("\n dame valor de las columnas matriz B: ");
    scanf("%d", &columnasB);

    printf("dame valor de los procesos a utilizar: ");
    scanf("%d", &procesos);

    if(columnas == filasB && filas >= procesos){
        srand(time(NULL));
        int matriz[filas] [columnas];
        int matrizB[filasB][columnasB];
        int filasC , columnasC;
        if (filas > filasB)
        {
             filasC = filas;
        }else{
             filasC = filasB;
        }
        if (columnas > columnasB)
        {
             columnasC = columnas;
        }else{
             columnasC = columnasB;
        }
        printf("filas %d, columnas %d\n", filasC, columnasC);
        int matrizC[filasC][columnasC];



        for(int i = 0; i< filas; i++){
            for(int j = 0; j < columnas; j++){
                matriz[i][j] = rand()%5;
                printf("%d ", matriz[i][j]);
            }
            printf("\n");
        }
        printf("\n");

        for(int i = 0; i< filasB; i++){
            for(int j = 0; j < columnasB; j++){
                matrizB[i][j] = rand()%5;
                printf("%d ", matrizB[i] [j]);
            }
            printf("\n");
        }


        printf("\n \n");




    
    int division = filas/procesos;
    int residuo = filas%procesos;
    int process = 0;
    
    //print("%d y %d\n", division, residuo);
    while(process < filas ){
        if(residuo != 0){
            printf("%d a %d\n",process, process+ division);
            
            int pid = fork();
            if(pid == 0){
                for(int i = process; i<= process+division; i++){
                    printf("\nHOLA SI PUEDO\n ademas soy el proceso: %d \n", i);
                }
               int aux = 0;
                //printf("lo estoy haciendo desde el proceso hijo mi pid es %d\n", getpid());
                for(int a = process; a< filas; a++){
                    for(int i = 0; i< filas; i++){
                        int suma = 0;
                        for(int j = 0; j<columnas; j++){
                            suma += matriz[a][j]*matrizB[j][aux];
                        }
                        /*arr_aux[0] = suma;
                        matrizC[a][i] = suma;
                        printf("ando cerca BROO %d\n", suma);
                        close(fd[0]);
                        write(fd[1], arr_aux, sizeof(arr_aux));
                        close(fd[1]);*/
                        aux++;
                    }

                    aux=0;
                    
                }

                for(int i = 0; i< filasC; i++){
                    for(int j = 0; j < columnasC; j++){
                        printf("%d ", matrizC[i][j]);

                    }
                    printf("\n");
                }
                
            }else{
                printf("soy el padre : %d \n", getpid());
                close(fd[1]);
                num = read(fd[0], mostrar_numero_p, sizeof(mostrar_numero_p));
                close(fd[1]);
                printf(" el numero es %d\n", mostrar_numero_p[0]);
                break;
            }
            process += division+ 1;
            residuo --;
            
        }else{
            int pid2 = fork();
            printf("%d a %d\n",process, process+ division-1);
            
            if(pid2 == 0){
                int aux = 0;
                printf("lo estoy haciendo desde el proceso hijo mi pid es %d\n", getpid());
                for(int a = process; a< filas; a++){
                    for(int i = 0; i< filas; i++){
                        int suma = 0;
                        for(int j = 0; j<columnas; j++){
                            suma += matriz[a][j]*matrizB[j][aux];
                        }
                        printf("es mi numero %d , ",suma );
                        solucion[aumentar] = suma;
                        
                        matrizC[a][i] = suma;
                        aumentar = aumentar +1; 
                        aux++;
                    }
                    //arr_aux[0] = suma;
                    
                    aux=0;
                    break;
                }
                for (int i = 0; i < 15; ++i){
                    printf(" desde anteSSSSSSS %d\n",solucion[i] );
                }
                
                printf("ando cerca x2 \n");
                close(fd[0]);
                write(fd[1], solucion, sizeof(solucion));
                close(fd[1]);  

                /*for(int i = 0; i< filasC; i++){
                    for(int j = 0; j < columnasC; j++){
                        printf(" que es esto%d ", matrizC[i][j]);

                     }
                    printf("\n");
                }*/

            }else{
               /* int contadorPadre = 0;
                if(contadorPadre > 1){
                    break;

                }else{
                    printf("YOSOY EL PADREEEEEEE mi id es %d", getpid());
                    break;
                }*/

               /* wait(NULL);
                printf("YOSOY EL PADREEEEEEE mi id es %d", getpid());
                close(fd[1]);
                num = read(fd[0], mostrar_numero_p, sizeof(mostrar_numero_p));
                
                /*for (int i = 0; i < sizeof(mostrar_numero_p)/sizeof(mostrar_numero_p[0]); i++)
                {
                    printf(" estos son mis resultados%d\n", mostrar_numero_p[i]);
                }
                for (int i = 0; i < 10; i++)
                {
                   printf(" el padre %d lee %d numero es PORDOS%d\n",getpid(), num, mostrar_numero_p[i]);
                }
                close(fd[0]);*/
               
                break;
               
                
            }
            process += division;
        }
    }
    

    //MULTIPLICACION
    
   /* int aux = 0;

    for(int a = 0; a< filas; a++){
        for(int i = 0; i< filas; i++){
            int suma = 0;
            for(int j = 0; j<columnas; j++){
                suma += matriz[a][j]*matrizB[j][aux];
            }
            matrizC[a][i] = suma;
            //printf("%d\n", suma);
            aux++;
        }
        aux=0;
     }*/

     
    printf("\nesta es mi matriz resultante\n");
    for(int i = 0; i< filasC; i++){
            for(int j = 0; j < columnasC; j++){
                printf("%d ", matrizC[i][j]);

            }
            printf("\n");
    }    
    wait(NULL);
    printf("YOSOY EL PADREEEEEEE mi id es %d", getpid());
    close(fd[1]);
    num = read(fd[0], mostrar_numero_p, sizeof(mostrar_numero_p));
                
                /*for (int i = 0; i < sizeof(mostrar_numero_p)/sizeof(mostrar_numero_p[0]); i++)
                {
                    printf(" estos son mis resultados%d\n", mostrar_numero_p[i]);
                }*/
    for (int i = 0; i < 10; i++){
        printf(" el padre %d lee %d numero es PORDOS%d\n",getpid(), num, mostrar_numero_p[i]);
    }
    close(fd[0]);

    for (int i = 0; i < 15; ++i)
    {
        printf(" cfytugyhl %d\n",solucion[i] );
    }


    while(1){

        printf("\nyo soy el proceso%d",getpid() );
        sleep(10);
    }
        
    }else{
        printf("ERROR \n#filasA == #columnasB o procesos revasan al #filas de la matriz A");
    }


    return 0;
}

