#include <stdio.h>

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void quickSort(int* arr, int width) {
	int index = 0;
	for (int i = 1; i < width; i++) {
		if (arr[0] > arr[i]) {
			swap(arr + index + 1, arr + i);
			index++;
		}
	}
	swap(arr, arr + index);
	if (index > 1) {
		quickSort(arr, index);
	}
	if (width - index > 2) {
		quickSort(arr + index + 1, width - index - 1);
	}
}

int main() {
	int N, k, arr[1000];

	scanf("%d %d", &N, &k);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	quickSort(arr, N);

	printf("%d\n", arr[N - k]);

	return 0;
}