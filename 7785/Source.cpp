#include <iostream>
#include <set>
#include <string>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::string in1, in2;
	std::set<std::string> stringSet;

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> in1 >> in2;
		if (in2 == "enter") {
			stringSet.insert(in1);
		}
		else {
			stringSet.erase(in1);
		}
	}

	for (auto iter = stringSet.rbegin(); iter != stringSet.rend(); iter++) {
		std::cout << *iter << '\n';
	}

	return 0;
}