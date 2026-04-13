// 동적 계획법을 사용
// nCr = n-1Cr-1 + n-1Cr
// 파스칼의 삼각형
#include <stdio.h>
#define min(a, b) ((a) < (b) ? (a) : (b))

int dp[11][11];

int binomial(int n, int r) {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= min(i, r); j++) {
			if (j == 0 || j == i) {
				dp[i][j] = 1;
			}
			else {
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			}
		}
	}

	return dp[n][r];
}

int main() {
	int N, K;

	scanf("%d %d", &N, &K);

	printf("%d\n", binomial(N, K));

	return 0;
}