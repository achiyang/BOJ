#include <iostream>
#include <unordered_map>
#include <string>

int main() {
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	std::unordered_map<std::string, int> Map;
	Map["ChongChong"] = 1;

	int N, count = 1;
	std::string input1, input2;

	std::cin >> N;

	while (N--) {
		std::cin >> input1 >> input2;

		bool not_exist_1 = Map.find(input1) == Map.end();
		bool not_exist_2 = Map.find(input2) == Map.end();

		if (not_exist_1 && not_exist_2) {
			Map[input1] = Map[input2] = 0;
		}
		else if (not_exist_1) {
			if (Map[input2] == 1) {
				Map[input1] = 1;
				count++;
			}
			else {
				Map[input1] = 0;
			}
		}
		else if (not_exist_2) {
			if (Map[input1] == 1) {
				Map[input2] = 1;
				count++;
			}
			else {
				Map[input2] = 0;
			}
		}
		else {
			bool isSparkle_1 = Map[input1] == 1;
			bool isSparkle_2 = Map[input2] == 1;

			if (!isSparkle_1 && isSparkle_2) {
				Map[input1] = 1;
				count++;
			}
			else if (isSparkle_1 && !isSparkle_2) {
				Map[input2] = 1;
				count++;
			}
		}
	}

	std::cout << count << std::endl;

	return 0;
}