#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define MAXN 3

pthread_t id_thread[MAXN];

void * PrintHello(void * num){
	printf("Hello from thread %d\n",*(int *)num);
	printf("Terminating of thread %d\n", *(int *)num);
	pthread_exit(NULL);
}

int main(){

	for(int i = 0;i < MAXN;i++){
		printf("Creating thread %d\n", i);
		if(pthread_create(&id_thread[i], NULL, &PrintHello, &i) != 0){
			printf("Failed to create thread\n");
		}
	}
	pthread_exit(NULL);
}
