#include <iostream>
#include <algorithm>
#include <vector>
#include <array>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int N, count = 1;

	std::cin >> N;

	std::vector<std::array<int, 2>> meetings(N);

	for (int i = 0; i < N; i++) {
		std::cin >> meetings[i][0] >> meetings[i][1];
	}

	std::sort(meetings.begin(), meetings.end(),
		[](const std::array<int, 2>& a, const std::array<int, 2>& b) {
			return a[1] != b[1] ? a[1] < b[1] : a[0] < b[0];
		}
	);

	int end = meetings[0][1];
	for (int i = 1; i < N; i++) {
		if (end <= meetings[i][0]) {
			end = meetings[i][1];
			count++;
		}
	}

	std::cout << count;

	return 0;
}