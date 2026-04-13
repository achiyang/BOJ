#include <stdio.h>

int power[13] = { 1 };

int pow_3(int n) {
	if (power[n] != 0) {
		return power[n];
	}

	power[n] = 3 * pow_3(n - 1);
	return power[n];
}

void print_cantor(int N) {
	if (N == 0) {
		printf("-");
		return;
	}

	print_cantor(N - 1);
	for (int i = 0; i < pow_3(N - 1); i++) {
		printf(" ");
	}
	print_cantor(N - 1);
}

void cantor(int N) {
	print_cantor(N);
	printf("\n");
}

int main() {
	int N;

	while (scanf("%d", &N) == 1) {
		cantor(N);
	}

	return 0;
}