/*�����ο��� ������ �����Ѵ�(���ΰ� �¹����� ����)
* �����ϴ� ��������, ������ ����, 
�ｺ���Ͱ� �ִ� ������ ��ȣ,
�� ������ ���� �Ÿ�
* ��� ������ �����
* ���� �Ÿ��� �� ���� ��ȣ ��� (�� �� �̻��� ��� ���� ��ȣ ���)
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