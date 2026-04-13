#include <stdio.h>

int gcd(int a, int b) {
	int temp;
	while (b) {
		temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int main() {
	int N = 1, arr[100000] = { 0 }, gcd_ = 0, temp;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		if (i) {
			temp = arr[i] - arr[i - 1];
			if (gcd_ == 0) {
				gcd_ = temp;
			}
			else if (gcd_ != 1) {
				gcd_ = gcd(gcd_, temp);
			}
		}
	}

	printf("%d\n", (arr[N - 1] - arr[0]) / gcd_ - N + 1);

	return 0;
}