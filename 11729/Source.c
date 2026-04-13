#include <stdio.h>

int pow_2(int n) {
	if (n == 0) {
		return 1;
	}

	return 2 * pow_2(n - 1);
}

void hanoi(int N, int start, int via, int to) {
	if (N == 0) {
		return;
	}

	hanoi(N - 1, start, to, via);
	printf("%d %d\n", start, to);
	hanoi(N - 1, via, start, to);
}

int main() {
	int N;

	scanf("%d", &N);

	printf("%d\n", pow_2(N) - 1);

	hanoi(N, 1, 2, 3);

	return 0;
}