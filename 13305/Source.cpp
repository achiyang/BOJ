#include <iostream>

typedef unsigned long long llu;

int arr[100000];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, input;

	std::cin >> N;

	for (int i = 0; i < N - 1; i++) {
		std::cin >> arr[i];
	}

	int min = 1000000000;
	llu sum = 0;
	for (int i = 0; i < N - 1; i++) {
		std::cin >> input;
		if (min > input) {
			min = input;
		}
		sum += static_cast<llu>(min) * arr[i];
	}

	std::cout << sum;

	return 0;
}