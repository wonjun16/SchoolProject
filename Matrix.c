#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void main(void) {
	int matrix1[10][10], matrix2[10][10], matrix3[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			matrix1[i][j] = i * 10 + j;
			matrix2[i][j] = 2 * (i * 10 + j);
			matrix3[i][j] = matrix1[i][j] * matrix2[i][j];
		}
	}
	printf("=======================MATRIX1======================\n");
	for (int j = 0; j < 10; j++) {
		for (int k = 0; k < 10; k++) {
			printf("%7d ", matrix1[j][k]);
		}
		printf("\n");
	}
	printf("=======================MATRIX2=======================\n");
	for (int j = 0; j < 10; j++) {
		for (int k = 0; k < 10; k++) {
			printf("%7d ", matrix2[j][k]);
		}
		printf("\n");
	}
	printf("=======================MATRIX3=======================\n");
	for (int j = 0; j < 10; j++) {
		for (int k = 0; k < 10; k++) {
			printf("%7d ", matrix3[j][k]);
		}
		printf("\n");
	}
}