#include <iostream>

int sum[2001][2001];
const int MAX_VALUE = 2000000;

inline int MIN(int a, int b) {
	return a < b ? a : b;
}

int main() {
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	int N, M, K;
	char line[2001];

	std::cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		std::cin >> line;
		for (int j = 1; j <= M; j++) {
			char c = (i + j) % 2 ? 'W' : 'B';
			sum[i][j] = (line[j - 1] == c ? 1 : 0) + sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
		}
	}

	int min = MAX_VALUE;
	for (int i = K; i <= N; i++) {
		for (int j = K; j <= M; j++) {
			int a = sum[i][j] - sum[i][j - K] - sum[i - K][j] + sum[i - K][j - K];
			int b = K * K - a;
			min = MIN(min, MIN(a, b));
		}
	}

	std::cout << min;

	return 0;
}