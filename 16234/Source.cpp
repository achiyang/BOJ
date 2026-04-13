#include <iostream>
#include <vector>
#include <cmath>

const int dirRow[4] = { -1, 0, 1, 0 };
const int dirCol[4] = { 0, 1, 0, -1 };

bool isMigrationPossible(std::vector<std::vector<int>>& board, int minDiff, int maxDiff) {
	for (int row = 0; row < board.size(); row++) {
		for (int col = 0; col < board.size(); col++) {
			for (int dir = 0; dir < 2; dir++) {
				int newRow = row + (dir ? 0 : 1);
				int newCol = col + (dir ? 1 : 0);

				if (newRow < board.size() && newCol < board.size()) {
					int diff = std::abs(board[row][col] - board[newRow][newCol]);

					if (diff >= minDiff && diff <= maxDiff) {
						return true;
					}
				}
			}
		}
	}

	return false;
}

void formUnion(std::vector<std::vector<int>>& board, std::vector<std::vector<int>>& unions, int minDiff, int maxDiff, std::pair<int, int> index, int unionNumber) {
	unions[index.first][index.second] = unionNumber;

	for (int dir = 0; dir < 4; dir++) {
		std::pair<int, int> newIndex = { index.first + dirRow[dir], index.second + dirCol[dir] };

		if (newIndex.first >= 0 && newIndex.first < board.size() &&
			newIndex.second >= 0 && newIndex.second < board.size() &&
			unions[newIndex.first][newIndex.second] != unionNumber) {
			int diff = std::abs(board[index.first][index.second] - board[newIndex.first][newIndex.second]);

			if (diff >= minDiff && diff <= maxDiff) {
				formUnion(board, unions, minDiff, maxDiff, newIndex, unionNumber);
			}
		}
	}
}

void performMigration(std::vector<std::vector<int>>& board, int minDiff, int maxDiff) {
	std::vector<std::vector<int>> unions(board.size(), std::vector<int>(board.size(), 0));
	int currentUnion = 1;

	for (int row = 0; row < board.size(); row++) {
		for (int col = 0; col < board.size(); col++) {
			if (unions[row][col] == 0) {
				bool canUnion = false;

				for (int dir = 0; dir < 4; dir++) {
					int newRow = row + dirRow[dir];
					int newCol = col + dirCol[dir];

					if (newRow >= 0 && newRow < board.size() && newCol >= 0 && newCol < board.size()) {
						int diff = std::abs(board[row][col] - board[newRow][newCol]);

						if (diff >= minDiff && diff <= maxDiff) {
							canUnion = true;
							break;
						}
					}
				}

				if (canUnion) {
					formUnion(board, unions, minDiff, maxDiff, { row, col }, currentUnion++);
				}
			}
		}
	}

	for (int i = 1; i < currentUnion; i++) {
		int totalPopulation = 0, populationCount = 0, avg;

		for (int row = 0; row < unions.size(); row++) {
			for (int col = 0; col < unions.size(); col++) {
				if (unions[row][col] == i) {
					totalPopulation += board[row][col];
					populationCount++;
				}
			}
		}

		avg = totalPopulation / populationCount;

		for (int row = 0; row < unions.size(); row++) {
			for (int col = 0; col < unions.size(); col++) {
				if (unions[row][col] == i) {
					board[row][col] = avg;
				}
			}
		}
	}
}

int findMigrationDuration(std::vector<std::vector<int>>& board, int minDiff, int maxDiff) {
	int migrationDuration = 0;

	while (isMigrationPossible(board, minDiff, maxDiff)) {
		performMigration(board, minDiff, maxDiff);
		migrationDuration++;
	}

	return migrationDuration;
}

int main() {
	int N, L, R;

	std::cin >> N >> L >> R;

	std::vector<std::vector<int>> board(N, std::vector<int>(N, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> board[i][j];
		}
	}

	int migrationDuration = findMigrationDuration(board, L, R);

	std::cout << migrationDuration << std::endl;

	return 0;
}