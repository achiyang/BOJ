#include <stdio.h>
#include <stdlib.h>

typedef struct Pos {
	int row;
	int col;
} Pos;

Pos sumPos(Pos a, Pos b) {
	a.row += b.row;
	a.col += b.col;
	return a;
}

int checkValid(Pos pos, int N) {
	if (pos.row >= 0 && pos.row < N &&
		pos.col >= 0 && pos.col < N)
		return 1;
	else
		return 0;
}

typedef struct Shark {
	int size;
	int eat;
	Pos pos;
} Shark;

typedef struct Prey {
	int dis;
	Pos pos;
} Prey;

const Pos dir[4] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

Prey findPrey(int **board, int N, Shark shark) {
	Prey queue[800];
	int front = 0, rear = 0;
	int visited[20][20] = { 0 };

	queue[front++] = (Prey){ .dis = 0, .pos = shark.pos };
	visited[shark.pos.row][shark.pos.col] = 1;
	while (front > rear) {
		Prey curr = queue[rear++];

		if (board[curr.pos.row][curr.pos.col] != 0 &&
			board[curr.pos.row][curr.pos.col] < shark.size) {
			while (front > rear) {
				Prey temp = queue[rear++];

				if (curr.dis < temp.dis) break;

				if (board[temp.pos.row][temp.pos.col] != 0 &&
					board[temp.pos.row][temp.pos.col] < shark.size) {
					if (curr.pos.row > temp.pos.row) {
						curr = temp;
					}
					else if (curr.pos.row == temp.pos.row && curr.pos.col > temp.pos.col) {
						curr = temp;
					}
				}
			}

			return curr;
		}

		for (int i = 0; i < 4; i++) {
			Pos pos = sumPos(curr.pos, dir[i]);

			if (checkValid(pos, N) && !visited[pos.row][pos.col] &&
				board[pos.row][pos.col] <= shark.size) {
				queue[front++] = (Prey){ .dis = curr.dis + 1, .pos = pos };
				visited[pos.row][pos.col] = 1;
			}
		}
	}

	return (Prey){ .dis = -1 };
}

int main() {
	int N, t = 0;
	Shark shark = { .size = 2, .eat = 0 };

	scanf("%d", &N);

	int **board = (int **)malloc(sizeof(int *) * N);
	if (board == NULL) exit(EXIT_FAILURE);

	for (int i = 0; i < N; i++) {
		board[i] = (int *)malloc(sizeof(int) * N);
		if (board[i] == NULL) exit(EXIT_FAILURE);

		for (int j = 0; j < N; j++) {
			scanf("%d", &board[i][j]);

			if (board[i][j] == 9) {
				shark.pos.row = i;
				shark.pos.col = j;
				board[i][j] = 0;
			}
		}
	}

	while (1) {
		Prey prey = findPrey(board, N, shark);
		if (prey.dis == -1)
			break;

		t += prey.dis;
		board[prey.pos.row][prey.pos.col] = 0;
		shark.pos = prey.pos;
		if (++shark.eat == shark.size) {
			shark.eat = 0;
			shark.size++;
		}
	}

	printf("%d", t);

	for (int i = 0; i < N; i++) {
		free(board[i]);
	}
	free(board);

	return 0;
}
