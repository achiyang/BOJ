#include <stdio.h>

int main() {
	int N, M, temp, arr[100][100] = { 0 };

	scanf("%d %d", &N, &M);

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				temp = 0;
				scanf("%d", &temp);
				arr[j][k] += temp;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}