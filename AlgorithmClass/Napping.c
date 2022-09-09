//version for data always given with sorting
#include<stdio.h>

void main() {
	int n, maxIndex=0;
	int time[100][4] = { 0 }, breakTime[100][2] = { 0 };
	printf("number of schedules : ");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("schedule no.%d : ", i+1);
		scanf_s("%d:%d %d:%d", &time[i][0], &time[i][1], &time[i][2], &time[i][3]);
	}
	for (int i = 0; i < n-1; i++) {
		if (time[i+1][1] < time[i][3]) {
			breakTime[i][0] = time[i+1][0] - time[i][2] - 1;
			breakTime[i][1] = time[i+1][1] - time[i][3] + 60;
		}
		else {
			breakTime[i][0] = time[i+1][0] - time[i][2];
			breakTime[i][1] = time[i+1][1] - time[i][3];
		}
	}
	for (int i = 0; i < n; i++) {
		if (breakTime[maxIndex][0] < breakTime[i][0] || 
			(breakTime[maxIndex][0] == breakTime[i][0] && breakTime[maxIndex][1] < breakTime[i][1]))
			maxIndex = i;
	}
	printf("good time for a nap : %dhours %dminutes\n", breakTime[maxIndex][0], breakTime[maxIndex][1]);
}
