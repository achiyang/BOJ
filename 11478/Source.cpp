#include <iostream>
#include <unordered_set>

int main() {
	std::string S;
	std::unordered_set<std::string> strSet;

	std::cin >> S;

	int len = S.length();

	for (int i = 0; i < len; i++) {
		for (int j = i; j < len; j++) {
			strSet.insert(S.substr(i, j - i + 1));
		}
	}

	std::cout << strSet.size();

	return 0;
}