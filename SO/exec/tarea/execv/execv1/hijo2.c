#include<stdio.h>
#include<unistd.h>

int main(int argc, char* argc2[]){
	
	

	printf("soy el hijo 2 desde execv : %d ",  getpid());
	

	return 0;
}