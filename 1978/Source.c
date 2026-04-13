#include <stdio.h>
#include <stdlib.h>

int main() {
	int N, input, notPrime[1001] = { 1, 1 }, count = 0;

	for (int i = 2; i * i <= 1000; i++) {
		if (!notPrime[i]) {
			for (int j = i + i; j <= 1000; j += i) {
				notPrime[j] = 1;
			}
		}
	}

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &input);

		if (!notPrime[input]) {
			count++;
		}
	}

	printf("%d\n", count);

	return 0;
}