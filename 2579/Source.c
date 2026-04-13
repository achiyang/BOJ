#include <stdio.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int stair[300];
int dp[300][2];	// dp[][0] : 1칸 아래의 계단에서 올라온 경우, dp[][1] : 2칸 아래의 계단에서 올라온 경우

int get_max(int n) {
	dp[0][0] = stair[0] + 0;	// dp[i][0] = stair[i] + dp[i - 1][1];
	dp[0][1] = stair[0] + 0;	// dp[i][1] = stair[i] + max(dp[i - 2][0], dp[i - 2][1]);

	dp[1][0] = stair[1] + dp[0][1];	// dp[i][0] = stair[i] + dp[i - 1][1];
	dp[1][1] = stair[1] + 0;		// dp[i][1] = stair[i] + max(dp[i - 2][0], dp[i - 2][1]);

	for (int i = 2; i < n; i++) {
		dp[i][0] = stair[i] + dp[i - 1][1];
		dp[i][1] = stair[i] + max(dp[i - 2][0], dp[i - 2][1]);
	}

	return max(dp[n - 1][0], dp[n - 1][1]);
}

int main() {
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &stair[i]);
	}

	printf("%d\n", get_max(N));

	return 0;
}