#include <stdio.h>

int sum[100001];

int main() {
	int N, M, input;

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &input);
		sum[i] = sum[i - 1] + input;
	}


	for (int i = 0; i < M; i++) {
		int start, end;
		scanf("%d %d", &start, &end);
		printf("%d\n", sum[end] - sum[start - 1]);
	}

	return 0;
}