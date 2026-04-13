#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

Node* createNode(int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	if (node == NULL) {
		return NULL;
	}

	node->data = data;
	node->next = NULL;

	return node;
}

void appendList(Node** node, int data) {
	Node* newNode = createNode(data);

	if (*node == NULL) {
		*node = newNode;
		return;
	}

	Node* current = *node;
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = newNode;
}

int deleteNodeByIndex(Node** node, int index) {
	Node* current = *node;
	Node* prev = NULL;

	for (int i = 0; i < index; i++) {
		prev = current;
		current = current->next;
	}

	if (prev == NULL){
		*node = current->next;
	}
	else {
		prev->next = current->next;
	}

	int data = current->data;
	free(current);
	return data;
}

void freeList(Node** node) {
	Node* current = *node;
	Node* next;

	while (current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}

	*node = NULL;
}

int main() {
	Node* root = NULL;

	int N, K, index;

	scanf("%d %d", &N, &K);
	index = K - 1;
	for (int i = 1; i <= N; i++) {
		appendList(&root, i);
	}

	printf("<%d", deleteNodeByIndex(&root, index));
	while (--N > 0) {
		index = (index + K - 1) % N;
		printf(", %d", deleteNodeByIndex(&root, index));
	}
	printf(">");

	freeList(&root);

	return 0;
}