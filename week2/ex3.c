#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {

	int n;
	char s[11];
	fgets(s, 11, stdin);

	n = atoi(s);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n + i; j++)
			if (j >= n - i - 1) printf("*");
			else printf(" ");
		printf("\n");
	}

}
