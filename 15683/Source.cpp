#include <iostream>
#include <vector>
#include <algorithm>

int N, M, min = 64;
int board[8][8] = { 0 };
std::vector<std::pair<int, int>> cctv;
std::vector<std::pair<int, int>> monitor;

const int drow[4] = { -1, 0, 1, 0 };
const int dcol[4] = { 0, 1, 0, -1 };

int countBlindArea() {
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 0) {
				count++;
			}
		}
	}
	return count;
}

int push_monitor(int dir, int row, int col) {
	int count = 0;

	row += drow[dir];
	col += dcol[dir];

	while (row >= 0 && row < N && col >= 0 && col < M) {
		if (board[row][col] == 6) {
			break;
		}
		if (board[row][col] == 0) {
			board[row][col] = -1;
			monitor.push_back({ row, col });
			count++;
		}
		row += drow[dir];
		col += dcol[dir];
	}
	return count;
}

void pop_monitor(int count) {
	for (int i = 0; i < count; i++) {
		board[monitor.back().first][monitor.back().second] = 0;
		monitor.pop_back();
	}
}

void getMinBlindArea(int depth) {
	if (depth == cctv.size()) {
		min = std::min(min, countBlindArea());
		return;
	}

	int row = cctv[depth].first;
	int col = cctv[depth].second;
	int push_count;

	if (board[row][col] == 1) {
		for (int i = 0; i < 4; i++) {
			push_count = 0;
			push_count += push_monitor(i, row, col);
			getMinBlindArea(depth + 1);
			pop_monitor(push_count);
		}
	}
	else if (board[row][col] == 2) {
		for (int i = 0; i < 2; i++) {
			push_count = 0;
			push_count += push_monitor(i, row, col);
			push_count += push_monitor(i + 2, row, col);
			getMinBlindArea(depth + 1);
			pop_monitor(push_count);
		}
	}
	else if (board[row][col] == 3) {
		for (int i = 0; i < 4; i++) {
			push_count = 0;
			push_count += push_monitor(i, row, col);
			push_count += push_monitor((i + 1) % 4, row, col);
			getMinBlindArea(depth + 1);
			pop_monitor(push_count);
		}
	}
	else if (board[row][col] == 4) {
		for (int i = 0; i < 4; i++) {
			push_count = 0;
			for (int j = 0; j < 4; j++) {
				if (i == j) {
					continue;
				}
				push_count += push_monitor(j, row, col);
			}
			getMinBlindArea(depth + 1);
			pop_monitor(push_count);
		}
	}
}

void cctv_5(int dir, int row, int col) {
	row += drow[dir];
	col += dcol[dir];

	while (row >= 0 && row < N && col >= 0 && col < M) {
		if (board[row][col] == 6) {
			break;
		}
		if (board[row][col] == 0) {
			board[row][col] = -1;
		}
		row += drow[dir];
		col += dcol[dir];
	}
}

int main() {
	std::cin >> N >> M;

	int input;
			
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			std::cin >> input;
			board[i][j] = input;
			if (input >= 1 && input <= 4) {
				cctv.push_back({ i,j });
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 5) {
				for (int k = 0; k < 4; k++) {
					cctv_5(k, i, j);
				}
			}
		}
	}

	getMinBlindArea(0);

	std::cout << min << std::endl;

	return 0;
}