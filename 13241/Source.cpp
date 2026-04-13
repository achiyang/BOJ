#include <iostream>

long long gcd(long long a, long long b) {
	long long temp;
	while (b) {
		temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

long long lcm(long long a, long long b) {
	return a * b / gcd(a, b);
}

int main() {
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	long long a, b;

	std::cin >> a >> b;
	std::cout << lcm(a, b) << '\n';

	return 0;
}