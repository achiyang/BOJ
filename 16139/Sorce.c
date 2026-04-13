#include <stdio.h>
#include <string.h>

int count[200001][26];

int main() {
	int q;
	char c;

	for (int i = 1; (c = getchar()) != '\n'; i++) {
		memcpy(count[i], count[i - 1], sizeof(int) * 26);
		count[i][c - 'a']++;
	}

	scanf("%d", &q);

	for (int i = 0; i < q; i++) {
		int start, end;

		scanf(" %c %d %d", &c, &start, &end);
		printf("%d\n", count[end + 1][c - 'a'] - count[start][c - 'a']);
	}

	return 0;
}