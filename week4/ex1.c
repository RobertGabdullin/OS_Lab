#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	int n = 17;

	int temp = fork();
	if (temp) printf("Hello from parent [%d - %d]\n", temp, n);
	else printf("Hello from child [%d - %d]\n", temp, n);
}

