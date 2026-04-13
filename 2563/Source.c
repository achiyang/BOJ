#include <stdio.h>

int main() {
	int N, count = 0;
	int board[100][100] = { 0 };

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int col, row;
		scanf("%d %d", &col, &row);
		for (int i = row; i < row + 10; i++) {
			for (int j = col; j < col + 10; j++) {
				if (board[i][j] == 0) {
					board[i][j] = 1;
				}
			}
		}
	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (board[i][j]) {
				count++;
			}
		}
	}

	printf("%d", count);

	return 0;
}