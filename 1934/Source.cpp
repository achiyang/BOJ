#include <iostream>

int gcd(int a, int b) {
	int temp;
	while (b) {
		temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main() {
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	int N, a, b;

	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> a >> b;
		std::cout << lcm(a, b) << '\n';
	}

	return 0;
}