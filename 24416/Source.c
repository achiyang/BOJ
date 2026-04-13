#include<stdio.h>

int fi[50];

int f(int N) {
    fi[1] = fi[2] = 1;

    for (int i = 3; i <= N; i++) {
        fi[i] = fi[i - 1] + fi[i - 2];
    }

    return fi[N];
}

int main() {
    int N;

    scanf("%d", &N);

    printf("%d %d\n", f(N), N - 2);

    return 0;
}