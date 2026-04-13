#include <iostream>

int sort(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

int main() {
	int N[3];

	for (int i = 0; i < 3; i++) {
		std::cin >> N[i];
	}

	qsort(N, 3, sizeof(int), sort);

	std::cout << N[1] << std::endl;

	return 0;
}