#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {

	int n = atoi(argv[1]);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n + i; j++)
			if (j >= n - i - 1) printf("*");
			else printf(" ");
		printf("\n");
	}

}
