#include <stdio.h>

template<typename T>
T Min(T a, T b) {
	if (a < b) {
		return a;
	} else {
		return b;
	}
}

int main() {
	int x = 10;
	int y = 20;
	int minInt = Min(x, y);
	printf("X: %d\n", x);
	printf("Y: %d\n", y);
	printf("MinInt: %d\n\n", minInt);

	float p = 5.5f;
	float q = 3.3f;
	float minFloat = Min(p, q);
	printf("P: %.2f\n", p);
	printf("Q: %.2f\n", q);
	printf("MinFloat: %.2f\n\n", minFloat);

	double m = 7.7;
	double n = 9.9;
	double minDouble = Min(m, n);
	printf("M: %.2f\n", m);
	printf("N: %.2f\n", n);
	printf("MinDouble: %.2f\n\n", minDouble);

	return 0;
}