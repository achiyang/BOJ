#include <stdio.h>

#define MAX_VALUE 1000000000

int memo[100][10];

int stair_num(int n) {
	for (int i = 1; i <= 9; i++) {
		memo[0][i] = 1;
	}

	for (int i = 1; i < n; i++) {
		memo[i][0] = memo[i - 1][1];
		for (int j = 1; j < 9; j++) {
			memo[i][j] = (memo[i - 1][j - 1] + memo[i - 1][j + 1]) % MAX_VALUE;
		}
		memo[i][9] = memo[i - 1][8];
	}

	int sum = 0;
	for (int i = 0; i < 10; i++) {
		sum = (sum + memo[n - 1][i]) % MAX_VALUE;
	}

	return sum;
}

int main() {
	int N;

	scanf("%d", &N);

	printf("%d\n", stair_num(N));

	return 0;
}