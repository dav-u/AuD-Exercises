#include <cstdio>

double piRecursive(int n) {
	if (n >= 4) return 1.0;
	return 1 + piRecursive(n + 1) * n / (2*n + 1);
}

double piIterative(int n) {
	double prev = 1.0;

	for (int i = n; i > 0; i--)
		prev = 1 + i / (2.0 * i + 1) * prev;

	return prev;
}

void main() {
	double pi = 2 * piIterative(10);
	printf("Die ersten Stellen von Pi: %.10lf", pi);
}