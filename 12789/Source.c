#include <stdio.h>

int top = -1;
int stack[1000];

int main() {
	int N, input, waiting = 1;

	scanf("%d", &N);

	while (N--) {
		scanf("%d", &input);

		if (waiting == input) {
			waiting++;
		}
		else {
			if (top < 0) {
				stack[++top] = input;
			}
			else if (stack[top] > input) {
				stack[++top] = input;
			}
			else {
				printf("Sad\n");
				return 0;
			}
		}

		while (top >= 0 && waiting == stack[top]) {
			waiting++;
			top--;
		}
	}

	printf("Nice\n");

	return 0;
}