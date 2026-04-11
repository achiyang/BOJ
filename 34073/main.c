#include <stdio.h>

int main() {
    int N;
    char input[101];

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%s", input);
        printf("%sDORO ", input);
    }

    return 0;
}