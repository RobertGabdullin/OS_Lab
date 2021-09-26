#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXN 10

int n, curTime = 0, AT[MAXN], BT[MAXN], CT[MAXN], TAT[MAXN], WT[MAXN], active[MAXN], maxLen = 3;
double avgWT = 0, avgTAT = 0;

int Max(int a, int b) {
	if (a > b) return a;
	return b;
}

int Len(int a) {
	int ans = 0;
	while (a > 0) {
		ans++;
		a /= 10;
	}
	return Max(1, ans);
}

int read_line(FILE *p) {
	int cur1 = 0, cur2 = 0, *q = &cur1, action = 0; 
	char c;
	while ((c = fgetc(p)) != EOF) {
		if (c == '\n') break;
		if (c == ' ') continue;
		if (c == ',') {
			q = &cur2;
			continue;
		}
		*q = *q * 10 + c - '0';
		action = 1;
	}

	if (action) {
		AT[n] = cur1;
		BT[n] = cur2;
		maxLen = Max(maxLen, Len(cur1));
		maxLen = Max(maxLen, Len(cur2));
		n++;
		return 1;
	}

	return 0;

}

void space(int a) {
	for (int i = 0; i < a; i++)
		printf(" ");
}

void out(int a) {
	printf("%d", a);
	space(maxLen - Len(a) + 2);
}

void Swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void Start() {
	printf("P#   AT");
	space(maxLen);
	printf("BT");
	space(maxLen);
	printf("CT");
	space(maxLen);
	printf("TAT");
	space(maxLen - 1);
	printf("WT\n\n");
}

int Next() {
	int Min = -1;
	for (int i = 0; i < n; i++) {
		if (active[i] && (Min == -1 || (AT[Min] > AT[i]) || (AT[Min] == AT[i] && BT[i] < BT[Min]))) 
			Min = i;
	}
	return Min;
}

void Choose(int pos) {

	active[pos] = 0;
	curTime = Max(curTime, AT[pos]) + BT[pos];
	CT[pos] = curTime;
	TAT[pos] = CT[pos] - AT[pos];
	WT[pos] = TAT[pos] - BT[pos];
	avgWT += WT[pos];
	avgTAT += TAT[pos];

}

int main()
{
   
	FILE* stream = fopen("input.csv", "r");
	
	while (read_line(stream));

	for (int i = 0; i < n; i++)
		active[i] = 1;

	Start();

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (BT[i] > BT[j]) {
				Swap(&AT[i], &AT[j]);
				Swap(&BT[i], &BT[j]);
			}

	for (int i = 0; i < n; i++) {
		int flag = 0;
		for (int j = 0; j < n; j++) {
			if (active[j] && AT[j] <= curTime) {
				flag = 1;
				Choose(j);
				break;
			}
		}
		if (!flag) Choose(Next());
	}

	avgWT /= n;
	avgTAT /= n;

	for (int i = 0; i < n; i++) {
		printf("P%d", i);
		space(4 - Len(i));
		out(AT[i]);
		out(BT[i]);
		out(CT[i]);
		out(TAT[i]);
		out(WT[i]);
		printf("\n");
	}

	printf("Average Turnaround Time = %f\n", avgTAT);
	printf("Average WT = %f\n", avgWT);

}
