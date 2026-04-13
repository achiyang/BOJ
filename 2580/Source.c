#include <stdio.h>
#include <stdlib.h>

int board[9][9];
int row[9][9];
int col[9][9];
int sub[9][9];
int empty[81][2];

void sudoku(int empty_count, int depth) {
	if (depth == empty_count) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				printf("%d ", board[i][j]);
			}
			printf("\n");
		}

		exit(EXIT_SUCCESS);
	}

	int sub_index = empty[depth][0] / 3 * 3 + empty[depth][1] / 3;

	for (int i = 0; i < 9; i++) {
		if (row[empty[depth][0]][i] == 0 && col[empty[depth][1]][i] == 0 && sub[sub_index][i] == 0) {

			row[empty[depth][0]][i] = 1;
			col[empty[depth][1]][i] = 1;
			sub[sub_index][i] = 1;
			board[empty[depth][0]][empty[depth][1]] = i + 1;

			sudoku(empty_count, depth + 1);

			row[empty[depth][0]][i] = 0;
			col[empty[depth][1]][i] = 0;
			sub[sub_index][i] = 0;
			board[empty[depth][0]][empty[depth][1]] = 0;
		}
	}
}

int main() {
	int index = 0;

	for (int i = 0; i < 9; i++) {
		int sub_index = i / 3 * 3;

		for (int j = 0; j < 9; j++) {
			scanf("%d", &board[i][j]);

			if (board[i][j] != 0) {
				row[i][board[i][j] - 1] = 1;
				col[j][board[i][j] - 1] = 1;
				sub[sub_index + j / 3][board[i][j] - 1] = 1;
			}
			else {
				empty[index][0] = i;
				empty[index++][1] = j;
			}
		}
	}

	sudoku(index, 0);

	return 0;
}