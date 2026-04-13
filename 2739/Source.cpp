#include <iostream>

int main() {
	int N, multiplication_table[9][9] = { 0 };

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			for (int k = 0; k <= j; k++) {
				multiplication_table[i][j] += i + 1;
			}
		}
	}

	std::cin >> N;

	for (int i = 0; i < 9; i++) {
		std::cout << N << " * " << i + 1 << " = " << multiplication_table[N - 1][i] << std::endl;
	}

	return 0;
}