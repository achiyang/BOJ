#include <cstdio>
#include <vector>

std::vector<int> Primes;

std::vector<bool> eratos(int max) {
    std::vector<bool> Prime(max + 1, true);

    Prime[0] = Prime[1] = false;

    int i;

    for (i = 2; i * i <= max; i++) {
        if (Prime[i]) {
            Primes.push_back(i);
            for (int j = i * i; j <= max; j += i) {
                Prime[j] = false;
            }
        }
    }

    for (; i <= max; i++) {
        if (Prime[i]) {
            Primes.push_back(i);
        }
    }

    return Prime;
}

std::vector<bool> isPrime = eratos(1000000);

int countGoldbachPartitions(int N) {
    int count = 0;
    for (int p = 0; Primes[p] <= N / 2; p++) {
        if (isPrime[N - Primes[p]]) {
            count++;
        }
    }

    return count;
}

int main() {
    int T;

    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int N;
        scanf("%d", &N);
        printf("%d\n", countGoldbachPartitions(N));
    }
    return 0;
}