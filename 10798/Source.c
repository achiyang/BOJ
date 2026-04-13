#include <stdio.h>

int main() {
	int max_len = 0;
	char strarr[5][16] = { 0 };

	for (int i = 0; i < 5; i++) {
		scanf("%s", strarr[i]);
	}

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 5; j++) {
			if (strarr[j][i] != 0) {
				printf("%c", strarr[j][i]);
			}
		}
	}

	return 0;
}