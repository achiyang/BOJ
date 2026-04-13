#include <stdio.h>

int A[10000];
int dp[10000];

int search(int value, int left, int right) {
	int mid = (left + right) / 2;

	if (left == right) {
		return right;
	}

	if (value == dp[mid]) {
		return mid;
	}

	if (value < dp[mid]) {
		return search(value, left, mid);
	}

	if (value > dp[mid]) {
		return search(value, mid + 1, right);
	}
}

int get_max(int n) {
	int dp_length = 0;

	for (int i = 0; i < n; i++) {
		int index = search(A[i], 0, dp_length);

		if (index == dp_length) {
			dp[dp_length++] = A[i];
		}
		else {
			dp[index] = A[i];
		}
	}

	return dp_length;
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