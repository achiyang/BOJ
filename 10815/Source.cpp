#include <iostream>
#include <unordered_set>
#include <map>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, input;
	std::unordered_set<int> cardSet;

	std::cin >> N;
	while (N--) {
		std::cin >> input;
		cardSet.insert(input);
	}

	std::cin >> N;
	while (N--) {
		std::cin >> input;
		std::cout << (cardSet.find(input) != cardSet.end()) << ' ';
	}

	return 0;
}