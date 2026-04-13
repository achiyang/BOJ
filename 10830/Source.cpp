#include <iostream>
#include <vector>

typedef long long lld;
typedef std::vector<std::vector<lld>> matrix;

matrix operator * (const matrix& a, const matrix& b) {
	int size = static_cast<int>(a.size());
	matrix temp(size, std::vector<lld>(size, 0));

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < size; k++) {
				temp[i][j] += a[i][k] * b[k][j];
			}
			temp[i][j] %= 1000;
		}
	}

	return temp;
}

matrix power(matrix a, lld b) {
	int size = static_cast<int>(a.size());
	matrix temp(size, std::vector<lld>(size, 0));

	for (int i = 0; i < size; i++) {
		temp[i][i] = 1;
	}

	while (b > 0) {
		if (b % 2) {
			--b;
			temp = temp * a;
		}
		else {
			a = a * a;
			b /= 2;
		}
	}

	return temp;
}

void print_matrix(const matrix& a) {
	int size = static_cast<int>(a.size());

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			std::cout << a[i][j] << ' ';
		}
		std::cout << '\n';
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	lld B;

	std::cin >> N >> B;

	matrix a(N, std::vector<lld>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> a[i][j];
		}
	}

	print_matrix(power(a, B));

	return 0;
}