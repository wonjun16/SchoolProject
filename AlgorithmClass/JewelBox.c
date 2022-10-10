#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

float findCost(int c, int n) {
	return (float)n / c;
}

void findResult(int *jewel, int n, int* result) {
	*result = *jewel / n;
	*jewel %= n;
}

void check(int* jewel, int n1, int n2, int* result, int jewelNum) {
	if (*jewel % n2) {
		while (*jewel % n2 && *jewel < jewelNum) {
			*jewel += n1;
			(*result)--;
		}
	}
}

void main() {
	int jewelNum;
	do {
		int c1, c2, n1, n2, result1, result2 ,jewel;
		float cost1, cost2, highCost;
		scanf("%d", &jewelNum);
		if (jewelNum) {
			scanf("%d %d", &c1, &n1);
			scanf("%d %d", &c2, &n2);
			jewel = jewelNum;
			cost1 = findCost(c1, n1);
			cost2 = findCost(c2, n2);
			if (cost1 > cost2) {
				findResult(&jewel, n1, &result1);
				check(&jewel, n1, n2, &result1, jewelNum);
				findResult(&jewel, n2, &result2);
			}
			else if (cost1 < cost2) {
				findResult(&jewel, n2, &result2);
				check(&jewel, n2, n1, &result2, jewelNum);
				findResult(&jewel, n1, &result1);
			}
			else {
				if (n1 > n2) {
					findResult(&jewel, n2, &result2);
					check(&jewel, n2, n1, &result2, jewelNum);
					findResult(&jewel, n1, &result1);
				}
				else {
					findResult(&jewel, n1, &result1);
					check(&jewel, n1, n2, &result1, jewelNum);
					findResult(&jewel, n2, &result2);
				}
			}
			if (!jewel)
				printf("%d %d\n", result1, result2);
			else
				printf("failed\n");
		}
	} while (jewelNum);
}