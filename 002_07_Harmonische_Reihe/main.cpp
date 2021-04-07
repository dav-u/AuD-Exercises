#include <iostream>

double harmonic_series_recursive(int n) {
	if (n == 1) return 1;
	return 1.0 / n + harmonic_series_recursive(n - 1);
}

double harmonic_series_iterative(int n) {
	double result = 0;

	for (int i = 1; i <= n; i++)
		result += 1.0 / i;

	return result;
}

int main() {
	std::cout << harmonic_series_recursive(3) << std::endl;
	std::cout << harmonic_series_iterative(7) << std::endl;

	return 0;
}