#include <stdio.h>
#include <stdlib.h>

int count;
int K;
int arr[500000];
int temp[500000];

void merge(int* A, int start, int mid, int end) {
	int i = start, j = mid + 1, t = 0;

	while (i <= mid && j <= end) {
		if (A[i] <= A[j]) {
			temp[t++] = A[i++];
		}
		else {
			temp[t++] = A[j++];
		}
	}

	while (i <= mid) {
		temp[t++] = A[i++];
	}
	while (j <= end) {
		temp[t++] = A[j++];
	}

	i = start, t = 0;
	while (i <= end) {
		if (++count == K) {
			printf("%d\n", temp[t]);
			exit(EXIT_SUCCESS);
		}
		A[i++] = temp[t++];
	}
}

void merge_sort(int* A, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		merge_sort(A, start, mid);
		merge_sort(A, mid + 1, end);
		merge(A, start, mid, end);
	}
}

int main() {
	int N;

	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	merge_sort(arr, 0, N - 1);

	printf("-1\n");

	return 0;
}