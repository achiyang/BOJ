#include <stdio.h>
#include <ctype.h>

int main() {
	int index = 0, t = 0;
	char S[1000001];
	int alphabet[26] = { 0 };

	scanf("%s", S);

	while (S[index] != '\0') {
		alphabet[tolower(S[index++]) - 'a']++;
	}

	index = 0;

	for (int i = 0; i < 26; i++) {
		if (alphabet[index] < alphabet[i]) {
			index = i;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (index != i && alphabet[index] == alphabet[i]) {
			t = 1;
			break;
		}
	}

	if (t) {
		printf("?");
	}
	else {
		printf("%c", index + 'A');
	}

	return 0;
}