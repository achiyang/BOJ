#include <stdio.h>

int main() {
	int N, input, min = 1000000, max = 2;

	scanf("%d", &N);

	while (N--) {
		scanf("%d", &input);

		if (input < min) {
			min = input;
		}
		if (input > max) {
			max = input;
		}
	}

	printf("%d", min * max);

	return 0;
}