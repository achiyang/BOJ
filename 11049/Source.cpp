#include <iostream>
#include <algorithm>
#include <climits>

int matrices[500][2];
int dp[500][500];

int main() {
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int N;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> matrices[i][0] >> matrices[i][1];
	}

	for (int term = 1; term < N; term++) {
		for (int start = 0; start + term < N; start++) {
			dp[start][start + term] = INT_MAX;

			for (int t = start; t < start + term; t++) {
				dp[start][start + term] = std::min(dp[start][start + term], dp[start][t] + dp[t + 1][start + term] + matrices[start][0] * matrices[t][1] * matrices[start + term][1]);
			}
		}
	}

	std::cout << dp[0][N - 1];

	return 0;
}