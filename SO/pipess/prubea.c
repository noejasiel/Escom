#include<stdio.h>
#include <stdlib.h>
#include<unistd.h>

int main(){

	int np ;
	int nf ;
	scanf("%d", &np);
	scanf("%d", &nf);
	int division = nf/np;
	int residuo = nf%np;
	int process = 0;
	
	printf("%d y %d\n", division, residuo);
	while(process < nf ){
		if(residuo != 0){
			printf("%d a %d\n",process, process+ division);
			
			int pid = fork();
			if(pid == 0){
				for(int i = process; i<= process+division; i++){
					printf("\nHOLA SI PUEDO\n ademas soy el proceso: %d \n", i);
				}
			}else{
				break;
			}
			process += division+ 1;
			residuo --;
			
		}else{
			int pid2 = fork();
			printf("%d a %d\n",process, process+ division-1);
			
			if(pid2 == 0){
				for(int i = process; i<= process+division-1; i++){
					printf("\n HOLA HOLA SI PUEDO\n ademas soy el proceso: %d \n", i);
				}
			}else{
				break;
			}
			process += division;
		}
	}
	
	while(1){

		printf("\nyo soy el proceso%d",getpid() );
		sleep(10);
	}




	return 0;
}