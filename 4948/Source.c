#include <stdio.h>

int main() {
	int isPrime[246913];
	isPrime[0] = isPrime[1] = 0;
	for (int i = 2; i < 246913; i++) {
		isPrime[i] = 1;
	}

	for (int i = 2; i * i <= 246912; i++) {
		if (isPrime[i]) {
			for (int j = i * i; j <= 246912; j += i) {
				isPrime[j] = 0;
			}
		}
	}

	int input;
	while (1) {
		scanf("%d", &input);
		if (input == 0) {
			break;
		}

		if (input < 3) {
			printf("1\n");
			continue;
		}

		int count = 0;
		for (int i = (input + 1) % 2 == 0 ? input + 2 : input + 1; i <= input * 2; i += 2) {
			if (isPrime[i]) {
				count++;
			}
		}
		printf("%d\n", count);
	}

	return 0;
}