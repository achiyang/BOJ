#include <iostream>
#include <vector>
#include <algorithm>

int max = 0;

std::vector<std::vector<int>> TP;
std::vector<bool> isCounselingDay;

void getMaxProfit(int day, int Dday) {
	if (day >= Dday) {
		int count = 0;
		for (int i = 0; i < Dday; i++) {
			if (isCounselingDay[i]) {
				if (TP[i][0] + i <= Dday) {
					count += TP[i][1];
				}
			}
		}
		max = std::max(max, count);
		return;
	}

	for (int i = 0; i < 2; i++) {
		if (i) {
			getMaxProfit(day + 1, Dday);
		}
		else {
			isCounselingDay[day] = true;
			getMaxProfit(day + TP[day][0], Dday);
			isCounselingDay[day] = false;
		}
	}
}

int main() {
	int N;

	std::cin >> N;

	TP.resize(N, std::vector<int>(2));
	isCounselingDay.resize(N, false);

	for (int i = 0; i < N; i++) {
		std::cin >> TP[i][0] >> TP[i][1];
	}

	getMaxProfit(0, N);

	std::cout << max << std::endl;

	return 0;
}