#include <stdio.h>

int main() {
	int N, M, min = 1250;
	char board[50][50];

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %c", &board[i][j]);
		}
	}

	for (int r = 0; r < N - 7; r++) {
		for (int c = 0; c < M - 7; c++) {
			for (int i = 0; i < 2; i++) {
				int count = 0;
				for (int j = 0; j < 8; j++) {
					for (int k = 0; k < 8; k++) {
						if (board[j + r][k + c] != ((i + j + k) % 2 ? 'B' : 'W')) {
							count++;
						}
					}
				}
				min = min > count ? count : min;
			}
		}
	}

	printf("%d\n", min);

	return 0;
}