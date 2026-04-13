#include <stdio.h>
#include <math.h>

int main() {
	int N;

	scanf("%d", &N);

	printf("%d", (int)pow(pow(2, N) + 1, 2));

	return 0;
}