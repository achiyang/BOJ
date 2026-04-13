#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

class AbsHeap {
private:
	std::vector<int> heap;

	int parent(int i) { return (i - 1) / 2; }
	int leftChild(int i) { return 2 * i + 1; }
	int rightChild(int i) { return 2 * i + 2; }

	void heapifyUp(int i) {
		while (i > 0) {
			int parentIndex = parent(i);
			int absI = std::abs(heap[i]);
			int absParent = std::abs(heap[parentIndex]);

			if (absI < absParent || (absI == absParent && heap[i] < heap[parentIndex])) {
				std::swap(heap[i], heap[parentIndex]);
				i = parentIndex;
			}
			else {
				break;
			}
		}
	}

	void heapifyDown(int i) {
		int minIndex = i;
		int left = leftChild(i);
		int right = rightChild(i);

		if (left < heap.size()) {
			int absLeft = std::abs(heap[left]);
			int absMin = std::abs(heap[minIndex]);

			if (absLeft < absMin || (absLeft == absMin && heap[left] < heap[minIndex])) {
				minIndex = left;
			}
		}

		if (right < heap.size()) {
			int absRight = std::abs(heap[right]);
			int absMin = std::abs(heap[minIndex]);

			if (absRight < absMin || (absRight == absMin && heap[right] < heap[minIndex])) {
				minIndex = right;
			}
		}

		if (minIndex != i) {
			std::swap(heap[i], heap[minIndex]);
			heapifyDown(minIndex);
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

		int min = heap[0];
		heap[0] = heap.back();
		heap.pop_back();
		heapifyDown(0);

		std::cout << min << '\n';
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	AbsHeap absHeap;

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		int input;
		std::cin >> input;
		if (input) {
			absHeap.insert(input);
		}
		else {
			absHeap.pop();
		}
	}

	return 0;
}