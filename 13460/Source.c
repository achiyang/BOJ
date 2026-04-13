#include <stdio.h>

typedef struct {
	int row;
	int col;
} Point;

const Point dir[] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int board[10][10];
int min = -1;

int equal(Point a, Point b) {
	return a.row == b.row && a.col == b.col;
}

void dfs(int depth, Point r, Point b) {
	if ((depth > 10) || (min != -1 && depth >= min)) {
		return;
	}

	for (int i = 0; i < 4; i++) {
		Point red = r;
		Point blue = b;

		while (1) {
			Point nr = { red.row + dir[i].row, red.col + dir[i].col };
			Point nb = { blue.row + dir[i].row, blue.col + dir[i].col };

			int moved = 0;

			if (board[nr.row][nr.col] != -1 && !equal(nr, blue)) {
				red = nr;
				moved = 1;
			}
			if (board[nb.row][nb.col] != -1 && !equal(nb, red)) {
				blue = nb;
				moved = 1;
			}

			if (moved) {
				if (board[blue.row][blue.col] == 1) {
					break;
				}
				if (board[red.row][red.col] == 1) {
					while (1) {
						nb = (Point){ blue.row + dir[i].row, blue.col + dir[i].col };

						if (board[nb.row][nb.col] != -1) {
							blue = nb;

							if (board[blue.row][blue.col] == 1) {
								break;
							}
						}
						else {
							break;
						}
					}
					break;
				}
			}
			else {
				break;
			}
		}

		if (!(equal(red, r) && equal(blue, b))) {
			if (board[blue.row][blue.col] != 1) {
				if (board[red.row][red.col] == 1) {
					min = depth;
					return;
				}
				else {
					dfs(depth + 1, red, blue);
				}
			}
		}
	}
}

int main() {
	int N, M;
	Point red, blue;

	scanf("%d %d ", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			switch (getchar()) {
			case '.':
				break;
			case '#':
				board[i][j] = -1;
				break;
			case 'O':
				board[i][j] = 1;
				break;
			case 'R':
				red.row = i;
				red.col = j;
				break;
			case 'B':
				blue.row = i;
				blue.col = j;
				break;
			}
		}
		getchar();
	}

	dfs(1, red, blue);

	printf("%d", min);

	return 0;
}
