#include <stdio.h>

int main() {
	int leg[3];

	for (int i = 0; i < 3; i++) {
		scanf("%d", &leg[i]);
	}

	for (int i = 0; i < 2; i++) {
		for (int j = i + 1; j < 3; j++) {
			if (leg[i] > leg[j]) {
				int temp = leg[i];
				leg[i] = leg[j];
				leg[j] = temp;
			}
		}
	}

	printf("%d", leg[0] + leg[1] > leg[2] ? leg[0] + leg[1] + leg[2] : (leg[0] + leg[1]) * 2 - 1);

	return 0;
}