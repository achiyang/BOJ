#include <stdio.h>

int main() {
	int count = 0, N, K;

	scanf("%d %d", &N, &K);

	for (int i = 1; i <= N; i++) {
		if (N % i == 0) {
			count++;
		}
		if (count == K) {
			printf("%d\n", i);
			return 0;
		}
	}

	printf("0\n");
	return 0;
}