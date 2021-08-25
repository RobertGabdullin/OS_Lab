#include <stdio.h>

void Swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int main(void) {
	
	int a, b;
	scanf_s("%d%d", &a, &b);

	Swap(&a, &b);
	
	printf("%d %d", a, b);

}