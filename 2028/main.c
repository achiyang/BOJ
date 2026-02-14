#include <stdio.h>

int main() {
    int T;

    scanf("%d", &T);

    while (T--) {
        int N;

        scanf("%d", &N);
        
        int NN = N * N;
        char *ans = "YES";

        while (N) {
            if (NN % 10 != N % 10) {
                ans = "NO";
                break;
            }
            NN /= 10;
            N /= 10;
        }

        printf("%s\n", ans);
    }

    return 0;
}