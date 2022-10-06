#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

typedef struct card {
	char shape[20];
	int value;
}CARD;

typedef struct user {
	int cardNumber;
}USER;

typedef struct computer {
	int cardNumber;
}COMPUTER;

CARD cardDeck[48];
USER userPick[5];
COMPUTER computerPick[5];

void initailzeCardDeck() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 4; j++) {
			switch (j)
			{
			case 0:
				strcpy(cardDeck[i * 4 + j].shape, "Diamond");
				cardDeck[i * 4 + j].value = i + 1;
				break;
			case 1:
				strcpy(cardDeck[i * 4 + j].shape, "Spade");
				cardDeck[i * 4 + j].value = i + 1;
				break;
			case 2:
				strcpy(cardDeck[i * 4 + j].shape, "Hart");
				cardDeck[i * 4 + j].value = i + 1;
				break;
			case 3:
				strcpy(cardDeck[i * 4 + j].shape, "Clover");
				cardDeck[i * 4 + j].value = i + 1;
				break;
			}
		}
	}
}

void userPickForRamdom() {
	for (int i = 0; i < 5; i++) {
		srand(time(NULL));
		userPick[i].cardNumber = rand() % 48 + 1;
	}
}

void computerPickForRamdom() {
	for (int i = 0; i < 5; i++) {
		srand(time(NULL));
		computerPick[i].cardNumber = rand() % 48 + 1;
	}
}

int findUserTotal() {
	int totalValue=0;
	for (int i = 0; i < 5; i++)
		totalValue += cardDeck[userPick[i].cardNumber].value;
	return totalValue;
}

int findComputerTotal() {
	int totalValue = 0;
	for (int i = 0; i < 5; i++)
		totalValue += cardDeck[computerPick[i].cardNumber].value;
	return totalValue;
}

char* findUserShape() {
	int max= cardDeck[userPick[0].cardNumber].value, maxIndex=0;
	char shape[20];
	for (int i = 0; i < 5; i++) {
		if (max < cardDeck[userPick[i].cardNumber].value) {
			max = cardDeck[userPick[i].cardNumber].value;
			maxIndex = i;
		}
	}
	strcpy(shape, cardDeck[userPick[maxIndex].cardNumber].shape);
	return shape;
}

char* findComputerShape() {
	int max = cardDeck[computerPick[0].cardNumber].value, maxIndex = 0;
	char shape[20];
	for (int i = 0; i < 5; i++) {
		if (max < cardDeck[computerPick[i].cardNumber].value) {
			max = cardDeck[computerPick[i].cardNumber].value;
			maxIndex = i;
		}
	}
	strcpy(shape, cardDeck[computerPick[maxIndex].cardNumber].shape);
	return shape;
}

void ComputerVsUser(int userTotal, int computerTotal, char userShape[], char computerShape[]) {
	printf("User total : %d\n", userTotal);
	printf("User shape : %s\n", userShape);
	printf("Computer total : %d\n", computerTotal);
	printf("Computer shape : %s\n", computerShape);
	if (userTotal > computerTotal)
		printf("USER WIN!!!!!\n");
	else if (computerTotal > userTotal)
		printf("COMPUTER WIN!!!!!\n");
	else {

	}
}

void main() {
	int userTotal, computerTotal;
	char userShape[20], computerShape[20];
	initailzeCardDeck();
	userPickForRamdom();
	computerPickForRamdom();
	userTotal = findUserTotal();
	computerTotal = findComputerTotal();
	strcpy(userShape, findUserShape());
	strcpy(computerTotal, findComputerShape());

}