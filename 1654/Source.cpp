#include <iostream>

int main() {
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	int K, N, arr[10000];
	long long sum = 0;

	std::cin >> K >> N;

	for (int i = 0; i < K; i++) {
		std::cin >> arr[i];
		sum += arr[i];
	}

	unsigned int left = 1, right = sum / K;
	while (left != right) {
		int sum = 0;
		unsigned int mid = (left + right + 1) / 2;

		for (int i = 0; i < K; i++) {
			sum += arr[i] / mid;
			if (sum >= N) {
				break;
			}
		}

		if (sum >= N) {
			left = mid;
		}
		else {
			right = mid - 1;
		}
	}

	std::cout << left;

	return 0;
}