#include <iostream>

typedef unsigned long long llu;

llu myPow(llu A, llu B, llu C) {
	if (B == 0) {
		return 1;
	}

	llu result = 1;
	A = A % C;

	while (B > 0) {
		if (B % 2) {
			result = (result * A) % C;
		}

		A = (A * A) % C;
		B /= 2;
	}

	return result;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	llu A, B, C;

	std::cin >> A >> B >> C;

	std::cout << myPow(A, B, C);

	return 0;
}