#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	short index;
	short data;
	struct Node* prev;
	struct Node* next;
}Node;

void insert(Node** head, short index, short data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		return;
	}

	newNode->index = index;
	newNode->data = data;

	if (*head == NULL) {
		newNode->next = newNode;
		newNode->prev = newNode;
		*head = newNode;
		return;
	}

	newNode->prev = (*head)->prev;
	newNode->next = *head;
	(*head)->prev->next = newNode;
	(*head)->prev = newNode;
}

void delete(Node* node) {
	node->prev->next = node->next;
	node->next->prev = node->prev;
	free(node);
}

int main() {
	short N, input;
	Node* head = NULL;

	scanf("%hd", &N);

	for (short i = 1; i <= N; i++) {
		scanf("%hd", &input);
		insert(&head, i, input);
	}

	for (short i = 0; i < N; i++) {
		Node* temp = head;
		short move = head->data;
		head->data = 0;

		if (move > 0) {
			while (move--) {
				if (head->next->data == 0) {
					head = head->next;
				}
				head = head->next;
			}
		}
		else {
			while (move++) {
				if (head->prev->data == 0) {
					head = head->prev;
				}
				head = head->prev;
			}
		}

		printf("%hd ", temp->index);
		delete(temp);
	}

	return 0;
}