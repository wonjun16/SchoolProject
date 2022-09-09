#include<stdio.h>
#define SIZE 10

 int findMaxAge(int age[]) {
	 int maxAgeIndex = 0;
	 for (int i = 1; i < SIZE; i++) {
		 if (age[i] > age[maxAgeIndex])
			 maxAgeIndex = i;
	 }
	 return maxAgeIndex;
}

 void showMaxAge(int maxAgeIndex, int score[], int age[]) {
	 for (int i = 0; i < SIZE; i++) {
		 if (age[maxAgeIndex] == age[i]) {
			 printf("Oldest student's score : %d\n", score[i]);
		 }
	 }
 }

void main() {
	int age[SIZE], score[SIZE], maxAgeIndex;
	for (int i = 0; i < SIZE; i++) {
		printf("age score : ");
		scanf_s("%d %d", &age[i], &score[i]);
	}
	maxAgeIndex = findMaxAge(age);
	showMaxAge(maxAgeIndex, score, age);
}