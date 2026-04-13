#include <cstdio>
#include <vector>

const int MAX = 1000000;

int main() {
	std::vector<long long> sum_divisor(MAX + 1, 0);

	for (int i = 1; i <= MAX; i++) {
		for (int j = 1; i * j <= MAX; j++) {
			sum_divisor[i * j] += i;
		}
		sum_divisor[i] += sum_divisor[i - 1];
	}

	int T, N;

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		printf("%lld\n", sum_divisor[N]);
	}

	return 0;
}