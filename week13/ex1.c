#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SZ 30

void ReadEorA(FILE* p, int *q, int* n) {
    char c;
    int temp = 0;
    *n = 0;
    while (1) {
        c = fgetc(p);                 
        if (c == ' ' || c == '\n') {
            q[*n] = temp;
            (*n)++;
            temp = 0;
        }
        else temp = temp * 10 + c - '0';
        if (c == '\n') break;
    }
    c = fgetc(p);
}

void ReadCorR(FILE* p, int q[SZ][SZ], int *m) {
    char c;
    int pos1 = 0, pos2 = 0;
    while (1) {
        int flag = 0, temp = 0;
        pos2 = 0;
        while (1) {
            c = fgetc(p);
            if (c == ' ' || c == '\n' || c == EOF) {
                q[pos1][pos2++] = temp;
                temp = 0;
            }
            else {
                temp = temp * 10 + c - '0';
                flag++;
            }
            if (c == '\n' || c == EOF) break;
        }
        pos1++;
        if (!flag) break;
    }

    *m = pos1 - 1;
    c = fgetc(p);
}

int main() {

    FILE* stream = fopen("input.txt", "r");

    int E[SZ], A[SZ], C[SZ][SZ], R[SZ][SZ], n, m, ans[SZ], solve[SZ], pos = 0;

   for (int i = 0; i < SZ; i++)
       ans[i] = 0;

   ReadEorA(stream, E, &m);
   ReadEorA(stream, A, &m);
   ReadCorR(stream, C, &n);
   ReadCorR(stream, R, &n);

   while (1) {

       int success = 0;

       for (int i = 0; i < n; i++) {
           if (ans[i]) continue;
           int flag = 1;
           for (int j = 0; j < m; j++)
               if (A[j] < R[i][j]) flag = 0;
           if (flag == 1) {
               success = 1;
               for (int j = 0; j < m; j++)
                   A[j] += C[i][j];
               ans[i] = 1;
           }

       }

       if (!success) break;

   }

   
   for (int i = 0; i < n; i++)
       if (!ans[i]) solve[pos++] = i + 1;
   
   if (!pos) printf("No deadlock is detected");
   else {
       printf("Numbers of processes that are deadlocked: ");
       for (int i = 0; i < pos; i++)
           printf("%d ", solve[i]);
   }


}