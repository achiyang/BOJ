#include <iostream>

int wCount, bCount;
int arr[128 * 128];

void count(int p, int n, int N) {
	bool b = true;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[p + N * i + j] != arr[p]) {
				b = false;
				break;
			}
		}
		if (!b) {
			break;
		}
	}

	if (b) {
		if (arr[p] == 1) {
			++bCount;
		}
		else {
			++wCount;
		}
		return;
	}

	int half = n / 2;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			count(p + N * half * i + half * j, half, N);
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;

	std::cin >> N;

	for (int i = 0; i < N * N; i++) {
		std::cin >> arr[i];
	}

	count(0, N, N);

	std::cout << wCount << '\n' << bCount;

	return 0;
}