#include <iostream>

int get_gcd(int a, int b) {
	return b ? get_gcd(b, a % b) : a;
}

int get_lcm(int a, int b) {
	return a / get_gcd(a, b) * b;
}

int main() {
	int a, b;

	std::cin >> a >> b;

	int gcd = get_gcd(a, b);
	int lcm = get_lcm(a, b);

	std::cout << gcd << '\n' << lcm << std::endl;

	return 0;
}