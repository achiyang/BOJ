#include <iostream>
#include <unordered_map>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, M, input;
	std::unordered_map<int, int> cardCount;

	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> input;
		cardCount[input]++;
	}

	std::cin >> M;
	for (int i = 0; i < M; i++) {
		std::cin >> input;
		if (cardCount.find(input) == cardCount.end()) {
			std::cout << "0 ";
		}
		else {
			std::cout << cardCount[input] << ' ';
		}
	}

	return 0;
}