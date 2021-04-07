#include <iostream>

int recursive(int n) {
	if (n <= 2) return 1;
	return n * recursive(n - 1) - recursive(n - 2);
}

int iterative(int n) {
	if (n <= 2) return 1;
	int prev = 1, prevprev = 1;
	int result;
	for (int i = 3; i <= n; i++) {
		result = i * prev - prevprev;
		prevprev = prev;
		prev = result;
	}

	return result;
}

int main() {
	std::cout << recursive(5) << std::endl;
	std::cout << iterative(5) << std::endl;
	
	return 0;
}