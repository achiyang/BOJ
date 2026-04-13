#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;

	std::cin >> N;
	std::vector<int> sub;
	for (int i = 0; i < N; i++) {
		int input;
		std::cin >> input;

		if (sub.empty() || input > sub.back()) {
			sub.push_back(input);
		}
		else {
			int left = 0, right = sub.size();
			while (left < right) {
				int mid = (left + right) / 2;

				if (input > sub[mid]) {
					left = mid + 1;
				}
				else {
					right = mid;
				}
			}
			sub[left] = input;
		}
	}

	std::cout << sub.size();

	return 0;
}