#include <iostream>

int main() {
    int N;
    
    std::cin >> N;
    
    while (N > 0) {
        std::cout << N-- << '\n';
    }
    
    return 0;
}