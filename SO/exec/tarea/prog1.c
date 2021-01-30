#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>


int main(int arg, char* arg2[]){
	
	int pid;	
	//pid = fork();
	char *const argv[] = {"prog1", "soy", NULL};
	for (int i = 0; i < 1; ++i)
	{
		if(fork() == 0){
			if(i == 0){

				execv("./hijo1", argv);
				continue;
				if(fork() == 0){
					execv("./hijo2", argv);
					
					
				}
				
			}else{
				break;
			}
			break;
		}
		
	}
	while(1){
		sleep(3);
		printf("\n soy hijo: %d y mi padre es: %d", getpid(), getppid());
	};

}