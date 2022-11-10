//각 점들에 대해서 이루는 각 중 최솟값 찾음
		//해당 점을 방문점에 포함
		//이미 방문한 점이 최솟값일때까지 해당 과정 반복
		//거리구함
		//답 출력
// 일직선상에 놓인 점들에 대해서는 어케하지?
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int findMinAngle(int dotNum, float dots[][2], float nowDot[]) {
	float minAngle=360, tempAngle, Dx, Dy;
	int minAngleIndex = 0;
	
	for (int i = 0; i < dotNum+1; i++) {
		if (nowDot[0] == dots[i][0] && nowDot[1] == dots[i][1])
			continue;

		Dx = dots[i][0] - nowDot[0];
		Dy = dots[i][1] - nowDot[1];

		if ((Dx >= 0) && (Dy == 0))tempAngle = 0;
		else {
			tempAngle = fabs(Dy) / (fabs(Dx) + fabs(Dy));
			if ((Dx < 0) && (Dy >= 0))tempAngle = 2 - tempAngle;
			else if ((Dx <= 0) && (Dy < 0))tempAngle = 2 + tempAngle;
			else if ((Dx > 0) && (Dy < 0))tempAngle = 4 - tempAngle;
		}
		printf("nowDot[0] = %f, nowDot[1] = %f, minAngleIndex = %d, tempAngle = %f, Dx = %f, Dy = %f\n", nowDot[0], nowDot[1], minAngleIndex, tempAngle, Dx, Dy);
		if (minAngle >= tempAngle) {
			minAngle = tempAngle;
			minAngleIndex = i;
		}
	}
	return minAngleIndex;
}

float findDistance(float dots[][2], int visited[], int nowDots) {
	float distance = 0.0;
	for (int i = 0; i < nowDots - 1; i++) {
		int x1, x2, y1, y2;
		x1 = dots[visited[i]][0];
		y1 = dots[visited[i]][1];
		x2 = dots[visited[i + 1]][0];
		y2 = dots[visited[i + 1]][1];
		distance += sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	}
	return distance;
}

void main() {
	int testCase;

	printf("input testcase : ");
	scanf("%d", &testCase);
	printf("\n");

	for (int i = 0; i < testCase; i++) {
		int dotNum, visited[100] = { 0 }, nowDots = 1, breakPoint=0;
		float dots[100][2] = { 0 }, distance;

		printf("input dotNum : ");
		scanf("%d", &dotNum);

		printf("---input dots---\n");
		for (int j = 1; j < dotNum + 1; j++) {
			scanf("%f %f", &dots[j][1], &dots[j][0]);
		}

		for (int h = 0; h < dotNum; h++) {
			int  resultDotIndex;
			resultDotIndex = findMinAngle(dotNum, dots, dots[nowDots - 1]);
			for (int k = 0; k < nowDots; k++) {
				if (resultDotIndex == visited[k])
					breakPoint = 1;
			}
			if (breakPoint)
				break;
			else {
				visited[nowDots] = resultDotIndex;
				nowDots++;
			}
		}

		distance = findDistance(dots, visited, nowDots) + 2;

		printf("result : %.2f\n", distance);
		for (int i = 0; i < dotNum + 1; i++) {
			printf("dots[%d][0] = %f dots[%d][1] = %f\n", i, dots[i][0], i, dots[i][1]);
		}
	}
}