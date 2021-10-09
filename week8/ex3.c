#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define sz 10 * 1024 * 1024

int main(){

        int *p[10];

        for(int i = 0;i < 10;i++){
                p[i] = (int *)malloc(sz); // Each call to malloc increments the VIRT (virtual memory used)
					  // and RES (RAM used) values, after which the memory will be freed, 
					  // the process will terminate and no longer display.
                memset(p[i], 0, sz);
                sleep(1);
        }

        for(int i = 0;i < 10;i++) free(p[i]);

}
