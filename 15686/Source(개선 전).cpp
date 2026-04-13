#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

int min = INT_MAX;
std::vector<std::vector<int>> chickenRestaurant, house, chicken;

void getMin(int d, int start = 0) {
	if (d == 0) {
		int count = 0;
		for (const auto& h : house) {
			int minDistance = INT_MAX;
			for (const auto& c : chicken) {
				int distance = std::abs(h[0] - c[0]) + std::abs(h[1] - c[1]);
				minDistance = std::min(minDistance, distance);
			}
			count += minDistance;
		}
		min = std::min(min, count);
		return;
	}

	for (int i = start; i <= chickenRestaurant.size() - d; i++) {
		chicken.push_back(chickenRestaurant[i]);
		getMin(d - 1, i + 1);
		chicken.pop_back();
	}
}

int main() {
	int N, M;

	std::cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int p;
			std::cin >> p;
			if (p == 1) {
				house.push_back({ i, j });
			}
			else if (p == 2) {
				chickenRestaurant.push_back({ i, j });
			}
		}
	}

	getMin(M);

	std::cout << min << std::endl;

	return 0;
}