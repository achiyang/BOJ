/*배열을 이용한 Deque 구현*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100001

int front;
int back;
int D[MAX_SIZE];

void push_back(int data) {
	D[back++] = data;
	if (back >= MAX_SIZE) {
		back -= MAX_SIZE;
	}
}

void push_front(int data) {
	if (--front < 0) {
		front += MAX_SIZE;
	}
	D[front] = data;
}

int pop_back() {
	if (--back < 0) {
		back += MAX_SIZE;
	}
	return D[back];
}

int main() {
	int N, M, input;

	scanf("%d", &N);

	int* A = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	for (int i = 0; i < N; i++) {
		if (A[i] == 0) {
			scanf("%d", &input);
			push_back(input);
		}
		else {
			scanf("%*d");
		}
	}

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		scanf("%d", &input);

		if (front == back) {
			printf("%d ", input);
		}
		else {
			push_front(input);
			printf("%d ", pop_back());
		}
	}

	free(A);

	return 0;
}