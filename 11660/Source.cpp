#include <iostream>

int sum[1025][1025];

int main() {
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	int N, M, input;

	std::cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			std::cin >> input;
			sum[i][j] = input + sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
		}
	}

	for (int i = 0; i < M; i++) {
		int x1, y1, x2, y2;

		std::cin >> x1 >> y1 >> x2 >> y2;
		std::cout << sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1] << '\n';
	}

	return 0;
}