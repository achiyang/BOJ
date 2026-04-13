#include <iostream>

int board[500][500];
int dp[500][500];
int M, N;

const int dRow[4] = { 0, 1, 0, -1 };
const int dCol[4] = { 1, 0, -1, 0 };

int DFS(int row, int col) {
	if (row == M - 1 && col == N - 1) return 1;
	if (dp[row][col] != -1) return dp[row][col];

	dp[row][col] = 0;
	for (int i = 0; i < 4; i++) {
		int newRow = row + dRow[i];
		int newCol = col + dCol[i];
		if (newRow >= 0 && newRow < M && newCol >= 0 && newCol < N) {
			if (board[newRow][newCol] < board[row][col]) {
				dp[row][col] += DFS(newRow, newCol);
			}
		}
	}
	return dp[row][col];
}

int main() {
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	std::cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> board[i][j];
			dp[i][j] = -1;
		}
	}

	std::cout << DFS(0, 0);

	return 0;
}