#include <stdio.h>
#include <string.h>

const char table[36] = {
	'0', '1', '2', '3', '4', '5',
	'6', '7', '8', '9', 'A', 'B',
	'C', 'D', 'E', 'F', 'G', 'H',
	'I', 'J', 'K', 'L', 'M', 'N',
	'O', 'P', 'Q', 'R', 'S', 'T',
	'U', 'V', 'W', 'X', 'Y', 'Z'
};

int main() {
	int N, B, index = 0;
	char converted[31];

	scanf("%d %d", &N, &B);

	while (N) {
		converted[index++] = table[N % B];
		N /= B;
	}

	for (int i = index - 1; i >= 0; i--) {
		printf("%c", converted[i]);
	}

	return 0;
}