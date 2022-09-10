#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h> //rand, srand
#include<time.h> //time
#include<string.h> //strcmp
char space[4][10] = { "Rock\0", "Sissors\0", "Paper\0" , "Try again\0"};
char* pickComputer() { //pick computer's choice for random
	int pick;
	srand(time(NULL));
	pick = rand() % 3;
	return space[pick];
}

char* pickUser(char user) { //pick user's choice for input
	int userResult;
	if (user == 'r') userResult = 0;
	else if (user == 's') userResult = 1;
	else if (user == 'p') userResult = 2;
	else userResult = 3;
	return space[userResult];
}

void showResult(char computer[], char user[]) { // show result
	printf("Computer : %s  /  User : %s\n", computer, user);
	if (!strcmp(user, computer))
		printf("Draw!\n");
	else {
		if ((!strcmp(computer, "Rock") && !strcmp(user, "Paper"))
			|| (!strcmp(computer, "Paper") && !strcmp(user, "Sissors"))
			|| (!strcmp(computer, "Sissors") && !strcmp(user, "Rock")))
			printf("You Win!\n");
		else
			printf("You Lose!\n");
	}
}

void main() {
	char key;
	do {
		printf("-------------Rock-------------Sissors-------------Paper-------------\n");
		printf("Rock : r / Sissors : s / Paper : p / Exit : e\n");
		key = getchar();
		rewind(stdin);
		if (key == 'r' || key == 's' || key == 'p')
			showResult(pickComputer(), pickUser(key));
		else if(key!='e')
			printf("%s\n", pickUser(key));
	} while (key!='e');
}