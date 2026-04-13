// 비트마스크를 사용하는 방법
// (1 << M) - 1 부터 (1 << (치킨집 개수) + 1) - 1 까지의 비트마스크를 모두 확인해서 1인 비트가 M개일 경우 실행
// 조합을 계산하는 방식보다 비효율적
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

int min = INT_MAX;
std::vector<std::vector<int>> chickenRestaurant, house, HCdistance;

void getMin(int bit) {
	int count = 0;
	for (int i = 0; i < house.size(); i++) {
		int minDistance = INT_MAX;
		for (int j = 0; j < chickenRestaurant.size(); j++) {
			if (bit & (1 << j)) {
				minDistance = std::min(minDistance, HCdistance[i][j]);
			}
		}
		count += minDistance;
	}
	min = std::min(min, count);
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

	for (int i = (1 << M) - 1; i < 1 << chickenRestaurant.size() + 1; i++) {
		int count = 0;
		for (int j = 0; j < chickenRestaurant.size(); j++) {
			if (i & (1 << j)) {
				count++;
			}
		}
		if (count == M) {
			getMin(i);
		}
	}

	std::cout << min << std::endl;

	return 0;
}