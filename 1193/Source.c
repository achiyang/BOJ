#include <stdio.h>

int main() {
	int X, count = 1;

	scanf("%d", &X);

	while (X > count) {
		X -= count;
		count++;
	}

	if (count % 2) {
		printf("%d/%d\n", count - X + 1, 1 + X - 1);
	}
	else {
		printf("%d/%d\n", 1 + X - 1, count - X + 1);
	}

	return 0;
}