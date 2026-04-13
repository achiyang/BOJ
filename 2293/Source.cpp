#include <iostream>
#include <vector>

int dp[10001];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, k;

	std::cin >> n >> k;
	std::vector<int> coins(n + 1);
	for (int i = 1; i < n + 1; i++) {
		std::cin >> coins[i];
	}

	dp[0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = coins[i]; j <= k; j++) {
			dp[j] += dp[j - coins[i]];
		}
	}

	std::cout << dp[k];

	return 0;
}