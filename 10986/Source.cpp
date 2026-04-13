#include <iostream>

typedef unsigned long long llu;

int remainder_count[1000];

llu f(int n) {
	if (n & 1) {
		return static_cast<llu>(n - 1) / 2 * n;
	}
	else {
		return static_cast<llu>(n - 1) * (n / 2);
	}
}

int main() {
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	int N, M, num = 0;

	std::cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int input;

		std::cin >> input;

		num = (num + input) % M;
		remainder_count[num]++;
	}

	llu count = f(remainder_count[0] + 1);

	for (int i = 1; i < M; i++) {
		if (remainder_count[i] > 1) {
			count += f(remainder_count[i]);
		}
	}

	std::cout << count;

	return 0;
}