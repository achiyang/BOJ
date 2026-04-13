#include <stdio.h>

int arr[8];

void dfs(int N, int M, int depth) {
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", arr[i] + 1);
		}
		printf("\n");
		return;
	}

	for (int i = 0; i < N; i++) {
		int is_used = 0;

		for (int j = 0; j < depth; j++) {
			if (arr[j] == i) {
				is_used = 1;
				break;
			}
		}

		if (!is_used) {
			arr[depth] = i;
			dfs(N, M, depth + 1);
		}
	}
}

int main() {
	int N, M;

	scanf("%d %d", &N, &M);

	dfs(N, M, 0);

	return 0;
}