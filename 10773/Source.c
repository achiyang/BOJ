#include <stdio.h>

int top = -1;
int stack[100000];

int main() {
	int K, input, sum = 0;

	scanf("%d", &K);

	for (int i = 0; i < K; i++) {
		scanf("%d", &input);
		if (input) {
			stack[++top] = input;
		}
		else {
			top--;
		}
	}

	for (int i = 0; i <= top; i++) {
		sum += stack[i];
	}

	printf("%d\n", sum);

	return 0;
}