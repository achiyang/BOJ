#include <stdio.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int cost[1000][3];
int dp[1000][3];

int min_cost(int n) {
	dp[0][0] = cost[0][0];
	dp[0][1] = cost[0][1];
	dp[0][2] = cost[0][2];

	for (int i = 1; i < n; i++) {
		dp[i][0] = cost[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = cost[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = cost[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
	}

	return min(min(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]);
}

int main() {
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
	}

	printf("%d\n", min_cost(N));

	return 0;
}