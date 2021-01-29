#include<stdio.h>
#include <string.h>



struct USB{
    char nombre[10];
    int capacidad;
    char sistArchivo[3];
    float uso;
};

void cambiarnombre(struct USB *m);
void mostrarPropiedades(struct USB m);
void Formatear(struct USB *m);


int main (void){

    //FAT  NTFS

    struct USB usb_uno;
    struct USB usb_dos = {"default", 9*1024, "FAT", 0};
    struct USB usb_tres = {"default", 12*1024, "FAT", 0};

    strcpy(usb_dos.sistArchivo,"FAT");
    strcpy(usb_tres.sistArchivo,"FAT");
    usb_uno.capacidad = 3*1024;
    strcpy(usb_uno.nombre,"default");
    strcpy(usb_uno.sistArchivo,"FAT");
    usb_uno.uso = 0;
    int opcion;


    do{

        printf(" escoge una opcion \n");
        printf("1.- USB -> 3GB\n");
        printf("2.- USB -> 9GB\n");
        printf("3.- USB -> 12GB\n");
        printf("4.- salir\n");
        printf("   : ");
        scanf("%d", &opcion);
        printf("\n");

        if(opcion == 1){
                    int opcionn;

                printf("escoga una opcion");
                printf("\n");
                printf("1.- cambiar nombre a la USB \n");
                printf("2.- mostrar informacion \n");
                printf("3.- Formatear \n");
                printf("4.- volver al menu principal");
                printf(" : ");
                scanf("%i", &opcionn);
                if(opcionn == 1){
                    cambiarnombre(&usb_uno);
                }else if( opcionn == 2){
                    mostrarPropiedades(usb_uno);
                }else if(opcionn == 3){
                    Formatear(&usb_uno);
                }
        }else if(opcion == 2){
                int opcionn;

            printf("escoga una opcion");
                printf("\n");
                printf("1.- cambiar nombre a la USB \n");
                printf("2.- mostrar informacion \n");
                printf("3.- Formatear \n");
                printf("4.- volver al menu principal");
                printf(" : ");
                scanf("%i", &opcionn);
                printf("\n");
                if(opcionn == 1){
                    cambiarnombre(&usb_dos);
                }else if( opcionn == 2){
                    mostrarPropiedades(usb_dos);
                }else if(opcionn == 3){
                    Formatear(&usb_dos);
                }
        }else if(opcion == 3){
                int opcionn;

            printf("escoga una opcion");
                printf("\n");
                printf("1.- cambiar nombre a la USB \n");
                printf("2.- mostrar informacion \n");
                printf("3.- Formatear \n");
                printf("4.- volver al menu principal");
                printf(" : ");
                scanf("%i", &opcionn);
                printf("\n");
                if(opcionn == 1){
                    cambiarnombre(&usb_tres);
                }else if( opcionn == 2){
                    mostrarPropiedades(usb_tres);
                }else if(opcionn == 3){
                    Formatear(&usb_tres);
                }
        }


    }while(opcion == 1 || opcion == 2 || opcion == 3);


    return 0;
}

void Formatear(struct USB *m){
        char opcion;

    scanf("%c", &opcion);
    printf("seguro que quieres cambiar el sistema de archivos? s/n : ");
    scanf("%c", &opcion);

    if(opcion == 's'){
        if(strlen(m->sistArchivo) == 3){
            strcpy(m->sistArchivo, "NTFS");
        }else{
            strcpy(m->sistArchivo, "FAT");
        }
    }
}


void cambiarnombre(struct USB *m){
    char nuevo[15];
    printf("escribe el nombre que desees asignarle: ");
    scanf("%s", &nuevo);
    strcpy(m -> nombre, nuevo);
   // printf("tu nombre nuevo es: %s", m -> nombre);
    printf("cambio de nombre exitoso \n");
    printf("\n");

}

void mostrarPropiedades(struct USB m){
    printf("\n");
    printf("tu nombre actual es: %s", m.nombre);
    printf("\n");
    printf("tu capacidad es: %d MB", m.capacidad);
    printf("\n");
    printf("tu sist. Archivo es: %s", m.sistArchivo);
    printf("\n");
    printf("tu uso total es: %.3f", m.uso);
    printf("\n");
    printf("\n");



}

