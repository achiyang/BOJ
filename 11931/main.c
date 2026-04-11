#include <stdio.h>

int main() {
    int N;
    int count[2000001] = { 0 };

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int n;
        scanf("%d", &n);
        count[n + 1000000]++;
    }

    for (int i = 2000000; i >= 0; i--) {
        for (int j = 0; j < count[i]; j++) {
            printf("%d\n", i - 1000000);
        }
    }

    return 0;
}