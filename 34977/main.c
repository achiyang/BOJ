#include <stdio.h>

#define MAX 1000

int L[MAX];
int lps[MAX];

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &L[i]);
    }

    lps[0] = 0;
    int len = 0;

    for (int i = 1; i < N; i++) {
        while (len > 0 && L[i] != L[len]) {
            len = lps[len - 1];
        }
        if (L[i] == L[len]) {
            len++;
        }
        lps[i] = len;
    }

    int k = lps[N - 1];
    while (k > 0) {
        if (k <= N / 2) {
            printf("yes\n");
            return 0;
        }
        k = lps[k - 1];
    }

    printf("no\n");
    return 0;
}