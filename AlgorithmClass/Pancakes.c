#include<stdio.h>
#define SIZE 5

int result[100];
int resultIndex = 0;

//reverse index : filpIndex ~ SIZE-1
void filp(int pancakes[], int filpIndex) {
	int temp, index=1;
	for (int i = filpIndex; i < filpIndex+(SIZE - filpIndex) / 2; i++) {
		temp = pancakes[i];
		pancakes[i] = pancakes[SIZE - index];
		pancakes[SIZE - index] = temp;
		index++;
	}
	result[resultIndex] = filpIndex+1;
	resultIndex++;
}

int findMaxValue(int pancakes[], int start) {
	int maxIndex=start;
	for (int i = start; i < SIZE; i++) {
		if (pancakes[i] > pancakes[maxIndex])
			maxIndex = i;
	}
	return maxIndex;
}

void sortPancakes(int pancakes[]) {
	for (int i = 0; i < SIZE-1; i++) {
		int max = findMaxValue(pancakes, i);
		if (max == SIZE - 1)
			filp(pancakes, i);
		else if (max!=i && max < SIZE) {
			filp(pancakes, max);
			filp(pancakes, i);
		}
		else continue;
	}
}

void main() {
	int pancakes[SIZE] = {1, 2, 4, 3, 5};
	sortPancakes(pancakes);
	for (int i = 0; i < resultIndex+1; i++)
		printf("%d ", result[i]);
}