#include <stdio.h>
#include <string.h>
#define MAXN 10000

int main(void) {

	char s[MAXN];
	printf("Enter your string: "); fgets(s, MAXN, stdin);

	printf("Reversed version: ");

	for (int i = strlen(s) - 2; i >= 0; i--)
		printf("%c", s[i]);

}
