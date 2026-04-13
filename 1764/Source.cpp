#include <iostream>
#include <string>
#include <map>
#include <vector>

int main() {
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	int N, M;
	std::map<std::string, int> list;
	std::vector<std::string> strings;
	std::string input;

	std::cin >> N >> M;

	for (int i = 0; i < N + M; i++) {
		std::cin >> input;
		list[input]++;
	}

	for (const auto& pair : list) {
		if (pair.second > 1) {
			strings.push_back(pair.first);
		}
	}

	std::cout << strings.size() << '\n';
	for (const auto& string : strings) {
		std::cout << string << '\n';
	}

	return 0;
}