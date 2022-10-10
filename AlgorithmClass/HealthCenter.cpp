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
int result[SIZE][SIZE];

void initailizeShotestPath(int edgeCost[][3], int numInter) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			shortestPath[i][j] = INF;
		}
	}
	for (int i = 1; i < numInter + 1; i++) {
		shortestPath[i][i] = 0;
		shortestPath[edgeCost[i][0]][edgeCost[i][1]] = edgeCost[i][2];
		shortestPath[edgeCost[i][1]][edgeCost[i][0]] = edgeCost[i][2];
	}
}

void floydWarshall(int numHealth, int edgeCost[][3], int numInter) {
	initailizeShotestPath(edgeCost, numInter);
	for (int i = 1; i < numInter + 1; i++) {
		for (int j = 1; j < numInter + 1; j++) {
			for (int k = 1; k < numInter + 1; k++) {
				if (shortestPath[j][k] > shortestPath[j][i] + shortestPath[i][k]) {
					shortestPath[j][k] = shortestPath[j][i] + shortestPath[i][k];
				}
			}
		}
	}
}

//int findMax(int numHealth, int locationHealth[], int numInter) {
//	int maxIndex = 1, maxArray[SIZE][2] = { 0 };
//	for (int i = 1 ; i < numHealth + 1; i++) {
//		for (int j = 1; j < numInter + 1; j++) {
//			if (locationHealth[i] != j) {
//				maxArray[j][1] += shortestPath[locationHealth[i]][j];
//				maxArray[j][0] = j;
//			}
//		}
//	}
//	for (int i = 1; i < numHealth + 1; i++) { //�̺κ� ���� �̿ϼ�. �ｺ���Ͱ� 2�� �̻� ������� �������� �� ��¾ȵ�. 1���϶� �������� �� ��µ�
//		int count = 0;
//		for (int j = 1; j < numInter + 1; j++) {
//			if (maxArray[maxIndex][1] < maxArray[j][1] && locationHealth[i] != j)
//				count++;
//		}
//		if(count==numInter)
//			maxIndex = maxArray[i][0];
//	}
//	return maxIndex;
//}

void findResult(int numHealth, int locationHealth[], int numInter) {
	for (int i = 1; i < numInter + 1; i++) { //���� ���� �ｺ��
		for (int j = 1; j < numInter + 1; j++) { // �ش� ��忡�� ���� ª�� �Ÿ�
			int min=shortestPath[j][locationHealth[1]];
			for (int k = 1; k < numHealth + 1; k++) {
				if (min > shortestPath[j][locationHealth[k]])
					min = shortestPath[j][locationHealth[k]];
			}
			if (min > shortestPath[j][i])
				min = shortestPath[j][i];
			result[i][j] = min;
		}
	}
}

int findMin(int numInter) {
	int lineMax, totalMin=INF, minIndex=1;
	for (int i = 1; i < numInter + 1; i++) {
		lineMax = result[i][1];
		for (int j = 1; j < numInter + 1; j++) {
			if (lineMax < result[i][j])
				lineMax = result[i][j];
		}
		if (totalMin > lineMax) {
			totalMin = lineMax;
			minIndex = i;
		}
	}
	return minIndex;
}

void main() {
	int numHealth, numInter, locationHealth[SIZE], edgeCost[SIZE][3];
	scanf("%d %d", &numHealth, &numInter);
	for (int i = 1; i < numHealth+1; i++)
		scanf("%d", &locationHealth[i]);
	for (int i = 1; i < numInter+1; i++)
		scanf("%d %d %d", &edgeCost[i][0], &edgeCost[i][1], &edgeCost[i][2]);
	floydWarshall(numHealth, edgeCost, numInter);
	//printf("Location to build health center : %d", findMax(numHealth, locationHealth, numInter));
	findResult(numHealth, locationHealth, numInter);
	printf("Location to build health center : %d", findMin(numInter));
}