#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>

#define MAXN 1000

void type_prompt(){
	printf("> ");
}

void read_command(char *command){
	fgets(command, MAXN, stdin);
}

int Exit(char *s){
	return s[0] == 'e' && s[1] == 'x' && s[2] == 'i' && s[3] == 't';
}

int main()
{
	char in[MAXN];
	while(!Exit(in)){
		type_prompt();
		read_command(in);
		system(in);
	}
}

