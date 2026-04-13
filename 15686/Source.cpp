#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

int min = INT_MAX;
std::vector<std::vector<int>> chickenRestaurant, house, HCdistance;
std::vector<int> chickenIndex;

void getMin(int d, int start = 0) {
	if (d == 0) {
		int count = 0;
		for (int i = 0; i < house.size(); i++) {
			int minDistance = INT_MAX;
			for (const int& c : chickenIndex) {
				minDistance = std::min(minDistance, HCdistance[i][c]);
			}
			count += minDistance;
		}
		min = std::min(min, count);
		return;
	}

	for (int i = start; i <= chickenRestaurant.size() - d; i++) {
		chickenIndex.push_back(i);
		getMin(d - 1, i + 1);
		chickenIndex.pop_back();
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

	HCdistance.resize(house.size(), std::vector<int>(chickenRestaurant.size()));

	for (int i = 0; i < house.size(); i++) {
		for (int j = 0; j < chickenRestaurant.size(); j++) {
			int distance = std::abs(house[i][0] - chickenRestaurant[j][0]) + std::abs(house[i][1] - chickenRestaurant[j][1]);
			HCdistance[i][j] = distance;
		}
	}

	getMin(M);

	std::cout << min << std::endl;

	return 0;
}