#include <stdio.h>
#include <stdlib.h>

static int dolmen(int a, int b) {
	return (int)((long long)(a + b - 1) * (a + b) * (a + b) / 2);
}

int main() {
	int t, a, b;

	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", dolmen(a, b));
	}

	return 0;
}
