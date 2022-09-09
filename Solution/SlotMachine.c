#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define RMAX 4

void main() {
	int slot1, slot2, slot3;
	char pocket[RMAX][10] = { "CHERRY\0", "C\0", "A\0", "B\0" };
	char anyKey;
	while (1) {
		printf("Input anykey for start : ");
		scanf("%c", &anyKey);
		srand(time(NULL));
		slot1 = 1 + (int)rand() % RMAX;
		slot2 = 1 + (int)rand() % RMAX;
		slot3 = 1 + (int)rand() % RMAX;
		printf("slot1 : %s\n", pocket[slot1 - 1]);
		printf("slot1 : %s\n", pocket[slot2 - 1]);
		printf("slot1 : %s\n", pocket[slot3 - 1]);
		if (slot1 == slot2 && slot2 == slot3 && slot1 == 1)
			printf("JACKPOT\n");
		else if (slot1 == 1 || slot2 == 1 || slot3 == 1)
			printf("ONE DIME\n");
		else if (slot1 == slot2 || slot1 == slot3 || slot2 == slot3)
			printf("ONE NICKEL\n");
		else printf("BETTER LUCK NEXT TIME\n");
	}
	
}