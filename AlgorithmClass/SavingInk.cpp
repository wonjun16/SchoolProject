#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h> //pow, sqrt

bool selected[31]; // visited nodes
float adjacencyMatrix[31][31];
float MST[31];

float findDistance(int x1, int y1, int x2, int y2) { //find distance between two dots
	float distance;
	distance = sqrt(pow((x2 - x1), 2.0) + pow((y2 - y1), 2.0));
	return distance;
}

void createMatrix(int n,int dots[][2]) { //create adjacency matrix
	for (int i = 1; i < n + 1; i++)
		for (int j = 1; j < n + 1; j++)
			adjacencyMatrix[i][j] = findDistance(dots[i][0], dots[i][1], dots[j][0], dots[j][1]);
}

int findMinIndex(int n, int start) { //find minimum distance index
	int minIndex = start;
	for (int i = 1; i < n + 1; i++) {
		if (!selected[i]) {
			if (minIndex == start)
				minIndex = i;
			else {
				if (adjacencyMatrix[start][i] < adjacencyMatrix[start][minIndex])
					minIndex = i;
			}
		}
	}
	return minIndex;
}

void prim(int n) { //find MST from using prim algorithm
	selected[1] = 1; // start node > visited
	for (int i = 1; i < n; i++) { //each step, find one MST edge
		int minIndex; //index of end node minimum cost edge
		float minValue; //cost of edge
		for (int j = 1; j < n + 1; j++) { // for visited all nodes
			if (j == 1) { //initailize minIndex, minValue
				minIndex = findMinIndex(n, j);
				minValue = adjacencyMatrix[j][minIndex];
			}
			else {
				if (selected[j]) { //if visited node
					if (minValue > adjacencyMatrix[j][findMinIndex(n, j)]) {
						minIndex = findMinIndex(n, j);
						minValue= adjacencyMatrix[j][minIndex];
					}
				}
			}
		}
		selected[minIndex] = 1; //visit processing
		MST[i] = minValue; //find one MST edge's cost
	}
}

float sumMST(int n) {
	float total = 0.0;
	for (int i = 1; i < n + 1; i++)
		total += MST[i];
	return total;
}

void main() {
	int n, dots[31][2] = { 0 };
	printf("number of dots : ");
	scanf("%d", &n);
	for (int i = 1; i < n + 1; i++)
		scanf("%d %d", &dots[i][0], &dots[i][1]);
	createMatrix(n, dots);
	prim(n);
	printf("%.2f", sumMST(n));
}