#include <stdio.h>
#include <math.h>

int count;
int board[14] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };

void N_Queen(int N, int depth) {
	if (depth == N) {
		count++;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (board[i] == -1) {
			int is_unattackable = 1;

			for (int j = 0; j < N; j++) {
				if (board[j] != -1 && abs(i - j) == abs(depth - board[j])) {
					is_unattackable = 0;
					break;
				}
			}

			if (is_unattackable) {
				board[i] = depth;
				N_Queen(N, depth + 1);
				board[i] = -1;
			}
		}
	}
}

int main() {
	int N;

	scanf("%d", &N);

	N_Queen(N, 0);

	printf("%d\n", count);

	return 0;
}