#include <stdio.h>

int main() {
	int top, is_balance;
	char input[101], stack[100];

	while (scanf("%[^.]s", input) == 1) {
		int c;
		while ((c = getchar()) != '\n' && c != EOF);

		top = -1;
		is_balance = 1;
		for (int i = 0; input[i] != '\0'; i++) {
			if (input[i] == '(' || input[i] == '[') {
				stack[++top] = input[i];
			}
			else if (input[i] == ')' || input[i] == ']') {
				if (top < 0) {
					is_balance = 0;
					break;
				}
				if (stack[top] != (input[i] == ')' ? '(' : '[')) {
					is_balance = 0;
					break;
				}
				top--;
			}
		}

		if (is_balance && top == -1) {
			printf("yes\n");
		}
		else {
			printf("no\n");
		}
	}
}