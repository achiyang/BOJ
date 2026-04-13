// nCr = n! / ((n - r)! * r!)
// 메모이제이션을 통해 팩토리얼을 효율적으로 계산
#include <stdio.h>

int f[11];

int factorial(int n) {
	if (n < 2) {
		return 1;
	}

	if (f[n] == 0) {
		f[n] = n * factorial(n - 1);
	}

	return f[n];
}

int main() {
	int N, K;

	scanf("%d %d", &N, &K);

	printf("%d\n", factorial(N) / (factorial(K) * factorial(N - K)));

	return 0;
}