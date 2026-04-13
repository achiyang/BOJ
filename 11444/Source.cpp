#include <iostream>
#include <vector>

const int DIV = 1000000007;
typedef unsigned long long llu;
typedef std::vector<std::vector<llu>> Matrix;

Matrix operator*(const Matrix& a, const Matrix& b) {
	Matrix result(2, std::vector<llu>(2, 0));

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % DIV;
			}
		}
	}

	return result;
}

Matrix powerMatrix(Matrix a, llu n) {
	Matrix result{ {1, 0}, {0, 1} };

	while (n > 0) {
		if (n % 2) {
			result = result * a;
		}
		a = a * a;
		n /= 2;
	}

	return result;
}

llu fibonacci(llu n) {
	Matrix base{ {1, 1}, {1, 0} };
	return powerMatrix(base, n - 1)[0][0];
}

int main() {
	llu N;

	std::cin >> N;

	std::cout << fibonacci(N);

	return 0;
}