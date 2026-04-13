#include <iostream>
#include <vector>
#include <cstdlib>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, M, input, max = 0;

	std::cin >> N;
	std::vector<int> W(N);

	for (int i = 0; i < N; i++) {
		std::cin >> W[i];
		max += W[i];
	}

	std::vector<bool> dp(40001);
	dp[0] = true;
	for (int i = 0; i < N; i++) {
		for (int j = max; j >= 0; j--) {
			if (dp[j]) {
				dp[j + W[i]] = true;
			}
		}
		for (int j = 0; j <= max; j++) {
			if (dp[j]) {
				dp[std::abs(j - W[i])] = true;
			}
		}
	}

	std::cin >> M;
	for (int i = 0; i < M; i++) {
		std::cin >> input;
		if (dp[input]) {
			std::cout << "Y ";
		}
		else {
			std::cout << "N ";
		}
	}

	return 0;
}