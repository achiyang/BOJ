#include <stdio.h>

int index = 3;
long long n[100] = { 1, 1, 1 };

long long f(int N) {
	if (N > index) {
		for (int i = index; i < N; i++) {
			n[i] = n[i - 2] + n[i - 3];
		}
		index = N;
	}

	return n[N - 1];
}

int main() {
	int N, input;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &input);
		printf("%lld\n", f(input));
	}

	return 0;
}