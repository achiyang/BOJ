#include <iostream>
#include <algorithm>

int main() {
	int N, k;

	std::cin >> N >> k;

	int left = 1, right = k;
	while (left < right) {
		int mid = (left + right) / 2;
		int count = 0;

		for (int i = 1; i <= N; i++) {
			count += std::min(N, mid / i);
		}

		if (count < k) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}

	std::cout << left;

	return 0;
}