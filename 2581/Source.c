#include <stdio.h>

int main() {
	int M, N, minPrime = 0, sumPrime = 0;
	int notPrime[10001] = { 1, 1 };

	for (int i = 2; i <= 100; i++) {
		if (!notPrime[i]) {
			for (int j = i + i; j <= 10000; j += i) {
				notPrime[j] = 1;
			}
		}
	}

	scanf("%d %d", &M, &N);

	for (int i = M; i <= N; i++) {
		if (!notPrime[i]) {
			if (minPrime == 0) {
				minPrime = i;
			}
			sumPrime += i;
		}
	}

	if (minPrime) {
		printf("%d\n%d\n", sumPrime, minPrime);
	}
	else {
		printf("-1\n");
	}

	return 0;
}