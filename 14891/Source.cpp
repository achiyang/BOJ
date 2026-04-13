#include <iostream>
#include <vector>
#include <string>

void move_gear(std::vector<std::vector<int>>& gear, int gear_index, int direction, int rl) {
	if (rl != 1 && gear_index > 0) {
		if (gear[gear_index][6] != gear[gear_index - 1][2]) {
			move_gear(gear, gear_index - 1, -direction, -1);
		}
	}
	if (rl != -1 && gear_index < 3) {
		if (gear[gear_index][2] != gear[gear_index + 1][6]) {
			move_gear(gear, gear_index + 1, -direction, 1);
		}
	}

	std::vector<int> temp = gear[gear_index];
	for (int i = 0; i < 8; i++) {
		gear[gear_index][(i + direction + 8) % 8] = temp[i];
	}
	return;
}

int main() {
	std::vector<std::vector<int>> gear(4, std::vector<int>(8));

	for (int i = 0; i < 4; i++) {
		std::string input;
		std::cin >> input;

		for (int j = 0; j < 8; j++) {
			gear[i][j] = (input[j] - '0');
		}
	}

	int K;

	std::cin >> K;

	int gear_index, direction;

	for (int i = 0; i < K; i++) {
		std::cin >> gear_index >> direction;
		move_gear(gear, gear_index - 1, direction, 0);
	}

	int point = 0;

	for (int i = 0; i < 4; i++) {
		point += gear[i][0] * (1 << i);
	}

	std::cout << point << std::endl;

	return 0;
}