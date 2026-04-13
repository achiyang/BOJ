#include <stdio.h>

int main() {
	int N, constructor = 0, ten = 10, count = 1;

	scanf("%d", &N);

	while (N / ten) {
		count++;
		ten *= 10;
	}

	for (int i = N - count * 9 <= 1 ? 1 : N - count * 9; i <= N - count; i++) {
		int temp = i, sum = i;
		while (temp) {
			sum += temp % 10;
			temp /= 10;
		}
		if (sum == N) {
			constructor = i;
			break;
		}
	}

	printf("%d\n", constructor);

	return 0;
}