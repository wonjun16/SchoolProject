#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void createWorkSort(int work[][2], float workSort[][2], int workNum) {
	for (int i = 1; i < workNum + 1; i++) {
		workSort[i][0] = (float)work[i][0] / work[i][1];
		workSort[i][1] = i;
	}
}

void sort(float workSort[][2],int work[][2], int workNum) {
	for (int i = 1; i < workNum; i++) {
		float tempValue = workSort[i][0];
		int tempIndex = workSort[i][1];
		for (int j = i + 1; j < workNum + 1; j++) {
			if (tempValue > workSort[j][0]) {
				tempValue = workSort[j][0];
				tempIndex = workSort[j][1];
			}
			else if (tempValue == workSort[j][0] && work[tempIndex][0] > work[j][0]) {
				tempValue = workSort[j][0];
				tempIndex = workSort[j][1];
			}
		}
		workSort[(int)workSort[tempIndex][1]][0] = workSort[i][0];
		workSort[(int)workSort[tempIndex][1]][1] = workSort[i][1];
		workSort[i][0] = tempValue;
		workSort[i][1] = tempIndex;
	}
}

void main() {
	int testCase;
	char space;
	scanf("%d", &testCase);
	for (int i = 0; i < testCase; i++) {
		int workNum;
		int work[1001][2];
		float workSort[1001][2];
		scanf("%c", &space);
		scanf("%d", &workNum);
		for (int j = 1; j < workNum+1; j++)
			scanf("%d %d", &work[j][0], &work[j][1]);
		createWorkSort(work, workSort, workNum);
		sort(workSort, work, workNum);
		printf("\n");
		for (int j = 1; j < workNum + 1; j++)
			printf("%d ", (int)workSort[j][1]);
		printf("\n");
	}
}