#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
	return *((int*)a) - *((int*)b);
}

int main() {
	int N, P[1000];

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &P[i]);
	}

	qsort(P, N, sizeof(int), compare);

	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += P[i] * (N - i);
	}

	printf("%d\n", sum);

	return 0;
}