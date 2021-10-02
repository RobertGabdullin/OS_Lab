#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void *Realloc(void *ptr, size_t size){
	if(ptr == NULL && !size) return NULL;
	if(ptr == NULL) malloc(size);
	if(!size){
		free(ptr);
		return NULL;
	}
	void * ans = memcpy(malloc(size), ptr, size);
	return ans;
}

int main(){

 printf("Enter original array size:");
        int n1=0;
        scanf("%d",&n1);

        //Create a new array of n1 ints
        int* a1 = (int*)malloc(n1 * sizeof(int));
        int i;
        for(i=0; i<n1; i++){
                a1[i] = 100;
                printf("%d ", a1[i]);
        }

        printf("\nEnter new array size: ");
        int n2=0;
        scanf("%d",&n2);

        a1 = (int *)Realloc(a1, n2 * sizeof(int));

        for (int i = n1; i < n2; i++)
                a1[i] = 0;

        for(i=0; i<n2;i++){
                printf("%d ", a1[i]);
        }
        printf("\n");

       if(a1 != NULL) free(a1);

}
