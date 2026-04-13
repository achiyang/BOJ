#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

int min = INT_MAX;

void calMinDiff(std::vector<std::vector<int>>& S, int depth, int idx, int max) {
	static std::vector<bool> visited(max, false);

	if (depth == max / 2) {
		int team1 = 0, team2 = 0;

		for (int i = 0; i < max; i++) {
			for (int j = i + 1; j < max; j++) {
				if (visited[i] && visited[j]) {
					team1 += S[i][j] + S[j][i];
				}
				else if (!visited[i] && !visited[j]) {
					team2 += S[i][j] + S[j][i];
				}
			}
		}

		min = std::min(min, std::abs(team1 - team2));
		return;
	}

	for (int i = idx; i < max; i++) {
		visited[i] = true;
		calMinDiff(S, depth + 1, i + 1, max);
		visited[i] = false;
	}
}

int main() {
	int N;

	std::cin >> N;

	std::vector<std::vector<int>> S(N, std::vector<int>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> S[i][j];
		}
	}

	calMinDiff(S, 0, 0, N);

	std::cout << min << std::endl;

	return 0;
}