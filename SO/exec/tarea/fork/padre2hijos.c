#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	int pid;	
	//pid = fork();
	
	

	for (int i = 0; i < 1; ++i)
	{
		if(fork() == 0){
			if(i == 0){
				if(fork() == 0){
					break;
				}
			}else{
				break;
			}
			
			break;
		}
		
	}
	while(1){
		sleep(10);
		printf("\n soy hijo: %d y mi padre es: %d", getpid(), getppid());
	};


}