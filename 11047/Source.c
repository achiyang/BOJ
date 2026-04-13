#include <stdio.h>

int main() {
	int N, K, count = 0;
	int coins[10];

	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++) {
		scanf("%d", &coins[i]);
	}

	for (int i = N - 1; K != 0; i--) {
		count += K / coins[i];
		K %= coins[i];
	}

	printf("%d\n", count);

	return 0;
}