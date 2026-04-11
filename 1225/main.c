#include <stdio.h>

int main() {
    char A[10001], B[10001];
    long long ans = 0;

    scanf("%s %s", A, B);

    for (char *ap = A; *ap; ap++) {
        int a = *ap - '0';
        for (char *bp = B; *bp; bp++) {
            int b = *bp - '0';
            ans += a * b;
        }
    }

    printf("%lld\n", ans);

    return 0;
}