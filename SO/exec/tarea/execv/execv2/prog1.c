#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	int pid;	
	//pid = fork();
	
	char *const argv[] = {"prog1", NULL};

	for (int i = 0; i < 2; ++i)
	{
		if(fork() == 0){
			execv("./hijo", argv);
			break;
			
		}
		
	}
	while(1){
		sleep(10);
		printf("\n soy hijo: %d y mi padre es: %d", getpid(), getppid());
	};
	return 0;

}