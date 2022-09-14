#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define SIZEF 101
#define SIZEO 10001

int memo[SIZEF][SIZEO] = { 0 };

int distinctSubsequence(char oWord[], char fWord[]) {
	int oLength = strlen(oWord), fLength=strlen(fWord);
	for (int i = 1; i < fLength+1; i++) {
		for (int j = 1; j < oLength+1; j++) {
			if (oWord[j - 1] == fWord[i - 1] && i == 1)
				memo[i][j]++;
			else if (oWord[j - 1] == fWord[i - 1])
				memo[i][j] = memo[i - 1][j] + memo[i][j - 1];
			else
				memo[i][j] = memo[i][j - 1];
		}
	}
	for (int i = 1; i < fLength + 1; i++) {
		for (int j = 1; j < oLength + 1; j++) {
			printf("%d", memo[i][j]);
		}
		printf("\n");
	}
	return memo[fLength][oLength];
}

void main() {
	int n;
	printf("input number of test cases : ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char originalWord[SIZEO], findWord[SIZEF];
		printf("Input original word : ");
		scanf("%s", originalWord);
		printf("Input find word : ");
		scanf("%s", findWord);
		printf("find word in original word : %d\n", distinctSubsequence(originalWord, findWord));
	}
}