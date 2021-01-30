#include<stdio.h> 
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(int arg, char* arg2[]){


	int x = atoi(arg2[arg-1]);

	
	for (int i = 0; i < 2; ++i){
		int pid = fork();
		if (pid == 0){
			break;
			
		}else{
			continue;
		}
	}
	


	while(1){
		sleep(10);
		printf("\n soy un proceso: %d ", getpid());
	};
}