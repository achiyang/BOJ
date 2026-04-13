#include <stdio.h>
#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct Pair {
	int first;
	int second;
} Pair;

static void buildTree(Pair *tree, int index, int *arr, int start, int end) {
	if (start == end) {
		tree[index].first = tree[index].second = arr[start];
	}
	else {
		int mid = (start + end) / 2;
		buildTree(tree, 2 * index + 1, arr, start, mid);
		buildTree(tree, 2 * index + 2, arr, mid + 1, end);
		tree[index].first = MIN(tree[2 * index + 1].first, tree[2 * index + 2].first);
		tree[index].second = MAX(tree[2 * index + 1].second, tree[2 * index + 2].second);
	}
}

static Pair *createTree(int *arr, int len) {
	int size = 1;

	while (size < len) {
		size <<= 1;
	}
	size <<= 1;

	Pair *tree = (Pair *)malloc(sizeof(Pair) * size);

	buildTree(tree, 0, arr, 0, len - 1);

	return tree;
}

static Pair query(Pair *tree, int index, int start, int end, int l, int r) {
	if (r < start || end < l) return (Pair) { -1, -1 };
	if (l <= start && end <= r) return tree[index];

	int mid = (start + end) / 2;
	Pair left = query(tree, 2 * index + 1, start, mid, l, r);
	Pair right = query(tree, 2 * index + 2, mid + 1, end, l, r);

	Pair ret;
	if (left.first != -1 && left.second != -1) {
		ret = left;
		if (right.first != -1 || right.second != -1) {
			ret.first = MIN(ret.first, right.first);
			ret.second = MAX(ret.second, right.second);
		}
	}
	else {
		ret = right;
	}

	return ret;
}

int main() {
	int N, M, l, r, *arr;

	scanf("%d %d", &N, &M);

	arr = (int *)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	Pair *tree = createTree(arr, N);

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &l, &r);

		Pair pair = query(tree, 0, 0, N - 1, l - 1, r - 1);

		printf("%d %d\n", pair.first, pair.second);
	}

	return 0;
}
