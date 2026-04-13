#include <stdio.h>
#include <stdlib.h>

char* strplusminus(const char* Str) {
	while (*Str && *Str != '+' && *Str != '-') {
		++Str;
	}

	return *Str ? Str : NULL;
}

int main() {
	char input[51];

	scanf("%s", input);

	char* token = input;

	int result = atoi(token);

	int flag = 0;
	while (token = strplusminus(token)) {
		++token;

		if (flag) {
			result -= atoi(token);
		}
		else if (*(token - 1) == '-') {
			flag = 1;
			result -= atoi(token);
		}
		else {
			result += atoi(token);
		}
	}

	printf("%d\n", result);

	return 0;
}