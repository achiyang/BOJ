#include <stdio.h>
#include <stdlib.h>

int sort(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

int main() {
	int leg[3];

	while (1) {
		for (int i = 0; i < 3; i++) {
			scanf("%d", &leg[i]);
		}

		if (leg[0] + leg[1] + leg[2] == 0) {
			break;
		}

		qsort(leg, 3, sizeof(int), sort);

		if (leg[0] + leg[1] <= leg[2]) {
			printf("Invalid\n");
		}
		else {
			if (leg[0] != leg[1] && leg[0] != leg[2] && leg[1] != leg[2]) {
				printf("Scalene\n");
			}
			else if (leg[0] == leg[1] && leg[1] == leg[2]) {
				printf("Equilateral\n");
			}
			else {
				printf("Isosceles\n");
			}
		}
	}

	return 0;
}