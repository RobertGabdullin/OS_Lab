#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1000
#define ST 32768
#define BITS 16

struct page {
    int id, prior;
};

int Read(int* a, FILE* p) {
    char c; *a = 0;
    int flag = 0;
    while ((c = fgetc(p)) != EOF) {
        if (c == ' ') break;
        *a = *a * 10 + c - '0';
        flag = 1;
    }
    if (!flag) return 0;
    return 1;
}

int main(int argc, char **argv) {
    
    FILE* stream = fopen("input.txt", "r");

    int n = atoi(argv[1]), hit = 0, miss = 0;
    struct page val[MAXN];

    for (int i = 0; i < n; i++)
        val[i].id = -1, val[i].prior = 0;

    int temp;
    while (Read(&temp, stream)) {
        int flag = 0;
        for (int i = 0; i < n; i++) {
            val[i].prior >>= 1;
            if (val[i].id == temp) {
                flag = 1;
                hit++;
                val[i].prior |= 1 << (BITS - 1);
            }
        }
        
        if (flag) continue;

        miss++;

        int Min = 0;
        for (int i = 1; i < n; i++) {
            if (val[i].prior < val[Min].prior || val[i].id == -1) Min = i;
            if (val[i].id == -1) break;
        }
        val[Min].id = temp;
        val[Min].prior = ST;

    }

    double ratio = (double)hit / miss;

    printf("hit = %d miss = %d ratio = %f", hit, miss, ratio);

}