#include <iostream>
#include <vector>

int N, M;

std::vector<std::vector<int>> board;

int dice[6] = { 0 };
std::pair<int, int> dice_pos;

void roll_dice(int dir) {
	if (dir == 1) {
		if (dice_pos.second + 1 >= M) {
			return;
		}
		int temp = dice[0];
		dice[0] = dice[2];
		dice[2] = dice[5];
		dice[5] = dice[3];
		dice[3] = temp;

		dice_pos.second++;
	}
	else if (dir == 2) {
		if (dice_pos.second - 1 < 0) {
			return;
		}
		int temp = dice[0];
		dice[0] = dice[3];
		dice[3] = dice[5];
		dice[5] = dice[2];
		dice[2] = temp;

		dice_pos.second--;
	}
	else if (dir == 3) {
		if (dice_pos.first - 1 < 0) {
			return;
		}
		int temp = dice[0];
		dice[0] = dice[1];
		dice[1] = dice[5];
		dice[5] = dice[4];
		dice[4] = temp;

		dice_pos.first--;
	}
	else if (dir == 4) {
		if (dice_pos.first + 1 >= N) {
			return;
		}
		int temp = dice[0];
		dice[0] = dice[4];
		dice[4] = dice[5];
		dice[5] = dice[1];
		dice[1] = temp;

		dice_pos.first++;
	}
	else {
		return;
	}

	if (board[dice_pos.first][dice_pos.second] == 0) {
		board[dice_pos.first][dice_pos.second] = dice[0];
	}
	else {
		dice[0] = board[dice_pos.first][dice_pos.second];
		board[dice_pos.first][dice_pos.second] = 0;
	}
	std::cout << dice[5] << std::endl;
}

int main() {
	int x, y, K;

	std::cin >> N >> M >> x >> y >> K;

	board.resize(N, std::vector<int>(M));

	dice_pos = { x, y };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			std::cin >> board[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		int dir;
		std::cin >> dir;
		roll_dice(dir);
	}

	return 0;
}