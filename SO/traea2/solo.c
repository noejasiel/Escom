#include<stdio.h> 
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>


int main(int arg, char* arg2[]){


	int x = atoi(arg2[arg-1]);

	int pid;
	pid = fork();

	for (int i = 0; i < x; ++i){
		if (pid == 0){
			if (fork() == 0)
			{
				break;
			}
		}else{
			printf("soy proceso padre %d", getpid());
		}
	}
	


	while(1){
		sleep(10);
		printf("\n soy un proceso: %d ", getpid());
	};
}