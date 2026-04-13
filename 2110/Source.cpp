#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	int N, C;

	std::cin >> N >> C;
	std::vector<int> pos(N);
	for (int i = 0; i < N; i++) {
		std::cin >> pos[i];
	}

	std::sort(pos.begin(), pos.end());

	int left = 1, right = pos[N - 1] - pos[0];
	while (left < right) {
		int mid = (left + right + 1) / 2;
		int count = 1;
		int current = pos[0];

		for (int i = 1; i < N; i++) {
			if (pos[i] - current >= mid) {
				if (++count >= C) {
					break;
				}
				current = pos[i];
			}
		}

		if (count >= C) {
			left = mid;
		}
		else {
			right = mid - 1;
		}
	}

	std::cout << left;

	return 0;
}