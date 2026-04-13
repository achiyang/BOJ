#include <stdio.h>

int main() {
	int A, B, V;

	scanf("%d %d %d", &A, &B, &V);

	printf("%d\n", (V - A) / (A - B) + ((V - A) % (A - B) ? 1 : 0) + 1);

	return 0;
}