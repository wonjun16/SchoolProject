#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int euclid(int a, int b) {
	if (a < b) {
		int temp = a;
		a = b;
		b = temp;
	}
	if (b == 0)
		return a;
	else
		euclid(b, a % b);
}

void extend_euclid(int a, int b) {
	int r0 = a, r1 = b;
	int s0 = 1, s1 = 0;
	int t0 = 0, t1 = 1;
	int temp = 0, q = 0;

	while (r1) {
		q = r0 / r1;
		temp = r0;
		r0 = r1;
		r1 = temp - r1 * q;
		temp = s0;
		s0 = s1;
		s1 = temp - s1 * q;
		temp = t0;
		t0 = t1;
		t1 = temp - t1 * q;
	}

	printf("%d %d", s0, t0);
}

void main() {
	int a, b, d;
	printf("a, b : ");
	scanf("%d %d", &a, &b);
	d = euclid(a, b);
	extend_euclid(a, b);
	printf(" %d", d);
}