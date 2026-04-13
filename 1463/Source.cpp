#include <iostream>

int main() {
	int X;

	std::cin >> X;

	int* N = new int[X + 1] {};

	for (int i = 2; i <= X; i++) {
		N[i] = N[i - 1]  + 1;

		if (i % 3 == 0) {
			N[i] = std::min(N[i], N[i / 3] + 1);
		}
		if (i % 2 == 0) {
			N[i] = std::min(N[i], N[i / 2] + 1);
		}
	}

	std::cout << N[X] << std::endl;

	return 0;
}