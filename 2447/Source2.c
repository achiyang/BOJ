#include <stdio.h>
#include <string.h>

char board[2187 * 2188];

void stamp(int p, int N, int n) {
	if (n == 3) {
		memset(&board[p], '*', 3);
		memcpy(&board[p + (N + 1)], "* *", 3);
		memset(&board[p + (N + 1) * 2], '*', 3);
		return;
	}
	if (n == 9) {
		memset(&board[p], '*', 9);
		memcpy(&board[p + (N + 1)], "* ** ** *", 9);
		memset(&board[p + (N + 1) * 2], '*', 9);
		memcpy(&board[p + (N + 1) * 3], "***   ***", 9);
		memcpy(&board[p + (N + 1) * 4], "* *   * *", 9);
		memcpy(&board[p + (N + 1) * 5], "***   ***", 9);
		memset(&board[p + (N + 1) * 6], '*', 9);
		memcpy(&board[p + (N + 1) * 7], "* ** ** *", 9);
		memset(&board[p + (N + 1) * 8], '*', 9);
		return;
	}
	if (n == 27) {
		memset(&board[p], '*', 27);
		memcpy(&board[p + (N + 1)], "* ** ** ** ** ** ** ** ** *", 27);
		memset(&board[p + (N + 1) * 2], '*', 27);
		memcpy(&board[p + (N + 1) * 3], "***   ******   ******   ***", 27);
		memcpy(&board[p + (N + 1) * 4], "* *   * ** *   * ** *   * *", 27);
		memcpy(&board[p + (N + 1) * 5], "***   ******   ******   ***", 27);
		memset(&board[p + (N + 1) * 6], '*', 27);
		memcpy(&board[p + (N + 1) * 7], "* ** ** ** ** ** ** ** ** *", 27);
		memset(&board[p + (N + 1) * 8], '*', 27);
		memcpy(&board[p + (N + 1) * 9], "*********         *********", 27);
		memcpy(&board[p + (N + 1) * 10], "* ** ** *         * ** ** *", 27);
		memcpy(&board[p + (N + 1) * 11], "*********         *********", 27);
		memcpy(&board[p + (N + 1) * 12], "***   ***         ***   ***", 27);
		memcpy(&board[p + (N + 1) * 13], "* *   * *         * *   * *", 27);
		memcpy(&board[p + (N + 1) * 14], "***   ***         ***   ***", 27);
		memcpy(&board[p + (N + 1) * 15], "*********         *********", 27);
		memcpy(&board[p + (N + 1) * 16], "* ** ** *         * ** ** *", 27);
		memcpy(&board[p + (N + 1) * 17], "*********         *********", 27);
		memset(&board[p + (N + 1) * 18], '*', 27);
		memcpy(&board[p + (N + 1) * 19], "* ** ** ** ** ** ** ** ** *", 27);
		memset(&board[p + (N + 1) * 20], '*', 27);
		memcpy(&board[p + (N + 1) * 21], "***   ******   ******   ***", 27);
		memcpy(&board[p + (N + 1) * 22], "* *   * ** *   * ** *   * *", 27);
		memcpy(&board[p + (N + 1) * 23], "***   ******   ******   ***", 27);
		memset(&board[p + (N + 1) * 24], '*', 27);
		memcpy(&board[p + (N + 1) * 25], "* ** ** ** ** ** ** ** ** *", 27);
		memset(&board[p + (N + 1) * 26], '*', 27);
		return;
	}

	int one_third = n / 3;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i != 1 || j != 1) {
				stamp(p + (N + 1) * i * one_third + one_third * j, N, one_third);
			}
			else {
				for (int k = 0; k < one_third; k++) {
					memset(&board[p + (N + 1) * (one_third + k) + one_third], ' ', one_third);
				}
			}
		}
	}
}

int main() {
	int N = 0;

	scanf("%d", &N);

	for (int i = 0; i < N - 1; i++) {
		board[(N + 1) * i + N] = '\n';
	}

	stamp(0, N, N);

	printf("%s", board);

	return 0;
}