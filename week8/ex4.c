#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/resource.h>
#include <sys/time.h>

#define sz 10 * 1024 * 1024

int main(){

        int *p[10];
	struct rusage usage;

        for(int i = 0;i < 10;i++){
                p[i] = (int *)malloc(sz);
                memset(p[i], 0, sz);
		getrusage(RUSAGE_SELF, &usage);
		printf("%ld\n", usage.ru_maxrss);
                sleep(1);
        }

        for(int i = 0;i < 10;i++) free(p[i]);

}

