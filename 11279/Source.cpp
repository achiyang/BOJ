#include <iostream>
#include <vector>
#include <algorithm>

class MaxHeap {
private:
	std::vector<int> heap;

	int parent(int i) { return (i - 1) / 2; }

	int leftChild(int i) { return 2 * i + 1; }

	int rightChild(int i) { return 2 * i + 2; }

	void heapifyUp(int i) {
		while (i > 0 && heap[parent(i)] < heap[i]) {
			std::swap(heap[parent(i)], heap[i]);
			i = parent(i);
		}
	}

	void heapifyDown(int i) {
		int maxIndex = i;
		int left = leftChild(i);
		int right = rightChild(i);

		if (left < heap.size() && heap[left] > heap[maxIndex]) {
			maxIndex = left;
		}

		if (right < heap.size() && heap[right] > heap[maxIndex]) {
			maxIndex = right;
		}

		if (maxIndex != i) {
			std::swap(heap[i], heap[maxIndex]);
			heapifyDown(maxIndex);
		}
	}

public:
	void insert(int value) {
		heap.push_back(value);
		heapifyUp(heap.size() - 1);
	}

	void pop() {
		if (heap.empty()) {
			std::cout << "0\n";
			return;
		}

		int max = heap[0];
		heap[0] = heap.back();
		heap.pop_back();
		heapifyDown(0);

		std::cout << max << '\n';
	}
};

int main() {
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	int N;
	MaxHeap maxHeap;

	std::cin >> N;
	for (int i = 0; i < N; i++) {
		int input;
		std::cin >> input;
		if (input) {
			maxHeap.insert(input);
		}
		else {
			maxHeap.pop();
		}
	}

	return 0;
}