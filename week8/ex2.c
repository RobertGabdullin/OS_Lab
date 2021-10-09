#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define sz 10 * 1024 * 1024

int main(){

	int *p[10];

	for(int i = 0;i < 10;i++){
		p[i] = (int *)malloc(sz);
		memset(p[i], 0, sz);
		sleep(1);
	}

	for(int i = 0;i < 10;i++) free(p[i]);

}
