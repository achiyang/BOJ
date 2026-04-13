#include <stdio.h>

int get_max_sum(int N) {
	int max = -1000, sum = 0, input;

	for (int i = 0; i < N; i++) {
		scanf("%d", &input);

		sum += input;
		if (sum > max) {
			max = sum;
		}
		if (sum < 0) {
			sum = 0;
		}
	}

	return max;
}

int main() {
	int N;

	scanf("%d", &N);

	printf("%d\n", get_max_sum(N));

	return 0;
}