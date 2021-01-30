#include<stdio.h> 
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(int arg, char* arg2[]){


	int x = atoi(arg2[arg-1]);

	int pid;
	//pid = fork();
	int cont = 0;
	
	for (int i = 0; i < 4; ++i)
	{
		cont++;
		if (fork() == 0)
		{
			
			if(cont < 2){

				if (fork()==0){
					break;
				}
			}
			
		}
	}
		
	
	


	while(1){
		sleep(10);
		printf("\n soy un proceso: %d \n", getpid());
		printf("%d", cont);
	};
}	


