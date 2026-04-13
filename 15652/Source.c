#include <stdio.h>

int arr[8];

void dfs(int N, int M, int start, int depth) {
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", arr[i] + 1);
		}
		printf("\n");
		return;
	}

	for (int i = start; i < N; i++) {
		arr[depth] = i;
		dfs(N, M, i, depth + 1);
	}
}

int main() {
	int N, M;

	scanf("%d %d", &N, &M);

	dfs(N, M, 0, 0);

	return 0;
}