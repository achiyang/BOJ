#include <iostream>
#include <array>
#include <map>
#include <algorithm>

enum RC {
	R,
	C
};

int row_count = 3, col_count = 3;
std::array<std::array<int, 100>, 100> arr{ 0 };

RC checkRC() {
	int row_count = -1, col_count = -1;

	for (int i = 0; i < 100; i++) {
		bool row_empty = true, col_empty = true;
		for (int j = 0; j < 100; j++) {
			if (arr[i][j] != 0) {
				row_empty = false;
			}
			if (arr[j][i] != 0) {
				col_empty = false;
			}
			if (!row_empty && !col_empty) {
				break;
			}
		}
		if (row_count == -1 && row_empty) {
			row_count = i;
		}
		if (col_count == -1 && col_empty) {
			col_count = i;
		}
		if (row_count != -1 && col_count != -1) {
			break;
		}
	}

	if (row_count == -1) {
		row_count = 100;
	}
	if (col_count == -1) {
		col_count = 100;
	}

	::row_count = row_count;
	::col_count = col_count;

	return row_count < col_count ? RC::C : RC::R;
}

void sortArr(RC rc) {
	std::array<int, 101> count{ 0 };

	if (rc == RC::R) {
		for (int i = 0; i < row_count; i++) {
			for (int j = 0; j < col_count; j++) {
				if (arr[i][j] != 0) {
					count[arr[i][j]]++;
					arr[i][j] = 0;
				}
			}
			int idx = 0;
			for (int j = 1; j <= *std::max_element(count.begin(), count.end()); j++) {
				for (int k = 0; k < count.size(); k++) {
					if (count[k] == j) {
						arr[i][idx++] = k;
						arr[i][idx++] = j;
					}
				}
			}
			std::fill(count.begin(), count.end(), 0);
		}
	}

	if (rc == RC::C) {
		for (int i = 0; i < col_count; i++) {
			for (int j = 0; j < row_count; j++) {
				if (arr[j][i] != 0) {
					count[arr[j][i]]++;
					arr[j][i] = 0;
				}
			}
			int idx = 0;
			for (int j = 1; j <= *std::max_element(count.begin(), count.end()); j++) {
				for (int k = 0; k < count.size(); k++) {
					if (count[k] == j) {
						arr[idx++][i] = k;
						arr[idx++][i] = j;
					}
				}
			}
			std::fill(count.begin(), count.end(), 0);
		}
	}
}

int getMin(int r, int c, int j) {
	for (int i = 0; i <= 100; i++) {
		if (arr[r - 1][c - 1] == j) {
			return i;
		}
		sortArr(checkRC());
	}

	return -1;
}

int main() {
	int r, c, k;

	std::cin >> r >> c >> k;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cin >> arr[i][j];
		}
	}

	std::cout << getMin(r, c, k) << std::endl;

	return 0;
}