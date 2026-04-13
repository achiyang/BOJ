#include <stdio.h>
#include <stdlib.h>

static int func(int a, int b) {
	int ret = 1;

	a %= 10;

	while (b) {
		if (b & 1) {
			ret = (ret * a) % 10;
		}
		a = (a * a) % 10;
		b >>= 1;
	}

	return ret ? ret : 10;
}

int main() {
	int t, a, b;

	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf("%d %d", &a, &b);

		printf("%d\n", func(a, b));
	}

	return 0;
}
