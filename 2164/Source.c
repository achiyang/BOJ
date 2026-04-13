#include <stdio.h>
#define MAX_SIZE 500000

int cards[MAX_SIZE];

int main() {
	int N, front = 0, back;

	scanf("%d", &N);
	back = N;
	for (int i = 0; i < N; i++) {
		cards[i] = i + 1;
	}

	while (back - front > 1) {
		cards[back++ % MAX_SIZE] = cards[(front + 1) % MAX_SIZE];
		front += 2;
	}

	printf("%d\n", cards[front % MAX_SIZE]);

	return 0;
}