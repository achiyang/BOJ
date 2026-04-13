#include <stdio.h>

const int dr[] = { 0, 1, 0, -1 };
const int dc[] = { 1, 0, -1, 0 };

int board[50][50];
int rows, cols, time;
int cleaner;

void spread() {
	int temp[50][50] = { 0 };

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (board[i][j] >= 5) {
				int n = board[i][j] / 5;

				for (int k = 0; k < 4; k++) {
					int nr = i + dr[k];
					int nc = j + dc[k];

					if (nr >= 0 && nr < rows &&
						nc >= 0 && nc < cols &&
						board[nr][nc] != -1) {
						temp[nr][nc] += n;
						board[i][j] -= n;
					}
				}
			}
		}
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			board[i][j] += temp[i][j];
		}
	}
}

void circulation() {
	for (int i = cleaner - 1; i > 0; i--) {
		board[i][0] = board[i - 1][0];
	}
	for (int i = 0; i < cols - 1; i++) {
		board[0][i] = board[0][i + 1];
	}
	for (int i = 0; i < cleaner; i++) {
		board[i][cols - 1] = board[i + 1][cols - 1];
	}
	for (int i = cols - 1; i > 1; i--) {
		board[cleaner][i] = board[cleaner][i - 1];
	}
	board[cleaner][1] = 0;

	for (int i = cleaner + 2; i < rows - 1; i++) {
		board[i][0] = board[i + 1][0];
	}
	for (int i = 0; i < cols - 1; i++) {
		board[rows - 1][i] = board[rows - 1][i + 1];
	}
	for (int i = rows - 1; i > cleaner + 1; i--) {
		board[i][cols - 1] = board[i - 1][cols - 1];
	}
	for (int i = cols - 1; i > 1; i--) {
		board[cleaner + 1][i] = board[cleaner + 1][i - 1];
	}
	board[cleaner + 1][1] = 0;
}

int main() {
	scanf("%d %d %d", &rows, &cols, &time);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			scanf("%d", &board[i][j]);
			if (cleaner == 0 && j == 0 && board[i][j] == -1) {
				cleaner = i;
			}
		}
	}

	for (int i = 0; i < time; i++) {
		spread();
		circulation();
	}

	int result = 0;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (board[i][j] != -1) {
				result += board[i][j];
			}
		}
	}

	printf("%d", result);

	return 0;
}
