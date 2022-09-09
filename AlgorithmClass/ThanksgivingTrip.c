#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int findAvg(int price[], int n) {
	int all = 0, avg, remainder;
	for (int i = 0; i < n; i++)
		all += price[i];
	avg = all / n;
	if ((remainder = avg % 10) >= 5)
		avg += 10 - remainder;
	else
		avg -= remainder;
	return avg;
}

void subtractValue(int sub[], int price[], int avg, int n) {
	for (int i = 0; i < n; i++)
		sub[i] = abs(price[i] - avg);
}

void sortSub(int sub[], int n) {
	int min, temp;
	for (int i = 0; i < n; i++) {
		min = i;
		for (int j = i; j < n; j++) {
			if (sub[min] > sub[j])
				min = j;
		}
		temp = sub[min];
		sub[min] = sub[i];
		sub[i] = temp;
	}
}

void findOutput(int output[],int sub[], int count, int n) {
	if (n % 2) {
		for (int i = 0; i < n / 2 + 1; i++)
			output[count] += sub[i];
	}
	else {
		for (int i = 0; i < n / 2 ; i++)
			output[count] += sub[i];
	}
}

void showOutput(int count, int output[]) {
	for (int i = 0; i < count; i++)
		printf("%d\n", output[i]);
}

void main() {
	int n, price[100], output[100] = { 0 }, subtract[100], count = 0, avg;
	do {
		printf("Input : ");
		scanf("%d", &n);
		if (n) {
			for (int i = 0; i < n; i++)
				scanf("%d", &price[i]);
			avg = findAvg(price, n);
			subtractValue(subtract, price, avg, n);
			sortSub(subtract, n);
			findOutput(output, subtract, count, n);
			count++;
		}
	} while (n);
	showOutput(count, output);
}