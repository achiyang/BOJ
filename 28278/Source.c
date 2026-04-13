#include <stdio.h>

int top = -1;
unsigned int stack[1000000];

void push(int data) {
	stack[++top] = data;
}

int isEmpty() {
	return top < 0;
}

int size() {
	return top + 1;
}

int pop() {
	return isEmpty() ? -1 : stack[top--];
}

int top_() {
	return isEmpty() ? -1 : stack[top];
}

int main() {
	int N, input;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &input);
		switch (input) {
		case 1:
			scanf("%d", &input);
			push(input);
			break;
		case 2:
			printf("%d\n", pop());
			break;
		case 3:
			printf("%d\n", size());
			break;
		case 4:
			printf("%d\n", isEmpty());
			break;
		case 5:
			printf("%d\n", top_());
			break;
		}
	}

	return 0;
}