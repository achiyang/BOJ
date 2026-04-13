#include <stdio.h>

int w[101];
int p[101];
int dp[101][100001];

int max(int a, int b) {
	return a > b ? a : b;
}

int knapsack(int n, int W) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= W; j++) {
			if (j - w[i] >= 0) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + p[i]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	return dp[n][W];
}

int main() {
	int N, K;

	scanf("%d %d", &N, &K);

	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &w[i], &p[i]);
	}

	printf("%d\n", knapsack(N, K));

	return 0;
}