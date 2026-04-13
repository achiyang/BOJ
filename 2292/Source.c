#include <stdio.h>
#include <math.h>

int main() {
	int N, layer = 1, room = 1;

	scanf("%d", &N);

	while (N > room) {
		room += 6 * layer++;
	}

	printf("%d", layer);

	return 0;
}