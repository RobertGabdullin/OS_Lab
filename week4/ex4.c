#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
#include<wait.h>

#define MAXN 1000

void type_prompt(){
        printf("> ");
}

int Exit(char *s){
        return s[0] == 'e' && s[1] == 'x' && s[2] == 'i' && s[3] == 't';
}

void read_command(char *command, char **arg, int *f){
        fgets(command, MAXN, stdin);
	if(Exit(command)) exit(0);
	for(int i = 0;command[i] != '\0';i++){
		if(command[i] == '&'){
			*f = 1;
			command[i] = '\n';
			break;
		}
	}
	int pos = 0, id = 1, pos2 = 0;
	arg[pos] = (char*)malloc(MAXN);
	for(;command[pos] != '-' && command[pos] != '\n';pos++)
		arg[0][pos] = command[pos];
	if(pos && arg[0][pos - 1] == ' ') arg[0][pos - 1] = '\0';
	else arg[0][pos] = '\0';

	while(command[pos] != '\n'){
		int flag = 0;
		arg[id] = (char*)malloc(MAXN);
		if(command[pos] == ' ') pos++;
		for(;command[pos] != ' ' && command[pos] != '\n';pos++){
			arg[id][pos2++] = command[pos];
			flag = 1;
		}
		if(!flag) continue;
		arg[id][pos2] = '\0';
		pos2 = 0;
		id++;
	}
	arg[id] = NULL;

}

int main()
{
        char in[MAXN], *arg[10];
	int status[MAXN], start = 0;
        while(!Exit(in)){
                type_prompt();
		int flag = 0;
		read_command(in, arg, &flag);
                if(fork() == 0){
			int temp = execvp(arg[0], arg);
			if(temp == -1){
				printf("not found\n");
				break;
			}
		}
		else{
			if(flag) continue;
			wait(&status[start]);
			if(WIFEXITED(status[start])){
				start++;
				continue;
			}
		}
        }
	for(int i = 0;;i++)
		if(arg[i] != NULL) free(arg[i]);
		else break;
}
