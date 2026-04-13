#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
	if (*(int*)a > *(int*)b) {
		return 1;
	}
	else if (*(int*)a < *(int*)b) {
		return -1;
	}
	else {
		return 0;
	}
}

int* find(int* arr, int begin, int end, int value) {
	while (begin < end) {
		int mid = (begin + end) / 2;

		if (arr[mid] == value) {
			return arr + mid;
		}

		if (arr[mid] > value) {
			end = mid;
		}
		else {
			begin = mid + 1;
		}
	}

	return NULL;
}

int main() {
	int N, M;

	scanf("%d", &N);
	int* A = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	qsort(A, N, sizeof(int), compare);

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int input;
		scanf("%d", &input);

		printf("%d\n", find(A, 0, N, input) ? 1 : 0);
	}

    free(A);
	return 0;
}