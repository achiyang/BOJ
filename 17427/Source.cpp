#include <iostream>

int main() {
    int N;
    long long sum = 0;

    std::cin >> N;

    for (int i = 1; i <= N; i++) {
        sum += i * (N / i);
    }

    std::cout << sum << std::endl;

    return 0;
}