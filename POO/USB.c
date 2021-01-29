#include<stdio.h>


struct USB{
    char nombre[10];
    int capacidad;
    char sistArchivo[3];
    float uso;
};



int main (void){

    char cadena[4] = 'hola';

    printf("hola %s", &cadena);


    return 0;
}


