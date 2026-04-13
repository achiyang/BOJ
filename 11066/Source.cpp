#include <iostream>
#include <algorithm>
#include <climits>

int main() {
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	int T;

	std::cin >> T;
	while (T--) {
		int K;
		int sum[501] = { 0 };
		int dp[501][501] = { 0 };

		std::cin >> K;
		for (int i = 1; i <= K; i++) {
			int input;

			std::cin >> input;
			sum[i] = sum[i - 1] + input;
		}

		for (int i = 1; i < K; i++) {
			for (int x = 1; x <= K - i; x++) {
				int y = x + i;
				dp[x][y] = INT_MAX;

				for (int mid = x; mid < y; mid++) {
					dp[x][y] = std::min(dp[x][y], dp[x][mid] + dp[mid + 1][y] + sum[y] - sum[x - 1]);
				}
			}
		}

		std::cout << dp[1][K] << '\n';
	}

	return 0;
}