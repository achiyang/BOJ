#include <stdio.h>
#include <string.h>

int main() {
	char N[31];
	int B, decimal = 0, power = 1;

	scanf("%s %d", N, &B);

	int len = strlen(N);
	for (int i = len - 1; i >= 0; i--) {
		int value = N[i] >= '0' && N[i] <= '9' ? N[i] - '0' : N[i] - 'A' + 10;
		decimal += value * power;
		power *= B;
	}

	printf("%d", decimal);

	return 0;
}