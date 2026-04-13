#include <iostream>
#include <deque>

int main() {
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	std::deque<int> myDeque;

	int N, input;

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> input;

		int command = input;

		if (command == 1 || command == 2) {
			std::cin >> input;

			if (command == 1) {
				myDeque.push_front(input);
			}
			else {
				myDeque.push_back(input);
			}
		}
		else if (command == 3) {
			if (myDeque.size() > 0) {
				std::cout << myDeque.front() << '\n';
				myDeque.pop_front();
			}
			else {
				std::cout << -1 << '\n';
			}
		}
		else if (command == 4) {
			if (myDeque.size() > 0) {
				std::cout << myDeque.back() << '\n';
				myDeque.pop_back();
			}
			else {
				std::cout << -1 << '\n';
			}
		}
		else if (command == 5) {
			std::cout << myDeque.size() << '\n';
		}
		else if (command == 6) {
			std::cout << (myDeque.empty() ? 1 : 0) << '\n';
		}
		else if (command == 7) {
			if (myDeque.size() > 0) {
				std::cout << myDeque.front() << '\n';
			}
			else {
				std::cout << -1 << '\n';
			}
		}
		else {
			if (myDeque.size() > 0) {
				std::cout << myDeque.back() << '\n';
			}
			else {
				std::cout << -1 << '\n';
			}
		}
	}

	return 0;
}