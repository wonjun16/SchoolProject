#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int memo[100][10000];

void distinctSubsequence(char oWord[], char fWord[]) {
	int oLength = strlen(oWord), fLength=strlen(fWord);
	for (int i = 0; i < fLength; i++) {
		for (int j = 0; j < oLength; j++) {

		}
	}
}

void main() {
	int n;
	printf("input number of test cases : ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char originalWord[10000], findWord[100];
		printf("Input original word : ");
		scanf("%s", originalWord);
		printf("Input find word : ");
		scanf("%s", findWord);
	}
}