#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stringSet {
	char* string;
	int length;
	struct stringSet* left;
	struct stringSet* right;
}stringSet;

int compareStringSet(stringSet* a, char* b) {
	int lengthComparison = a->length - strlen(b);
	if (lengthComparison != 0) {
		return lengthComparison;
	}
	return memcmp(a->string, b, a->length);
}

stringSet* createStringSet(char* data) {
	stringSet* node = (stringSet*)malloc(sizeof(stringSet));
	if (node == NULL) {
		return NULL;
	}
	node->length = strlen(data);
	node->string = (char*)malloc(sizeof(char) * (node->length + 1));
	if (node->string == NULL) {
		free(node);
		return NULL;
	}
	strcpy(node->string, data);
	node->left = node->right = NULL;
	return node;
}

void destroyStringSet(stringSet* node) {
	if (node == NULL) {
		return;
	}
	destroyStringSet(node->left);
	destroyStringSet(node->right);
	free(node->string);
	free(node);
}

stringSet* insertStringSet(stringSet* node, char* data) {
	if (node == NULL) {
		node = createStringSet(data);
		return node;
	}

	if (compareStringSet(node, data) > 0) {
		node->left = insertStringSet(node->left, data);
	}
	else if (compareStringSet(node, data) < 0) {
		node->right = insertStringSet(node->right, data);
	}

	return node;
}

void printStringSet(stringSet* node) {
	if (node == NULL) {
		return;
	}
	printStringSet(node->left);
	printf("%s\n", node->string);
	printStringSet(node->right);
}

int main() {
	int N;

	scanf("%d", &N);

	stringSet* root = NULL;
	for (int i = 0; i < N; i++) {
		char temp[51];
		scanf("%s", temp);
		root = insertStringSet(root, temp);
	}

	printStringSet(root);
	destroyStringSet(root);

	return 0;
}