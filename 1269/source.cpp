#include <iostream>
#include <unordered_set>

int main() {
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	int a, b, input;
	std::unordered_set<int> Set;

	std::cin >> a >> b;

	for (int i = 0; i < a + b; i++) {
		std::cin >> input;
		if (Set.find(input) == Set.end()) {
			Set.insert(input);
		}
		else {
			Set.erase(input);
		}
	}

	std::cout << Set.size();

	return 0;
}