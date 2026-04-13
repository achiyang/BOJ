#include <stdio.h>

int min(int a, int b) {
	return a < b ? a : b;
}

int main() {
	int minValue = 1000, x, y, w, h;

	scanf("%d %d %d %d", &x, &y, &w, &h);

	minValue = min(minValue, x);
	minValue = min(minValue, y);
	minValue = min(minValue, w - x);
	minValue = min(minValue, h - y);

	printf("%d\n", minValue);

	return 0;
}