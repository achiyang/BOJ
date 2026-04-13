#include <stdio.h>
#include <string.h>

char board[2187 * 2188];

void stamp(int p, int N, int n) {
	int one_third = n / 3;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1);
			else if (n == 3) {
				board[p + (N + 1) * i + j] = '*';
			}
			else {
				stamp(p + (N + 1) * i * one_third + one_third * j, N, one_third);
			}
		}
	}
}

int main() {
	int N;

	scanf("%d", &N);

	memset(board, ' ', N * (N + 1) - 1);

	for (int i = 0; i < N - 1; i++) {
		board[(N + 1) * i + N] = '\n';
	}

	stamp(0, N, N);

	printf("%s", board);

	return 0;
}