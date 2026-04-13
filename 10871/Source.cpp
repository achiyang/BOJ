#include <iostream>

int main() {
    int N, X, temp;

    std::cin >> N >> X;

    int* Myvector = new int[N];

    for (int i = 0; i < N; i++) {
        std::cin >> temp;
        Myvector[i] = temp;
    }

    for (int i = 0; i < N; i++) {
        if (Myvector[i] < X) {
            std::cout << Myvector[i] << ' ';
        }
    }

    return 0;
}