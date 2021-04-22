#include <iostream>

int T(int n) {
	if (n == 1) return 1;
	return n * T(n - 1) + n;
}

int T_it(int n) {
	int result = 1;

	for (int i = 2; i <= n; i++)
		result = i * result + i;

	return result;
}

int main() {
	for (int i = 1; i <= 10; i++) {
		std::cout << T(i) << std::endl;
		std::cout << T_it(i) << std::endl;
	}
	return 0;
}