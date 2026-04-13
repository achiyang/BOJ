#include <stdio.h>

int main() {
	int arr[9][9], maxValue = -1, maxValueRow, maxValueCol;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] > maxValue) {
				maxValue = arr[i][j];
				maxValueRow = i;
				maxValueCol = j;
			}
		}
	}

	printf("%d\n%d %d\n", maxValue, maxValueRow + 1, maxValueCol + 1);

	return 0;
}