#include <iostream>
#include <unordered_set>
#include <string>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, M, count = 0;
	std::string input;
	std::unordered_set<std::string> stringSet;

	std::cin >> N >> M;

	for (int i = 0; i < N; i++) {
		std::cin >> input;
		stringSet.insert(input);
	}

	for (int i = 0; i < M; i++) {
		std::cin >> input;
		if (stringSet.find(input) != stringSet.end()) {
			count++;
		}
	}

	std::cout << count;

	return 0;
}