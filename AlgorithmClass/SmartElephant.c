#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define SIZE 1001

int memo[SIZE][SIZE];
int sortedW[SIZE], sortedS[SIZE];

void sort(int WSI[][3], int count) {
	int tempW, tempS, tempI, index, sortIndex = 1, copy[SIZE][3] = { 0 };
	for (int i = 1; i < count; i++) {
		copy[i][0] = WSI[i][0]; copy[i][1] = WSI[i][1]; copy[i][2] = WSI[i][2];
	}
	for (int i = 1; i < count; i++) { //sort weight for ascending order
		tempW = copy[i][0]; tempS = copy[i][1]; tempI = copy[i][2];
		index = i;
		for (int j = i; j < count; j++) {
			if (copy[j][0] < tempW) {
				tempW = copy[j][0]; tempS = copy[j][1]; tempI = copy[j][2]; index = j;
			}
		}
		copy[index][0] = copy[i][0]; copy[index][1] = copy[i][1]; copy[index][2] = copy[i][2];
		copy[i][0] = tempW; copy[i][1] = tempS; copy[i][2] = tempI;
		sortedW[sortIndex] = tempI;
		sortIndex++;
	}
	sortIndex = 1;
	for (int i = 1; i < count; i++) { //sort smart for descending order
		tempW = copy[i][0]; tempS = copy[i][1]; tempI = copy[i][2];
		index = i;
		for (int j = i; j < count; j++) {
			if (copy[j][1] > tempS) {
				tempW = copy[j][0]; tempS = copy[j][1]; tempI = copy[j][2]; index = j;
			}
		}
		copy[index][0] = copy[i][0]; copy[index][1] = copy[i][1]; copy[index][2] = copy[i][2];
		copy[i][0] = tempW; copy[i][1] = tempS; copy[i][2] = tempI;
		sortedS[sortIndex] = tempI;
		sortIndex++;
	}
}

void LCS(int WSI[][3], int count) { //longest common subsequence algorithm
	for (int i = 1; i < count; i++) {
		for (int j = 1; j < count; j++) {
			if (sortedW[j] == sortedS[i])
				memo[i][j] = memo[i - 1][j - 1] + 1;
			else
				memo[i][j] = memo[i - 1][j] > memo[i][j - 1] ? memo[i - 1][j] : memo[i][j - 1];
		}
	}
}

void result(int count) {
	int num = 0;
	for (int i = 1; i < count; i++) {
		for (int j = 1; j < count; j++) {
			if (memo[i][j] == memo[i - 1][j - 1] +1 && memo[i - 1][j - 1]==num) {
				printf("%d", sortedS[i]);
				num++;
				break;
			}
		}
	}
}

void main() {
	int weightSmartIndex[SIZE][3] = { 0 }, count = 1; // count > index of real input / weightSmartIndex > {weight, smart, index}
	while (weightSmartIndex[count-1][0] != EOF) {
		printf("elephant's size, smart : ");
		scanf("%d %d", &weightSmartIndex[count][0], &weightSmartIndex[count][1]);
		weightSmartIndex[count][2] = count;
		count++;
	}
	sort(weightSmartIndex, count - 1);
	LCS(weightSmartIndex, count - 1);
	printf("%d\n", memo[count - 2][count - 2]);
	result(count - 1);
}