#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pi[2000000];
int index_;
int indexs[2000000];

void getPi(const char* str) {
	int len = strlen(str), j = 0;

	for (int i = 1; i < len; i++) {
		while (j > 0 && str[i] != str[j]) {
			j = pi[j - 1];
		}

		if (str[i] == str[j]) {
			pi[i] = ++j;
		}
	}
}

void KMP(const char* Str, const char* SubStr) {
	getPi(SubStr);

	int str_len = strlen(Str);
	int sub_len = strlen(SubStr);

	for (int i = 0, j = 0; i < str_len; i++) {
		while (j > 0 && SubStr[j] != Str[i]) {
			j = pi[j - 1];
		}

		if (Str[i] == SubStr[j]) {
			if (j == sub_len - 1) {
				indexs[index_++] = i - sub_len + 2;
				j = pi[j];
			}
			else {
				j++;
			}
		}
	}
}

char T[2000000];
char P[2000000];

int main() {
	int i;
	fgets(T, 2000000, stdin);
	for (i = 0; T[i] != '\n'; i++);
	T[i] = '\0';
	fgets(P, 2000000, stdin);
	for (i = 0; P[i] != '\n'; i++);
	P[i] = '\0';

	KMP(T, P);

	printf("%d\n", index_);
	for (int i = 0; i < index_; i++) {
		printf("%d ", indexs[i]);
	}

	return 0;
}