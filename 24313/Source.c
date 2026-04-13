#include <stdio.h>

int main() {
	int a[2], c, n;

	scanf("%d %d %d %d", &a[1], &a[0], &c, &n);

	printf("%d\n", a[1] * n + a[0] <= c * n && a[1] <= c);

	return 0;
}