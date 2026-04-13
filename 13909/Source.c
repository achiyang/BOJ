#include <stdio.h>

int main() {
    int N, count = 1;

    scanf("%d", &N);

    for (int i = 2; i * i <= N; i++) {
        count++;
    }

    printf("%d\n", count);

    return 0;
}