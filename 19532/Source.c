#include <stdio.h>
#include <math.h>

int gcd(int a, int b) {
	while (b) {
		int temp = a % b;
		a = b;
		b = temp;
	}
	return abs(a);
}

int lcm(int a, int b) {
	return abs(a * b / gcd(a, b));
}

int main() {
	int a, b, c, d, e, f, x, y;

	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

	if (a == 0) {
		y = c / b;
		x = (f - e * y) / d;
	}
	else if (b == 0) {
		x = c / a;
		y = (f - d * x) / e;
	}
	else if (d == 0) {
		y = f / e;
		x = (c - b * y) / a;
	}
	else if (e == 0) {
		x = f / d;
		y = (c - a * x) / b;
	}
	else {
		int lcm_ = lcm(a, d);

		b *= lcm_ / a;
		c *= lcm_ / a;
		e *= lcm_ / d;
		f *= lcm_ / d;
		a = d = lcm_;

		y = (c - f) / (b - e);
		x = (c - b * y) / a;
	}

	printf("%d %d\n", x, y);

	return 0;
}