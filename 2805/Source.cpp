#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	int N, M, left = 0, right = 0;

	std::cin >> N >> M;
	std::vector<int> V(N);
	for (int i = 0; i < N; i++) {
		std::cin >> V[i];
		right = std::max(right, V[i]);
	}

	while (left != right) {
		int mid = (left + right + 1) / 2;
		unsigned int sum = 0;

		for (int i = 0; i < N; i++) {
			sum += std::max(0, V[i] - mid);
			if (sum >= M) {
				break;
			}
		}

		if (sum >= M) {
			left = mid;
		}
		else {
			right = mid - 1;
		}
	}

	std::cout << left;

	return 0;
}