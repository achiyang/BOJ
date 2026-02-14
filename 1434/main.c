#include <stdio.h>

int main() {
    int N, M, idx = 0, ans = 0;
    int box[50];

    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        scanf("%d", &box[i]);
    }

    // 책 정리 알고리즘
    for (int i = 0; i < M; i++) {
        int book;

        scanf("%d", &book);

        while (box[idx] < book) {
            ans += box[idx];
            ++idx;
        }

        box[idx] -= book;
    }

    // 미사용 박스 집계
    while (idx < N) {
        ans += box[idx++];
    }

    printf("%d\n", ans);

    return 0;
}