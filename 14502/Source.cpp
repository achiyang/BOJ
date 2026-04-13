#include <cstdio>
#include <vector>
#include <algorithm>

int N, M;
int lab_size;

void virus(std::vector<int>& laboratory, int index) {
	if (index - M >= 0) {
		if (laboratory[index - M] == 0) {
			laboratory[index - M] = 2;
			virus(laboratory, index - M);
		}
	}
	if (index + M < lab_size) {
		if (laboratory[index + M] == 0) {
			laboratory[index + M] = 2;
			virus(laboratory, index + M);
		}
	}
	if (index % M != 0) {
		if (laboratory[index - 1] == 0) {
			laboratory[index - 1] = 2;
			virus(laboratory, index - 1);
		}
	}
	if (index % M != M - 1) {
		if (laboratory[index + 1] == 0) {
			laboratory[index + 1] = 2;
			virus(laboratory, index + 1);
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);

	lab_size = N * M;

	std::vector<int> laboratory(lab_size);
	std::vector<int> empty_laps;
	std::vector<int> virus_labs;

	for (int i = 0; i < lab_size; i++) {
		int temp;

		scanf("%d", &temp);
		laboratory[i] = temp;

		if (temp == 0) {
			empty_laps.push_back(i);
		}
		if (temp == 2) {
			virus_labs.push_back(i);
		}
	}

	int max = 0;

	for (int i = 0; i < empty_laps.size(); i++) {
		for (int j = i + 1; j < empty_laps.size(); j++) {
			for (int k = j + 1; k < empty_laps.size(); k++) {
				std::vector<int> copy_laboratory = laboratory;
				copy_laboratory[empty_laps[i]] = 1;
				copy_laboratory[empty_laps[j]] = 1;
				copy_laboratory[empty_laps[k]] = 1;
				for (int index : virus_labs) {
					virus(copy_laboratory, index);
				}
				max = std::max(static_cast<int>(std::count(copy_laboratory.begin(), copy_laboratory.end(), 0)), max);
			}
		}
	}

	printf("%d\n", max);

	return 0;
}