#include <stdio.h>

int main() {
	int num1 = 1, num2 = 1;

	while (1) {
		scanf("%d %d", &num1, &num2);
		if (!num1 && !num2) {
			break;
		}

		if (num2 % num1 == 0) {
			printf("factor\n");
		}
		else if (num1 % num2 == 0) {
			printf("multiple\n");
		}
		else {
			printf("neither\n");
		}
	}

	return 0;
}