#include<stdio.h>
#include<unistd.h>

int main(int argc, char* argc2[]){
	
	
	for (int i = 1; i <= 2; ++i)
	{
		printf("soy el hijo %d desde execv : %d \n",i,  getpid());

	}
	

	return 0;
}