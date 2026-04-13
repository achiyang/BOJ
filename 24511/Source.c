/*원형 이중 연결 리스트를 이용한 Deque 구현*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* prev;
	struct Node* next;
}Node;

void push_back(Node** head, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	newNode->data = data;

	if (*head == NULL) {
		newNode->prev = newNode;
		newNode->next = newNode;
		*head = newNode;
		return;
	}

	newNode->prev = (*head)->prev;
	newNode->next = *head;
	(*head)->prev->next = newNode;
	(*head)->prev = newNode;
}

void push_front(Node** head, int data) {
	push_back(head, data);
	*head = (*head)->prev;
}

int pop_back(Node* head) {
	Node* backNode = head->prev;
	int data = backNode->data;

	backNode->prev->next = head;
	head->prev = backNode->prev;

	free(backNode);

	return data;
}

void freeDeque(Node* node) {
	if (node == NULL) {
		return;
	}

	Node* current = node;
	Node* nextNode;

	do {
		nextNode = current->next;
		free(current);
		current = nextNode;
	} while (current != node);
}

int main() {
	int N, M, input;
	Node* head = NULL;

	scanf("%d", &N);

	int* A = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	for (int i = 0; i < N; i++) {
		if (A[i] == 0) {
			scanf("%d", &input);
			push_back(&head, input);
		}
		else {
			scanf("%*d");
		}
	}

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		scanf("%d", &input);

		if (head == NULL) {
			printf("%d ", input);
		}
		else {
			push_front(&head, input);
			printf("%d ", pop_back(head));
		}
	}

	freeDeque(head);
	free(A);

	return 0;
}