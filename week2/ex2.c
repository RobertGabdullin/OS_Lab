#include <stdio.h>
#include <string.h>
#define MAXN 10000

int main(void) {
	
	char s[MAXN]; s[0] = 0;
	gets(s);
	
	for (int i = strlen(s) - 1; i >= 0; i--)
		printf("%c", s[i]);
	
}