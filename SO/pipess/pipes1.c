#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(){

	int fd[2];
	int pd;
	int arr[3] = {1, 2, 3};
	char buf[20];
	int buf2[5];
	int num;
	int hola;
	pipe(fd);
	pd = fork();


	/*if(pd == 0){
		printf("hola es una prueba\n");
		//hijo
		close(fd[0]);
		write(fd[1], arr, sizeof(arr));
		close(fd[1]);
	}else if(pd >0) {
		printf("hola es una prueba3\n");
		close(fd[1]);
		num = read(fd[0], buf2, sizeof(buf2));
		for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++ ){
			printf("\n padre lee bit %d bytes: %d",num, buf2[i]);

		}
		close(fd[0]);
		printf("hola es una prueba4\n");
		wait(&hola);
	}*/

	if(pd > 0){
		 close(fd[1]);
		 num = read(fd[0], buf2, sizeof(buf2));
		 close(fd[0]);
		 for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++ ){
			printf("\n padre lee bit %d bytes: %d",num, buf2[i]);

		}
	}else{
		close(fd[0]);
		write(fd[1], arr, sizeof(arr));
		close(fd[1]);
	}

	return 0;	

}
