#include <stdio.h>
#include <stdlib.h>

int main() {
	int T, Tcase, Q, D, N, P;

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d", &Tcase);

		Q = Tcase / 25;
		Tcase -= Q * 25;

		D = Tcase / 10;
		Tcase -= D * 10;

		N = Tcase / 5;
		Tcase -= N * 5;

		P = Tcase;

		printf("%d %d %d %d\n", Q, D, N, P);
	}

	return 0;
}