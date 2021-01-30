#include<stdio.h>
#include<unistd.h>

int main(int argc, char* argc2[]){
	printf("soy %s y mi id es %d \n", argc2[0], getpid());

	for (int i = 0; i < argc; ++i)
	{
		printf("argumento %d es %s\n", i , argc2[i]);
	}

	return 0;
}