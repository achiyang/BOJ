#include <stdio.h>

int A[1000];
int dp[1000];
int r_dp[1000];

int get_max(int n) {
	int max = 1;

	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		int biggest = 0;

		for (int j = 0; j < i; j++) {
			if (A[i] > A[j] && biggest < dp[j]) {
				biggest = dp[j];
			}
		}

		dp[i] = biggest + 1;
	}

	r_dp[n - 1] = 1;
	for (int i = n - 2; i >= 0; i--) {
		int biggest = 0;

		for (int j = n - 1; j > i; j--) {
			if (A[i] > A[j] && biggest < r_dp[j]) {
				biggest = r_dp[j];
			}
		}

		r_dp[i] = biggest + 1;
	}

	for (int i = 0; i < n; i++) {
		if (max < dp[i] + r_dp[i]) {
			max = dp[i] + r_dp[i];
		}
	}

	return max - 1;
}

int main() {
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	printf("%d\n", get_max(N));

	return 0;
}