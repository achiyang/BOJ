#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>

struct Pos {
	int row;
	int col;

	bool operator<(const Pos& other) const {
		if (row != other.row) {
			return row < other.row;
		}
		return col < other.col;
	}

	bool operator==(const Pos& other) const {
		return row == other.row && col == other.col;
	}
};

struct Snake {
	Pos head;
	int dir;
	std::deque<Pos> body;
};

const int drow[4] = { -1, 0, 1, 0 };
const int dcol[4] = { 0, 1, 0, -1 };

int main() {
	int N, K;

	std::cin >> N >> K;

	std::vector<std::vector<bool>> apples(N, std::vector<bool>(N, 0));

	for (int i = 0; i < K; i++) {
		int row, col;
		std::cin >> row >> col;
		apples[row - 1][col - 1] = 1;
	}

	Snake snake = { { 0, 0 }, 1, };
	snake.body.push_back(snake.head);

	int L;

	std::cin >> L;

	std::map<int, int> rotation;

	for (int i = 0; i < L; i++) {
		int sec;
		char rotation_dir;
		std::cin >> sec >> rotation_dir;
		rotation[sec] = rotation_dir == 'D' ? 1 : -1;
	}

	int count = 1;
	while (true) {
		int head_row = snake.head.row + drow[snake.dir];
		int head_col = snake.head.col + dcol[snake.dir];

		if (head_row < 0 || head_row >= N || head_col < 0 || head_col >= N ||
			std::find(snake.body.begin(), snake.body.end(), Pos{ head_row, head_col }) != snake.body.end()) {
			break;
		}

		snake.head = { head_row, head_col };
		snake.body.push_back(snake.head);

		if (apples[head_row][head_col] == 0) {
			snake.body.pop_front();
		}
		else {
			apples[head_row][head_col] = 0;
		}

		if (rotation.find(count) != rotation.end()) {
			snake.dir = (snake.dir + rotation[count] + 4) % 4;
		}

		count++;
	}

	std::cout << count << std::endl;

	return 0;
}