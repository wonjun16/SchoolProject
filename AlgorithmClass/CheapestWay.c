#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define row 10
#define col 100

//cheapest value, way
typedef struct dp {
	int minValue;
	int cheapestWay[col];
}dp;
dp dpList[row][col];

//find minimum value index
int findMin(int a, int b, int c, int y) {
	int min;
	if (dpList[a][y].minValue > dpList[b][y].minValue) {
		if (dpList[b][y].minValue > dpList[c][y].minValue) min = c;
		else min = b;
	}
	else {
		if (dpList[a][y].minValue > dpList[c][y].minValue)min = c;
		else min = a;
	}
	return min;
}

//copy cheapestWay array
void copy(int arr1[], int arr2[], int size) {
	for (int i = 0; i < size; i++) {
		arr2[i] = arr1[i];
	}
}

//fill dp table
void dpAlgorithm(int matrix[][col], int x, int y) {
	for (int i = 0; i < y; i++) {
		int minIndex;
		for (int j = 0; j < x; j++) {
			if (!i) {
				dpList[j][i].minValue = matrix[j][i];
				dpList[j][i].cheapestWay[i] = matrix[j][i];
			}
			else {
				if (!j) minIndex = findMin(0, 1, x - 1, i - 1);
				else if (j == x - 1) minIndex = findMin(0, x - 1, x - 2, i - 1);
				else minIndex = findMin(j, j - 1, j + 1, i - 1);
				dpList[j][i].minValue = dpList[minIndex][i - 1].minValue + matrix[j][i];
				copy(dpList[minIndex][i - 1].cheapestWay, dpList[j][i].cheapestWay, i + 1);
				dpList[j][i].cheapestWay[i] = matrix[j][i];
			}
		}
	}
}

//find cheapest way index
int findDpIndex(int x, int y) {
	int minIndex=0;
	for (int i = 0; i < x; i++) {
		if (dpList[i][y].minValue < dpList[minIndex][y].minValue) minIndex = i;
	}
	return minIndex;
}

//print result
void print(int index, int y) {
	printf("\n");
	for (int i = 0; i < y + 1; i++)
		printf("%d ", dpList[index][y].cheapestWay[i]);
	printf("\n%d", dpList[index][y].minValue);
}

void main() {
	int x, y, matrix[row][col]; //inital data
	scanf("%d %d", &x, &y);
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++)
			scanf("%d", &matrix[i][j]);
	}
	dpAlgorithm(matrix, x, y);
	print(findDpIndex(x, y - 1), y - 1);
}