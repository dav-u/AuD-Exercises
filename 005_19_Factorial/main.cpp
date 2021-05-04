#include <iostream>

int fact_it(int n) {
	int result = 1;
	
	for (int i = 2; i <= n; i++)
		result *= i;

	return result;
}

int main() {
	std::cout << fact_it(4) << std::endl;
	return 0;
}