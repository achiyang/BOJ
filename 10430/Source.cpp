#include <iostream>

int main() {
	int A, B, C;

	std::cin >> A >> B >> C;

	std::cout << (A + B) % C << '\n' << ((A % C) + (B % C)) % C << '\n' << (A * B) % C << '\n' << ((A % C) * (B % C)) % C << std::endl;

	return 0;
}