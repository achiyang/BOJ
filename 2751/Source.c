#include <stdio.h>
#include <stdlib.h>

int main() {
	int N;
	int* arr = (int*)calloc(2000001, sizeof(int));

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int input;
		scanf("%d", &input);
		arr[input + 1000000]++;
	}

	for (int i = 0; i < 2000001; i++) {
		if (arr[i]) {
			for (int j = 0; j < arr[i]; j++) {
				printf("%d\n", i - 1000000);
			}
		}
	}

    free(arr);

	return 0;
}