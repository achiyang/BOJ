#include <stdio.h>
#include <stdlib.h>

int main() {
	int N, arr[10001] = { 0 };

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int input;
		scanf("%d", &input);
		arr[input]++;
	}

	for (int i = 1; i < 10001; i++) {
		if (arr[i]) {
			for (int j = 0; j < arr[i]; j++) {
				printf("%d\n", i);
			}
		}
	}

	return 0;
}