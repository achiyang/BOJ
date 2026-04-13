#include <stdio.h>

int main() {
	int N, count = 0;

	scanf("%d", &N);

	for (int i = 666;; i++) {
		int temp = i;
		while (temp >= 666) {
			if (temp % 1000 == 666) {
				count++;
				break;
			}
			temp /= 10;
		}

		if (count == N) {
			printf("%d\n", i);
			break;
		}
	}

	return 0;
}