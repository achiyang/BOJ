#include <stdio.h>

#define MAX_SIZE 14 * 14

struct Pos {
	int row;
	int col;
};

typedef struct {
	struct Pos data[MAX_SIZE];
	int top;
}Stack;

Stack stack;
int board[14][14];
int N;

void initialize() {
	stack.top = -1;
}

void push(struct Pos* pos) {
	stack.data[++stack.top] = *pos;
}

struct Pos pop() {
	return stack.data[stack.top--];
}

int insertQueen(struct Pos* pos) {
	int count = 0;
	struct Pos temp;

	board[(*pos).row][(*pos).col] = 1;

	for (int i = 0; i < N; i++) {
		if (i != (*pos).row && board[i][(*pos).col] == 0) {
			board[i][(*pos).col] = -1;
			temp.row = i;
			temp.col = (*pos).col;
			push(&temp);
			count++;
		}
		if (i != (*pos).col && board[(*pos).row][i] == 0) {
			board[(*pos).row][i] = -1;
			temp.row = (*pos).row;
			temp.col = i;
			push(&temp);
			count++;
		}
	}

	for (int i = 1; (*pos).row + i < N && (*pos).col + i < N; i++) {
		if (board[(*pos).row + i][(*pos).col + i] == 0) {
			board[(*pos).row + i][(*pos).col + i] = -1;
			temp.row = (*pos).row + i;
			temp.col = (*pos).col + i;
			push(&temp);
			count++;
		}
	}
	for (int i = 1; (*pos).row + i < N && (*pos).col - i >= 0; i++) {
		if (board[(*pos).row + i][(*pos).col - i] == 0) {
			board[(*pos).row + i][(*pos).col - i] = -1;
			temp.row = (*pos).row + i;
			temp.col = (*pos).col - i;
			push(&temp);
			count++;
		}
	}
	for (int i = 1; (*pos).row - i >= 0 && (*pos).col + i < N; i++) {
		if (board[(*pos).row - i][(*pos).col + i] == 0) {
			board[(*pos).row - i][(*pos).col + i] = -1;
			temp.row = (*pos).row - i;
			temp.col = (*pos).col + i;
			push(&temp);
			count++;
		}
	}
	for (int i = 1; (*pos).row - i >= 0 && (*pos).col - i >= 0; i++) {
		if (board[(*pos).row - i][(*pos).col - i] == 0) {
			board[(*pos).row - i][(*pos).col - i] = -1;
			temp.row = (*pos).row - i;
			temp.col = (*pos).col - i;
			push(&temp);
			count++;
		}
	}

	return count;
}

void popQueen(struct Pos* pos, int count) {
	board[(*pos).row][(*pos).col] = 0;

	for (int i = 0; i < count; i++) {
		struct Pos temp = pop();
		board[temp.row][temp.col] = 0;
	}
}

int caseCount;
void N_Queen(int N, int depth) {
	if (depth == N) {
		caseCount++;
		return;
	}

	struct Pos temp = { depth, 0 };

	for (int i = 0; i < N; i++) {
		if (board[depth][i] == 0) {
			temp.col = i;
			int count = insertQueen(&temp);
			N_Queen(N, depth + 1);
			popQueen(&temp, count);
		}
	}
}

int main() {
	scanf("%d", &N);

	N_Queen(N, 0);

	printf("%d\n", caseCount);

	return 0;
}