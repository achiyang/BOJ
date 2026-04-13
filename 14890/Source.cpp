#include <iostream>
#include <vector>
#include <cmath>

bool width(std::vector<std::vector<int>>& grid, int row, int size, int ramp) {
	std::vector<bool> is_ramp(size, false);

	int pos = 0;

	while (pos < size - 1) {
		if (std::abs(grid[row][pos] - grid[row][pos + 1]) > 1) {
			return false;
		}

		if (grid[row][pos] == grid[row][pos + 1]) {
			pos++;
		}
		else if (grid[row][pos] - grid[row][pos + 1] == 1) {
			if (size - pos > ramp) {
				for (int i = 1; i <= ramp; i++) {
					if (grid[row][pos] - 1 != grid[row][pos + i]) {
						return false;
					}
					is_ramp[pos + i] = true;
				}
				pos += ramp;
			}
			else {
				return false;
			}
		}
		else if (grid[row][pos + 1] - grid[row][pos] == 1) {
			if (pos < ramp - 1) {
				return false;
			}
			for (int i = 0; i < ramp; i++) {
				if (grid[row][pos] != grid[row][pos - i] || is_ramp[pos - i]) {
					return false;
				}
			}
			pos++;
		}
	}

	return true;
}

bool length(std::vector<std::vector<int>>& grid, int col, int size, int ramp) {
	std::vector<bool> is_ramp(size, false);

	int pos = 0;

	while (pos < size - 1) {
		if (std::abs(grid[pos][col] - grid[pos + 1][col]) > 1) {
			return false;
		}

		if (grid[pos][col] == grid[pos + 1][col]) {
			pos++;
		}
		else if (grid[pos][col] - grid[pos + 1][col] == 1) {
			if (size - pos > ramp) {
				for (int i = 1; i <= ramp; i++) {
					if (grid[pos][col] - 1 != grid[pos + i][col]) {
						return false;
					}
					is_ramp[pos + i] = true;
				}
				pos += ramp;
			}
			else {
				return false;
			}
		}
		else if (grid[pos + 1][col] - grid[pos][col] == 1) {
			if (pos < ramp - 1) {
				return false;
			}
			for (int i = 0; i < ramp; i++) {
				if (grid[pos][col] != grid[pos - i][col] || is_ramp[pos - i]) {
					return false;
				}
			}
			pos++;
		}
	}

	return true;
}

int main() {
	int N, L;

	std::cin >> N >> L;

	std::vector<std::vector<int>> grid(N, std::vector<int>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> grid[i][j];
		}
	}

	int count = 0;

	for (int i = 0; i < N; i++) {
		if (width(grid, i, N, L)) {
			count++;
		}
		if (length(grid, i, N, L)) {
			count++;
		}
	}

	std::cout << count << std::endl;

	return 0;
}