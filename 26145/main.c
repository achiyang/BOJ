#include <stdio.h>

#define MAX 2000

int main() {
    // N: 출제자 수, M: 검수자 수, arr: 각 인원의 잔고 (최대 2000명)
    int N, M, arr[MAX] = { 0 };

    scanf("%d %d", &N, &M);

    // 출제자들의 초기 자본
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    // 자금 분배 (N x (N + M))
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N + M; j++) {
            int T;
            scanf("%d", &T);

            arr[i] -= T;  // 주는 사람의 잔고 차감
            arr[j] += T;  // 받는 사람의 잔고 증가
        }
    }

    // 결과 출력
    for (int i = 0; i < N + M; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}