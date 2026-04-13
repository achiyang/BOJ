#include <stdio.h>

int max;

void getMax(int N, int M, int cards[], int sum, int index, int depth) {
	if (sum > M) {
		return;
	}

	if (depth == 3) {
		max = max < sum ? sum : max;
		return;
	}

	for (int i = index; i < N - 2 + depth; i++) {
		getMax(N, M, cards, sum + cards[i], i + 1, depth + 1);
	}
}

int main() {
	int N, M, cards[100];

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &cards[i]);
	}

	getMax(N, M, cards, 0, 0, 0);

	printf("%d", max);

	return 0;
}