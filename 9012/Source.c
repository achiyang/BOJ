#include <stdio.h>

int main() {
	int T;
	char input[51];

	scanf("%d", &T);

	while (T--) {
		int stack = 0;
		scanf("%s", input);
		for (int i = 0; input[i] != '\0'; i++) {
			if (input[i] == '(') {
				stack++;
			}
			else {
				stack--;
				if (stack < 0) {
					break;
				}
			}
		}
		if (stack == 0) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}

	return 0;
}