#include <iostream>
#include <vector>

std::vector<bool> prime(int max) {
	std::vector<bool> PrimeArray(max + 1, true);

    PrimeArray[0] = false;
    PrimeArray[1] = false;

	for (int i = 2; i * i <= max; i++) {
		if (PrimeArray[i]) {
			for (int j = i * i; j <= max; j += i) {
				PrimeArray[j] = false;
			}
		}
	}
    
    return PrimeArray;
}

int main() {
	int M, N;

	std::cin >> M >> N;

    std::vector<bool> PrimeArray = prime(N);

	for (int i = M; i <= N; i++) {
		if (PrimeArray[i]) {
			std::cout << i << '\n';
		}
	}

	return 0;
}