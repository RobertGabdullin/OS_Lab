#include<stdio.h>

void Swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void bubble_sort(int *a, int sz) {
	for (int i = 0; i < sz; i++)
		for (int j = 0; j < sz - i - 1; j++)
			if (a[j] > a[j + 1]) Swap(a + j, a + j + 1);
}

void print_array(int *a, int sz) {
	for (int i = 0; i < sz; i++)
		printf("%d ", a[i]);
}

int main()
{

	int a[7] = { 5, 2, 9, 0, 2, 3, 1 };

	bubble_sort(a, 7);

	print_array(a, 7);

}
