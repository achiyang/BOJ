#include <stdio.h>

int main() {
	int N, count = 0;

	scanf("%d", &N);

	while (N % 5 != 0 && N >= 3) {
		N -= 3;
		count++;
	}

	if (N % 5 == 0) {
		printf("%d\n", N / 5 + count);
	}
	else {
		printf("-1");
	}

	return 0;
}