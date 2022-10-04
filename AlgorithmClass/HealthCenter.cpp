/*교차로에만 병원이 존재한다(도로가 맞물리는 지점)
* 존재하는 병원숫자, 교차로 숫자, 
헬스센터가 있는 교차로 번호,
두 교차로 사이 거리
* 모든 엣지는 양방향
* 가장 거리가 먼 곳의 번호 출력 (두 개 이상일 경우 작은 번호 출력)
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define INF 10000000
#define SIZE 21

int shortestPath[SIZE][SIZE];

void initailizeShotestPath(int edgeCost[][3], int numInter) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			shortestPath[i][j] = INF;
		}
	}
	for (int i = 1; i < numInter + 1; i++) {
		shortestPath[i][i] = 0;
		shortestPath[edgeCost[i][0]][edgeCost[i][1]] = edgeCost[i][2];
	}
}

void floydWarshall(int numHealth, int edgeCost[][3], int numInter) {
	initailizeShotestPath(edgeCost, numInter);
	for (int i = 1; i < numHealth + 1; i++) {
		for (int j = 1; j < numHealth + 1; j++) {
			for (int k = 1; k < numHealth + 1; k++) {
				if (shortestPath[j][k] > shortestPath[j][i] + shortestPath[i][k]) {
					shortestPath[j][k] = shortestPath[j][i] + shortestPath[i][k];
				}
			}
		}
	}
}

int findMax(int numHealth) {
	int maxIndex=0, max = 0;
	for (int i = 1; i < numHealth + 1; i++) {
		for (int j = 1; j < numHealth + 1; j++) {
			if (max < shortestPath[i][j]) {
				max = shortestPath[i][j];
				maxIndex = i;
			}
		}
	}
	return maxIndex;
}

void main() {
	int numHealth, numInter, locationHealth[SIZE], edgeCost[SIZE][3];
	scanf("%d %d", &numHealth, &numInter);
	printf("health : ");
	for (int i = 1; i < numHealth+1; i++)
		scanf("%d", &locationHealth[i]);
	printf("inter : ");
	for (int i = 1; i < numInter+1; i++)
		scanf("%d %d %d", &edgeCost[i][0], &edgeCost[i][1], &edgeCost[i][2]);
	floydWarshall(numHealth, edgeCost, numInter);
	printf("Location to build health center : %d", findMax(numHealth));
}