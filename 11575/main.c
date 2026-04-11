#include <stdio.h>

int main() {
    int T;

    scanf("%d", &T);

    while (T--) {
        int a, b;
        char s[1000000];

        scanf("%d %d %s", &a, &b, s);

        for (char *cp = s; *cp; cp++) {
            printf("%c", ((*cp - 'A') * a + b) % 26 + 'A');
        }
        printf("\n");
    }

    return 0;
}