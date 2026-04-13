#include <iostream>
#include <vector>
#include <algorithm>

void find(std::vector<int>& A, int start, int end, int value) {
	while (start < end) {
		int mid = (start + end) / 2;

		if (A[mid] == value) {
			std::cout << "1\n";
			return;
		}
		if (A[mid] > value) {
			end = mid;
		}
		else {
			start = mid + 1;
		}
	}

	std::cout << "0\n";
	return;
}

int main() {
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	int N, M;
	std::cin >> N;
	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	std::sort(A.begin(), A.end());

	std::cin >> M;
	for (int i = 0; i < M; i++) {
		int input;
		std::cin >> input;
		find(A, 0, N, input);
	}

	return 0;
}