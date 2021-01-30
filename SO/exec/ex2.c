#include<stdio.h>
#include<unistd.h>

int main(int argc, char* arg2[]){

	char*  argv2[] = {"lol", NULL};

	printf("soy %s y mi id es %d \n", arg2[0], getpid());

	execv("./c", argv2);

	printf("error \n");

	return -1;

}

//ex2.c => c2 && ex.c => c y se ejecuta c2

//en estre programa se ejecutara execv y cuando llegue a esa linea se va a ejecutar
//el proceso que le enviemos en este caso ./c y se ejecutara este tienen como ejecutable
//llamado ./c2
