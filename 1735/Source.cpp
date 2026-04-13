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

	long long a1, a2, b1, b2;

	std::cin >> a1 >> a2 >> b1 >> b2;

	long long ab = lcm(a2, b2);
	long long n = a1 * ab / a2 + b1 * ab / b2;
	long long abab = gcd(ab, n);

	std::cout << n / abab << ' ' << ab / abab;

	return 0;
}