#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void) {
	int a = INT_MAX;
	float f = FLT_MAX;
	double d = DBL_MAX;
	printf("int value: %d\nint size: %d\n", a, sizeof(a));
	printf("float value: %f\nfloat size: %d\n", f, sizeof(f));
	printf("double value: %f\ndouble size: %d\n", d, sizeof(d));
}