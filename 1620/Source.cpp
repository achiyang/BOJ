#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, M, num;
	std::string input;
	std::vector<std::string> stringVector;
	std::unordered_map<std::string, int> stringMap;

	std::cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		std::cin >> input;
		stringVector.push_back(input);
		stringMap[input] = i;
	}
	for (int i = 0; i < M; i++) {
		std::cin >> input;
		if (input[0] >= '0' && input[0] <= '9') {
			num = std::stoi(input);
			std::cout << stringVector[num - 1] << '\n';
		}
		else {
			std::cout << stringMap[input] << '\n';
		}
	}

	return 0;
}