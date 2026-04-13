#include <iostream>
#include <vector>
#include <algorithm>

int _gcd(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int _lcm(int a, int b) {
	return a / _gcd(a, b) * b;
}

std::vector<int> get_divisors(int num) {
	std::vector<int> divisors;

	for (int i = 1; i * i <= num; i++) {
		if (num % i == 0) {
			divisors.push_back(i);
			if (num != i * i) {
				divisors.push_back(num / i);
			}
		}
	}

	std::sort(divisors.begin(), divisors.end());

	return divisors;
}

int main() {
	int gcd, lcm;

	std::cin >> gcd >> lcm;

	auto divisors = get_divisors(lcm);

	std::vector<std::pair<int, int>> pairs;

	for (int divisor_1 : divisors) {
		for (int divisor_2 : divisors) {
			if (_gcd(divisor_1, divisor_2) == gcd && _lcm(divisor_1, divisor_2) == lcm) {
				pairs.push_back({ divisor_1, divisor_2 });
			}
		}
	}

	std::pair<int, int> min = pairs[0];

	for (const auto& pair : pairs) {
		if (min.first + min.second > pair.first + pair.second) {
			min = pair;
		}
	}

	std::cout << min.first << ' ' << min.second << std::endl;

	return 0;
}