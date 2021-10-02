#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXN 10

int main(int argc, char** argv) {

	int n; char N[MAXN];
	printf("N = ");

	fgets(N, MAXN, stdin);

	n = atoi(N);

	int* val = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		val[i] = i;
		printf("%d ", val[i]);
	}

	printf("\n");

	free(val);

}

