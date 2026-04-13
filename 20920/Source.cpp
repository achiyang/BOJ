#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

bool compareWords(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
	if (a.second != b.second) {
		return a.second > b.second;
	}

	if (a.first.size() != b.first.size()) {
		return a.first.size() > b.first.size();
	}

	return a.first < b.first;
}

int main() {
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	int N, M;
	std::string input;
	std::unordered_map<std::string, int> words;

	std::cin >> N >> M;

	for (int i = 0; i < N; i++) {
		std::cin >> input;
		if (input.size() >= M) {
			words[input]++;
		}
	}

	std::vector<std::pair<std::string, int>> wordVector(words.begin(), words.end());

	std::sort(wordVector.begin(), wordVector.end(), compareWords);

	for (const auto& pair : wordVector) {
		std::cout << pair.first << '\n';
	}

	return 0;
}