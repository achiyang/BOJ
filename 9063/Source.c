#include <stdio.h>

int main() {
	int N, x[2] = { 10000, -10000 }, y[2] = { 10000, -10000 };

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int tempX, tempY;

		scanf("%d %d", &tempX, &tempY);

		if (x[0] > tempX) {
			x[0] = tempX;
		}
		if (x[1] < tempX) {
			x[1] = tempX;
		}
		if (y[0] > tempY) {
			y[0] = tempY;
		}
		if (y[1] < tempY) {
			y[1] = tempY;
		}
	}

	printf("%d\n", (x[1] - x[0]) * (y[1] - y[0]));

	return 0;
}