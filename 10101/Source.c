#include <stdio.h>

int main() {
	int angle[3];

	for (int i = 0; i < 3; i++) {
		scanf("%d", &angle[i]);
	}

	if (angle[0] + angle[1] + angle[2] != 180) {
		printf("Error\n");
	}
	else {
		if (angle[0] != angle[1] && angle[0] != angle[2] && angle[1] != angle[2]) {
			printf("Scalene\n");
		}
		else if (angle[0] == 60) {
			printf("Equilateral\n");
		}
		else {
			printf("Isosceles\n");
		}
	}

	return 0;
}