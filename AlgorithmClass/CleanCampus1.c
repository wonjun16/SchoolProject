#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

typedef struct dot {
	float x;
	float y;
}DOT;

DOT dots[100];
DOT hull[100];
int hull_index = 2;

float find_angle(DOT dot) {
	float x = dot.x;
	float y = dot.y;
	float angle;

	if (x >= 0 && y == 0) angle = 0;
	else {
		angle = y / (x + y);
		if (x < 0 && y >= 0) angle = 2 - angle;
		else if (x <= 0 && y < 0) angle = 2 + angle;
		else if (x > 0 && y < 0) angle = 4 - angle;
	}

	return angle;
}

void sort_dots(int dotsNum) {
	for (int i = 1; i <= dotsNum; i++) {
		float minAngle = find_angle(dots[i]);
		int minIndex = i;
		float temp_x; float temp_y;
		for (int j = i; j <= dotsNum; j++) {
			if (find_angle(dots[j]) < minAngle) {
				minAngle = find_angle(dots[j]);
				minIndex = j;
			}
		}

		temp_x = dots[minIndex].x; temp_y = dots[minIndex].y;
		dots[minIndex].x = dots[i].x; dots[minIndex].y = dots[i].y;
		dots[i].x = temp_x; dots[i].y = temp_y;
	}
}

float ccw(DOT dot1, DOT dot2, DOT dot3) {
	return (dot1.x * (dot2.y - dot3.y) + dot2.x * (dot3.y - dot1.y) + dot3.x * (dot1.y - dot2.y));
}

void convex_hull(int dotsNum) {
	hull[0].x = dots[0].x; hull[0].y = dots[0].y;
	hull[1].x = dots[1].x; hull[1].y = dots[1].y;
	for (int i = 2; i < dotsNum + 2; i++) {
		if (ccw(dots[i - 2], dots[i - 1], dots[i]) >= 0) {
			hull[hull_index].x = dots[i].x;
			hull[hull_index].y = dots[i].y;
			hull_index++;
		}
	}
}

float culc_distance() {
	float distance = 0;
	for (int i = 0; i < hull_index - 1; i++) {
		distance += sqrt((hull[i + 1].x - hull[i].x) * (hull[i + 1].x - hull[i].x) + (hull[i + 1].y - hull[i].y) * (hull[i + 1].y - hull[i].y));
	}
	return distance;
}

void main() {
	int n;
	printf("test case : ");
	scanf("%d", &n);
	printf("\n");

	for (int i = 0; i < n; i++) {
		int dotsNum;
		printf("dots num : ");
		scanf("%d", &dotsNum);

		for (int j = 1; j <= dotsNum; j++) {
			scanf("%f %f", &dots[j].x, &dots[j].y);
		}

		sort_dots(dotsNum);

		convex_hull(dotsNum);

		for (int i = 0; i < dotsNum; i++)
			printf("%f %f\n", dots[i].x, dots[i].y);

		printf("hull_index : %d\n", hull_index);
		for (int i = 0; i < hull_index; i++)
			printf("%f %f\n", hull[i].x, hull[i].y);

		//printf("distance : %.2f", culc_distance());
	}
}