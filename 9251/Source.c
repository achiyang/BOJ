#include <stdio.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

char A[1001];
char B[1001];
int dp[1001][1001];

int LCS() {
	int longgest = 0;
	int A_len = strlen(A);
	int B_len = strlen(B);

	for (int i = 0; i < A_len; i++) {
		for (int j = 0; j < B_len; j++) {
			if (A[i] == B[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;

				longgest = max(dp[i + 1][j + 1], longgest);
			}
			else {
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
			}
		}
	}

	return longgest;
}

int main() {
	scanf("%s %s", A, B);

	printf("%d\n", LCS());

	return 0;
}