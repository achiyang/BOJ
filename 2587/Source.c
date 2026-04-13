#include <stdio.h>

int main() {
	int arr[5] = { 0 }, avg = 0;

	for (int i = 0; i < 5; i++) {
		int input;
		scanf("%d", &input);
		for (int j = 0; j < 5; j++) {
			if (arr[j] < input) {
				for (int k = 4; k > j; k--) {
					arr[k] = arr[k - 1];
				}
				arr[j] = input;
				break;
			}
		}
		avg += input;
	}
	avg /= 5;

	printf("%d\n%d\n", avg, arr[2]);

	return 0;
}