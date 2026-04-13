#include <stdio.h>

int frontIndex;
int backIndex;
int queue[2000000];

void push(int data) {
	queue[backIndex++] = data;
}

int size() {
	return backIndex - frontIndex;
}

int empty() {
	return size() == 0;
}

int pop() {
	return empty() ? -1 : queue[frontIndex++];
}

int front() {
	return empty() ? -1 : queue[frontIndex];
}

int back() {
	return empty() ? -1 : queue[backIndex - 1];
}

int main() {
	int N, input;
	char command[6];

	scanf("%d", &N);

	while (N--) {
		scanf("%s", command);

		switch (command[0])
		{
		case 'p':
			if (command[1] == 'u') {
				scanf("%d", &input);
				push(input);
			}
			else if (command[1] == 'o') {
				printf("%d\n", pop());
			}
			break;
		case 's':
			printf("%d\n", size());
			break;
		case 'e':
			printf("%d\n", empty());
			break;
		case 'f':
			printf("%d\n", front());
			break;
		case 'b':
			printf("%d\n", back());
			break;
		}
	}

	return 0;
}