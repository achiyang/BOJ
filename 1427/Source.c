#include <stdio.h>

int main() {
	int count[10] = { 0 };
	char input;

	while ((input = getchar()) != '\n' && input != EOF) {
		count[input - '0']++;
	}

	for (int i = 9; i >= 0; i--) {
		for (int j = 0; j < count[i]; j++) {
			printf("%d", i);
		}
	}

	return 0;
}