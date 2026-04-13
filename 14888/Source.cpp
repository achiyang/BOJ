#include <iostream>
#include <vector>
#include <algorithm>

void get_cases(std::vector<int>& operators, std::vector<int>& cases, int n, int k) {
	if (n == k) {
		cases.insert(cases.end(), operators.begin(), operators.end());
		return;
	}

	for (int i = n; i < k; i++) {
		bool is_swap = true;

		for (int j = n; j < i; j++) {
			if (operators[j] == operators[i]) {
				is_swap = false;
				break;
			}
		}

		if (is_swap) {
			std::swap(operators[n], operators[i]);
			get_cases(operators, cases, n + 1, k);
			std::swap(operators[n], operators[i]);
		}
	}
}

int main() {
	int N;

	std::cin >> N;

	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}

	std::vector<int> operators;
	for (int value = 0; value < 4; value++) {
		int count;
		std::cin >> count;
		operators.insert(operators.end(), count, value);
	}

	std::vector<int> cases;
	get_cases(operators, cases, 0, N - 1);

	int max, min, temp;

	for (int i = 0; i < cases.size(); i++) {
		if (i % (N - 1) == 0) {
			temp = A[i % (N - 1)];
		}

		if (cases[i] == 0) {
			temp += A[i % (N - 1) + 1];
		}
		else if (cases[i] == 1) {
			temp -= A[i % (N - 1) + 1];
		}
		else if (cases[i] == 2) {
			temp *= A[i % (N - 1) + 1];
		}
		else if (cases[i] == 3) {
			temp /= A[i % (N - 1) + 1];
		}

		if (i % (N - 1) == N - 2) {
			if (i == N - 2) {
				max = min = temp;
			}
			else {
				max = std::max(temp, max);
				min = std::min(temp, min);
			}
		}
	}

	std::cout << max << '\n' << min << std::endl;

	return 0;
}