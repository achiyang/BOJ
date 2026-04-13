#include <iostream>
#include <vector>
#include <algorithm>

int max = 0;
int N, M;

std::vector<std::vector<int>> board;
std::vector<std::pair<int, int>> tetromino;

const int drow[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dcol[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

void dfs(int depth) {
	if (depth == 3) {
		int count = 0;
		for (int i = 0; i < 4; i++) {
			count += board[tetromino[i].first][tetromino[i].second];
		}
		max = std::max(max, count);
		return;
	}

	for (int i = 0; i < 8; i++) {
		int row = tetromino.back().first + drow[i];
		int col = tetromino.back().second + dcol[i];
		if (row >= 0 && row < N && col >= 0 && col < M &&
			std::find(tetromino.begin(), tetromino.end(), std::make_pair(row, col)) == tetromino.end() &&
			(std::find(tetromino.begin(), tetromino.end(), std::make_pair(row + 1, col)) != tetromino.end() ||
			std::find(tetromino.begin(), tetromino.end(), std::make_pair(row - 1, col)) != tetromino.end() ||
			std::find(tetromino.begin(), tetromino.end(), std::make_pair(row, col + 1)) != tetromino.end() ||
			std::find(tetromino.begin(), tetromino.end(), std::make_pair(row, col - 1)) != tetromino.end())) {
			tetromino.push_back({ row, col });
			dfs(depth + 1);
			tetromino.pop_back();
		}
	}
}

int main() {
	std::cin >> N >> M;

	board.resize(N, std::vector<int>(M));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			std::cin >> board[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			tetromino.push_back({ i, j });
			dfs(0);
			tetromino.pop_back();
		}
	}

	std::cout << max << std::endl;

	return 0;
}