#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define SIZE 5

typedef struct stock {
	char name[20];
	float EPS;
	float PER;
	float stockPrice;
}Stock;

void calcStockPrice(Stock* s) { //calculate stock price
	s->stockPrice = s->EPS * s->PER;
}

void sortStockPrice(Stock s[]) { //sort stock information with stock price ascending order
	char tempName[20];
	float tempEPS, tempPER, tempStockPrice;
	for (int i = 0; i < SIZE; i++) {
		int minIndex = i;
		for (int j = i; j < SIZE; j++) {
			if (s[minIndex].stockPrice > s[j].stockPrice)
				minIndex = j;
		}
		strcpy(tempName, s[minIndex].name); //switch information
		tempEPS = s[minIndex].EPS;
		tempPER = s[minIndex].PER;
		tempStockPrice = s[minIndex].stockPrice;

		strcpy(s[minIndex].name, s[i].name);
		s[minIndex].EPS = s[i].EPS;
		s[minIndex].PER = s[i].PER;
		s[minIndex].stockPrice = s[i].stockPrice;

		strcpy(s[i].name, tempName);
		s[i].EPS = tempEPS;
		s[i].PER = tempPER;
		s[i].stockPrice = tempStockPrice;
	}
}

void main() {
	Stock stockData[SIZE]; // create stock dataset with size="SIZE"
	printf("Input five stock datasets.\n");
	printf("Form : name EPS PER\n");

	for (int i = 0; i < SIZE; i++) //input name, EPS, PER data
		scanf("%s %f %f", stockData[i].name, &stockData[i].EPS, &stockData[i].PER);

	for (int i = 0; i < SIZE; i++) //calculate stock price for each data
		calcStockPrice(&stockData[i]);

	sortStockPrice(stockData); //sort stock datasets with stock price ascending order

	for (int i = 0; i < SIZE; i++) // print result
		printf("name : %s / EPS : %.2f / PER : %.2f / StockPrice : %.2f\n", stockData[i].name, stockData[i].EPS, stockData[i].PER, stockData[i].stockPrice);
}