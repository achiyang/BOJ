#include <iostream>

int count[3];
short arr[2187][2187];
short memo[729][729];

void f(int r, int c, int n) {
	if (n == 1 || (n == 3 && memo[r / 3][c / 3] != -1)) {
		count[arr[r][c] + 1]++;
		return;
	}

	bool b = true;

	for (int i = 0; i < n / 3; i++) {
		for (int j = 0; j < n / 3; j++) {
			if (memo[r / 3 + i][c / 3 + j] == -1 || memo[r / 3][c / 3] != memo[r / 3 + i][c / 3 + j]) {
				b = false;
				break;
			}
		}
		if (!b) {
			break;
		}
	}

	if (b) {
		count[arr[r][c] + 1]++;
	}
	else {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				f(r + n / 3 * i, c + n / 3 * j, n / 3);
			}
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N / 3; i++) {
		for (int j = 0; j < N / 3; j++) {
			bool b = true;

			for (int k = 0; k < 3; k++) {
				for (int l = 0; l < 3; l++) {
					if (arr[i * 3][j * 3] != arr[i * 3 + k][j * 3 + l]) {
						b = false;
						break;
					}
				}
				if (!b) {
					break;
				}
			}

			if (b) {
				memo[i][j] = arr[i * 3][j * 3] + 1;
			}
			else {
				memo[i][j] = -1;
			}
		}
	}

	f(0, 0, N);

	std::cout << count[0] << '\n' << count[1] << '\n' << count[2];

	return 0;
}