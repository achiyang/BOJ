#include <stdio.h>

int main() {
    int N, M, arr[2000] = { 0 };

    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N + M; j++) {
            int T;
            scanf("%d", &T);
            arr[i] -= T;
            arr[j] += T;
        }
    }

    for (int i = 0; i < N + M; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}