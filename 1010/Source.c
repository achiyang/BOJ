#include <stdio.h>

int dp[31][31];

int nCr(int n, int r) {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= (i < r ? i : r); j++) {
			if (dp[i][j] == 0) {
				if (j == 0 || j == i) {
					dp[i][j] = 1;
				}
				else {
					dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
				}
			}
		}
	}

	return dp[n][r];
}

int main() {
	int T, N, M;

	scanf("%d", &T);

	while (T--) {
		scanf("%d %d", &N, &M);
		printf("%d\n", nCr(M, N));
	}

	return 0;
}