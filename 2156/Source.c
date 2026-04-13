#include <stdio.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int wine[10000];
int dp[10000];

int get_max(int n) {
	dp[0] = wine[0];
	dp[1] = wine[1] + wine[0];
	dp[2] = max(max(wine[2] + dp[0], wine[2] + wine[1]), dp[1]);

	for (int i = 3; i < n; i++) {
		dp[i] = max(max(wine[i] + dp[i - 2], wine[i] + wine[i - 1] + dp[i - 3]), dp[i - 1]);
	}

	return dp[n - 1];
}

int main() {
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &wine[i]);
	}

	printf("%d\n", get_max(N));

	return 0;
}