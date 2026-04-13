#include <stdio.h>

int main() {
	int input, arr[100001] = { 0 };

	for (int i = 1; i <= 50000; i++) {
		for (int j = i * 2; j <= 100001; j += i) {
			arr[j] += i;
		}
	}

	while (1) {
		scanf("%d", &input);

		if (input < 0) {
			return 0;
		}

		printf("%d ", input);
		if (arr[input] == input) {
			printf("= 1");
			for (int i = 2; i <= input / 2; i++) {
				if (input % i == 0) {
					printf(" + %d", i);
				}
			}
			printf("\n");
		}
		else {
			printf("is NOT perfect.\n");
		}
	}
}