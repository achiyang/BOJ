#include <stdio.h>

int main() {
	int primes[70001], prime[6935], index = 0;
	primes[0] = primes[1] = 0;
	for (int i = 2; i < 70001; i++) {
		primes[i] = 1;
	}

	for (int i = 2; i * i <= 70000; i++) {
		if (primes[i]) {
			for (int j = i * i; j < 70001; j += i) {
				primes[j] = 0;
			}
		}
	}

	for (int i = 2; i < 70001; i++) {
		if (primes[i]) {
			prime[index++] = i;
		}
	}

	long long N;
	long long input;

	scanf("%lld", &N);
	for (long long k = 0; k < N; k++) {
		scanf("%lld", &input);
		for (long long i = input > 2 && input % 2 == 0 ? input + 1 : input;; i += 2) {
			if (i <= 69997) {
				i = i == 0 || i == 1 ? 2 : i;
				for (int j = i;; j += 2) {
					if (primes[j]) {
						printf("%d\n", j);
						break;
					}
				}
				break;
			}
			int isPrime = 1;
			for (int j = 0; (long long)prime[j] * prime[j] <= i; j++) {
				if (i % prime[j] == 0) {
					isPrime = 0;
					break;
				}
			}
			if (isPrime) {
				printf("%lld\n", i);
				break;
			}
		}
	}

	return 0;
}