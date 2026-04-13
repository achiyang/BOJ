#include <stdio.h>

int sum[100001];

int main() {
	int N, K, input;

	scanf("%d %d", &N, &K);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &input);
		sum[i] = sum[i - 1] + input;
	}

	int max = -10000000;

	for (int i = 0; i <= N - K; i++) {
		if (max < sum[K + i] - sum[i]) {
			max = sum[K + i] - sum[i];
		}
	}

	printf("%d\n", max);

	return 0;
}