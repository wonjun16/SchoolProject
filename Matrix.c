#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void main(void) {
	int matrix1[10][10], matrix2[10][10], matrix3[10][10], matrix4[100] = { 0 };
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			matrix1[i][j] = i * 10 + j;
			matrix2[i][j] = 2 * (i * 10 + j);
			matrix3[i][j] = matrix1[i][j] * matrix2[i][j];
			if (!i && !j) continue;
			matrix4[i * 10 + j] = 1;
		}
	}
	//Sieve of Eratosthenes
	for (int i = 2; i*i < 101; i++) {
		if (matrix4[i-1]) {
			for (int j = i + i; j < 101; j += i) {
				matrix4[j - 1] = 0;
			}
		}
	}
	printf("=====================================MATRIX1====================================\n");
	for (int j = 0; j < 10; j++) {
		for (int k = 0; k < 10; k++)
			printf("%7d ", matrix1[j][k]);
		printf("\n");
	}
	printf("=====================================MATRIX2====================================\n");
	for (int j = 0; j < 10; j++) {
		for (int k = 0; k < 10; k++)
			printf("%7d ", matrix2[j][k]);
		printf("\n");
	}
	printf("=====================================MATRIX3====================================\n");
	for (int j = 0; j < 10; j++) {
		for (int k = 0; k < 10; k++)
			printf("%7d ", matrix3[j][k]);
		printf("\n");
	}
	printf("=====================================MATRIX4====================================\n");
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			printf("%7d ", matrix4[i * 10 + j]);
		printf("\n");
	}
}