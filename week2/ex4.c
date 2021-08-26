#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int main(void) {

	int a, b;
	char s1[11], s2[11];

	printf("Enter the first number: "); fgets(s1, 11, stdin);
	printf("Enter the second number: "); fgets(s2, 11, stdin);

	a = atoi(s1), b = atoi(s2);

	Swap(&a, &b);

	printf("Now the first number equals to %d and the second equals to %d", a, b);

}
