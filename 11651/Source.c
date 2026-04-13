#include <stdio.h>
#include <stdlib.h>

typedef struct PosXY {
	int x;
	int y;
}PosXY;

int sort(const void* a, const void* b) {
	if (((PosXY*)a)->y != ((PosXY*)b)->y) return ((PosXY*)a)->y - ((PosXY*)b)->y;
	else return ((PosXY*)a)->x - ((PosXY*)b)->x;
}

int main() {
	int N;
	PosXY pos[100000];

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &pos[i].x, &pos[i].y);
	}

	qsort(pos, N, sizeof(PosXY), sort);

	for (int i = 0; i < N; i++) {
		printf("%d %d\n", pos[i].x, pos[i].y);
	}

	return 0;
}