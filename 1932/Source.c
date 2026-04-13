#include <stdio.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int triangle[500][500];
int dp[500][500];

int max_sum(int n) {
	dp[0][0] = triangle[0][0];

	for (int i = 1; i < n; i++) {
		dp[i][0] = triangle[i][0] + dp[i - 1][0];
		for (int j = 1; j < i; j++) {
			dp[i][j] = triangle[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
		}
		dp[i][i] = triangle[i][i] + dp[i - 1][i - 1];
	}

	int max = 0;

	for (int i = 0; i < n; i++) {
		if (dp[n - 1][i] > max) {
			max = dp[n - 1][i];
		}
	}

	return max;
}

int main() {
	int N;
	
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			scanf("%d", &triangle[i][j]);
		}
	}

	printf("%d\n", max_sum(N));

	return 0;
}