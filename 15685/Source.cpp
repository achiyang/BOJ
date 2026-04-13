#include <iostream>
#include <vector>
#include <set>

std::set<std::pair<int, int>> dragonCurveXY;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

void dragonCurve(int x, int y, int d, int g) {
	std::vector<int> dirs{ d };

	for (int i = 0; i < g; i++) {
		for (int dir : std::vector<int>(dirs.rbegin(), dirs.rend())) {
			dirs.push_back((dir + 1) % 4);
		}
	}

	std::pair<int, int> currentXY { x, y };
	dragonCurveXY.insert(currentXY);
	for (int dir : dirs) {
		currentXY.first += dx[dir];
		currentXY.second += dy[dir];
		dragonCurveXY.insert(currentXY);
	}
}

int main() {
	int N;

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		int x, y, d, g;
		std::cin >> x >> y >> d >> g;
		dragonCurve(x, y, d, g);
	}

	int count = 0;

	for (const auto& XY : dragonCurveXY) {
		const int dx[3] = { 1, 1, 0 };
		const int dy[3] = { 0, -1, -1 };

		bool is = true;
		for (int i = 0; i < 3; i++) {
			if (dragonCurveXY.find({ XY.first + dx[i], XY.second + dy[i]}) == dragonCurveXY.end()) {
				is = false;
				break;
			}
		}
		if (is) {
			count++;
		}
	}

	std::cout << count << std::endl;

	return 0;
}