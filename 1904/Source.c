#include <stdio.h>

#define MAX_VALUE 15746

int select_case[1000000];

int select_tiles(int N) {
	select_case[0] = select_case[1] = 1;

	for (int i = 2; i <= N; i++) {
		int value = select_case[i - 1] + select_case[i - 2];
		if (value >= MAX_VALUE) value -= MAX_VALUE;
		select_case[i] = value;
	}

	return select_case[N];
}

int main() {
	int N;

	scanf("%d", &N);

	printf("%d\n", select_tiles(N));

	return 0;
}