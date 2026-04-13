#include <stdio.h>

typedef struct Point {
	int x;
	int y;
} Point;

typedef struct Line {
	Point a;
	Point b;
} Line;

int isDivPoints(Line l, Point a, Point b) {
	long long f1 = (long long)(l.b.x - l.a.x) * (a.y - l.a.y) - (long long)(l.b.y - l.a.y) * (a.x - l.a.x);
	long long f2 = (long long)(l.b.x - l.a.x) * (b.y - l.a.y) - (long long)(l.b.y - l.a.y) * (b.x - l.a.x);

	return (f1 < 0 && f2 > 0) || (f1 > 0 && f2 < 0);
}

int main() {
	Line l1, l2;

	scanf("%d %d %d %d", &l1.a.x, &l1.a.y, &l1.b.x, &l1.b.y);
	scanf("%d %d %d %d", &l2.a.x, &l2.a.y, &l2.b.x, &l2.b.y);

	if (isDivPoints(l1, l2.a, l2.b) && isDivPoints(l2, l1.a, l1.b)) {
		printf("1");
	}
	else {
		printf("0");
	}

	return 0;
}
