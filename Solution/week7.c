#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define NUM_TEST_SET 5

int text_search(char full_text[], char search_text[]) {
	int cursor = 0, pp = 0, count = 0;
	for (cursor; cursor < sizeof(full_text); cursor++) {
		while (full_text[cursor] != '\0' && search_text[pp]!='\0') {
			if (full_text[cursor] == search_text[pp]) {
				//printf("%c : %c %c\n", full_text[cursor], search_text[pp], 'o');
				cursor++;
				pp++;
			}
			else {
				//printf("%c : %c %c\n", full_text[cursor], search_text[pp], 'x');
				cursor++;
				pp = 0;
			}
			if (search_text[pp] == '\0') {
				count++;
				//printf("count=%d\n\n", count);
				pp = 0;
			}
		}
	}
	return count;
}

int main() {
	char txt[NUM_TEST_SET][256] = { "My name is Hong", "second test case test case of second line"};
	char search[NUM_TEST_SET][256] = { "name" , "test"};


	for (int i = 0; i < NUM_TEST_SET; i++) {
		int count;
		char* str = txt[i];
		char* str_search = search[i];
		printf("--------------------------\n");
		printf("-------TEST_CASE%d--------\n", i + 1);
		printf("--------------------------\n");
		printf("str = %s\n", str);
		printf("str_search = %s\n", str_search);
		count = text_search(str, str_search);
		printf("%s count is %d\n", str_search, count);
	}
}