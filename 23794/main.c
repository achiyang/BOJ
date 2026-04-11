#include <stdio.h>

int main() {
    int N;

    scanf("%d", &N);

    for (int i = 0; i < N + 2; i++) {
        for (int j = 0; j < N + 2; j++) {
            if ((i > 0 && i < N + 1) && (j > 0 && j < N + 1))
                printf(" ");
            else
                printf("@");
        }
        printf("\n");
    }

    return 0;
}