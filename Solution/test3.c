#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int key;
	struct node* next;
}NODE;

NODE* createNode(int x) {
	NODE* node = (NODE*)malloc(sizeof(NODE));
	node->key = x;
	node->next = NULL;
	return node;
}

void displayList(NODE* head) {
	NODE* ptr = head;
	int index = 1;
	while (ptr) {
		printf("%d번째 데이터는 %d입니다\n", index, ptr->key);
		ptr = ptr->next;
		index++;
	}
}

int lengthTest(NODE* head) {
	NODE* ptr = head;
	int length = 0;
	while (ptr) {
		ptr = ptr->next;
		length++;
	}
	return length;
}

void searchTest(NODE* head, int searchKey) {
	NODE* ptr = head;
	int searchResult = 0;
	while (ptr) {
		if (ptr->key == searchKey) {
			searchResult++;
		}
		ptr = ptr->next;
	}
	if (searchResult) {
		printf("Linked List안에 %d개의 %d데이터가 있습니다.\n", searchResult, searchKey);
	}
	else {
		printf("Linked List안에 %d데이터가 없습니다.\n", searchKey);
	}
}

void push(NODE** head, int data) {
	NODE* node = createNode(data);
	node->next = *head;
	*head = node;
}

void appendNode(NODE** head, int data) {
	NODE* node = createNode(data);
	NODE* ptr = *head;
	if (ptr == NULL) {
		*head = node;
	}
	else {
		while (ptr->next) {
			ptr = ptr->next;
		}
	}
	ptr->next = node;
}

void deleteNode(NODE **head, int data) {
	NODE* old_ptr=NULL, *ptr=*head;
	while (ptr) {
		if (ptr->key==data && ptr==*head) {
			*head = ptr->next;
			free(ptr);
			break;
		}
		if (ptr->key == data) {
			old_ptr->next = ptr->next;
			free(ptr);
			break;
		}
		old_ptr = ptr;
		ptr = ptr->next;
	}
	if (!ptr) {
		printf("해당 값을 찾지 못했습니다.\n");
	}
}

void removeTail(NODE** head)

{

	NODE* curPtr = *head;

	NODE* prevPtr = NULL;

	// special case for length 0

	if (curPtr == NULL) {

		return;

	}

	while (curPtr->next != NULL) {

		prevPtr = curPtr;

		curPtr = curPtr->next;

	}

	// at this point, ptr is referring the tail node

	// two cases: length = 1,  length > 1

	if (*head == curPtr) {

		free(curPtr);

		*head = NULL;

	}

	else {

		free(curPtr);

		prevPtr->next = NULL;

	}

}

void removeALL(NODE** head) {
	NODE* old_ptr = *head , * ptr = (*head)->next;
	while (ptr) {
		free(old_ptr);
		old_ptr = ptr;
		ptr = ptr->next;
	}
	*head = NULL;
	printf("정상적으로 해제되었습니다.\n");
}

void insertNode(NODE** head, int data) {
	NODE* node = createNode(data), * old_ptr=NULL, * ptr = *head;
	if (ptr->key > data) {
		node->next = ptr;
		*head = node;
		return;
	}
	while (ptr->next) {
		if (ptr->key == data) {
			printf("data is already exist.\n");
			break;
		}
		if (ptr->key < data) {
			old_ptr = ptr;
			ptr = ptr->next;
		}
		else {
			/*if (ptr == *head) {
				node->next = *head;
				*head = node;
				break;
			}*/
			old_ptr->next = node;
			node->next = ptr;
			break;
		}
	}
	if(!(ptr->next))
		ptr->next = node;
}

void main() {
	int length;
	NODE* node1 = createNode(100);
	NODE* node2 = createNode(200);
	NODE* node3 = createNode(300);
	NODE* head = node1;

	node1->next = node2;
	node2->next = node3;

	/*displayList(head);

	length = lengthTest(head);
	printf("Length of Linked List : %d\n", length);

	searchTest(head, 200);

	push(&head, 10);

	displayList(head);

	appendNode(&head, 400);

	displayList(head);*/

	insertNode(&head, 5);
	insertNode(&head, 250);
	insertNode(&head, 1000);

	deleteNode(&head, 200);

	displayList(head);

	removeALL(&head);

	displayList(head);
}