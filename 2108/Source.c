#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int arr[500000];
int frequency[8001];

int sort(int* a, int* b) {
	return (*a) - (*b);
}

int main() {
	int N, sum = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);

		sum += arr[i];
		frequency[arr[i] + 4000]++;
	}

	printf("%d\n", (int)round((double)sum / N));

	qsort(arr, N, sizeof(int), sort);

	printf("%d\n", arr[N / 2]);

	int mode[2] = { -1, -1 };
	int findsecond = 0;
	for (int i = 0; i <= 8000; i++) {
		if (frequency[i] > mode[1]) {
			mode[0] = i;
			mode[1] = frequency[i];
			findsecond = 0;
		}
		else if (frequency[i] == mode[1] && findsecond == 0) {
			mode[0] = i;
			mode[1] = frequency[i];
			findsecond = 1;
		}
	}

	printf("%d\n", mode[0] - 4000);

	printf("%d\n", arr[N - 1] - arr[0]);

	return 0;
}