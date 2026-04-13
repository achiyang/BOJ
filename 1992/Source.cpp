#include <iostream>

char arr[64 * 64];

void quadTree(int p, int n, int N) {
	bool compressible = true;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[p + N * i + j] != arr[p]) {
				compressible = false;
				break;
			}
		}
		if (!compressible) {
			break;
		}
	}

	if (compressible) {
		std::cout << arr[p];
	}
	else {
		std::cout << '(';

		int half = n / 2;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				quadTree(p + N * half * i + half * j, half, N);
			}
		}

		std::cout << ')';
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

	quadTree(0, N, N);

	return 0;
}