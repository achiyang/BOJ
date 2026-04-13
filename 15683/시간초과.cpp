#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int getMaxNonMonitoringZone(const std::vector<std::vector<int>>& office, int depth, int numcctv) {
	static int min = INT_MAX;
	static std::vector<std::vector<int>> dir(office.size(), std::vector<int>(office[0].size(), 0));

	if (depth == numcctv) {
		int nonMonitoringZone = 0;
		int c_office;
		int c_dir;

		for (int i = 0; i < office.size(); i++) {
			for (int j = 0; j < office[i].size(); j++) {
				if (office[i][j] == 0) {
					bool nonMonitored = true;

					for (int k = i - 1; k >= 0; k--) {
						c_office = office[k][j];
						if (c_office == 6) {
							break;
						}
						c_dir = dir[k][j];
						if (!c_dir) {
							continue;
						}
						if (c_office == 5) {
							nonMonitored = false;
							break;
						}
						if (c_office == 4 && c_dir != 1) {
							nonMonitored = false;
							break;
						}
						if (c_office == 3 && (c_dir == 2 || c_dir == 3)) {
							nonMonitored = false;
							break;
						}
						if (c_office == 2 && c_dir == 2) {
							nonMonitored = false;
							break;
						}
						if (c_office == 1 && c_dir == 3) {
							nonMonitored = false;
							break;
						}
					}
					if (nonMonitored) {
						for (int k = i + 1; k < office.size(); k++) {
							c_office = office[k][j];
							if (c_office == 6) {
								break;
							}
							c_dir = dir[k][j];
							if (!c_dir) {
								continue;
							}
							if (c_office == 5) {
								nonMonitored = false;
								break;
							}
							if (c_office == 4 && c_dir != 3) {
								nonMonitored = false;
								break;
							}
							if (c_office == 3 && (c_dir == 1 || c_dir == 4)) {
								nonMonitored = false;
								break;
							}
							if (c_office == 2 && c_dir == 2) {
								nonMonitored = false;
								break;
							}
							if (c_office == 1 && c_dir == 1) {
								nonMonitored = false;
								break;
							}
						}
					}
					if (nonMonitored) {
						for (int k = j - 1; k >= 0; k--) {
							c_office = office[i][k];
							if (c_office == 6) {
								break;
							}
							c_dir = dir[i][k];
							if (!c_dir) {
								continue;
							}
							if (c_office == 5) {
								nonMonitored = false;
								break;
							}
							if (c_office == 4 && c_dir != 4) {
								nonMonitored = false;
								break;
							}
							if (c_office == 3 && (c_dir == 1 || c_dir == 2)) {
								nonMonitored = false;
								break;
							}
							if (c_office == 2 && c_dir == 1) {
								nonMonitored = false;
								break;
							}
							if (c_office == 1 && c_dir == 2) {
								nonMonitored = false;
								break;
							}
						}
					}
					if (nonMonitored) {
						for (int k = j + 1; k < office[i].size(); k++) {
							c_office = office[i][k];
							if (c_office == 6) {
								break;
							}
							c_dir = dir[i][k];
							if (!c_dir) {
								continue;
							}
							if (c_office == 5) {
								nonMonitored = false;
								break;
							}
							if (c_office == 4 && c_dir != 2) {
								nonMonitored = false;
								break;
							}
							if (c_office == 3 && (c_dir == 3 || c_dir == 4)) {
								nonMonitored = false;
								break;
							}
							if (c_office == 2 && c_dir == 1) {
								nonMonitored = false;
								break;
							}
							if (c_office == 1 && c_dir == 4) {
								nonMonitored = false;
								break;
							}
						}
					}

					if (nonMonitored) {
						nonMonitoringZone++;
					}
				}
			}
		}

		min = std::min(min, nonMonitoringZone);
	}

	for (int i = 0; i < office.size(); i++) {
		for (int j = 0; j < office[i].size(); j++) {
			if (dir[i][j] == 0) {
				if (office[i][j] == 5) {
					dir[i][j] = 1;
				}
				if (office[i][j] == 1 || office[i][j] == 3 || office[i][j] == 4) {
					for (int k = 1; k <= 4; k++) {
						dir[i][j] = k;
						getMaxNonMonitoringZone(office, depth + 1, numcctv);
					}
					dir[i][j] = 0;
				}
				else if (office[i][j] == 2) {
					for (int k = 1; k <= 2; k++) {
						dir[i][j] = k;
						getMaxNonMonitoringZone(office, depth + 1, numcctv);
					}
					dir[i][j] = 0;
				}
			}
		}
	}

	if (depth == 0) {
		return min;
	}
}

int main() {
	int N, M;

	std::cin >> N >> M;

	std::vector <std::vector<int>> office(N, std::vector<int>(M));

	int numcctv = 0;

	int g;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			std::cin >> g;
			if (g >= 1 && g <= 4) {
				numcctv++;
			}
			office[i][j] = g;
		}
	}

	std::cout << getMaxNonMonitoringZone(office, 0, numcctv) << std::endl;

	return 0;
}