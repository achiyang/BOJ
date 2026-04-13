#include <iostream>
#include <unordered_set>
#include <string>

int main() {
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	int N, count = 0;
	std::string input;
	std::unordered_set<std::string> stringSet;

	std::cin >> N;

	while (N--) {
		std::cin >> input;
		if (input == "ENTER") {
			count += stringSet.size();
			stringSet = std::unordered_set<std::string>();
		}
		else {
			stringSet.insert(input);
		}
	}

	std::cout << count + stringSet.size() << std::endl;

	return 0;
}