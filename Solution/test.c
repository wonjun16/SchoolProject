#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void main() {
	FILE* readFile, *resultFile;
	const char* myFileName = "C:\\test\\score.txt";
	const char* myReFileName = "C:\\test\\resultScore.txt";
	char name[20];
	int score1, score2, score3;

	readFile = fopen(myFileName, "r");
	resultFile = fopen(myReFileName, "w");
	if (readFile == NULL)
		printf("Can't find file\n");
	else {
		while (fscanf(readFile, "%s %d %d %d", name, &score1, &score2, &score3) != EOF) {
			fprintf(resultFile, "%s %d %d %d\n", name, score1, score2, score3);
			fprintf(resultFile, "%s total score : %d\n\n", name, score1 + score2 + score3);
		}
	}

	fclose(readFile);
	fclose(resultFile);
}