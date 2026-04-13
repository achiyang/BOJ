#include <stdio.h>

int connection[500];
int dp[500];

int search(int value, int left, int right) {
	int mid = (left + right) / 2;

	if (left == right) {
		return right;
	}

	if (value == dp[mid]) {
		return mid;
	}

	if (value > dp[mid]) {
		return search(value, mid + 1, right);
	}

	if (value < dp[mid]) {
		return search(value, left, mid);
	}
}

int f(int n) {
	int dp_length = 0;

	for (int i = 0, count = 0; count < n; i++) {
		if (connection[i]) {
			int index = search(connection[i], 0, dp_length);

			if (index == dp_length) {
				dp[dp_length++] = connection[i];
			}
			else {
				dp[index] = connection[i];
			}

			count++;
		}
	}

	return n - dp_length;
}

int main() {
	int N, A, B;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &A, &B);
		connection[A - 1] = B;
	}

	printf("%d\n", f(N));

	return 0;
}