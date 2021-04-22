#include <iostream>
#include <chrono>

unsigned long long fibRec(int n) {
	if (n <= 2)
		return 1;

	return fibRec(n - 1) + fibRec(n - 2);
}

unsigned long long fibIt(int n) {
	if (n <= 2) return 1;

	unsigned long long* fibonacci_numbers = new unsigned long long[n + 1];
	fibonacci_numbers[1] = 1u;
	fibonacci_numbers[2] = 1u;

	for (int i = 3; i <= n; i++)
		fibonacci_numbers[i] = fibonacci_numbers[i - 1] + fibonacci_numbers[i - 2];

	unsigned long long result = fibonacci_numbers[n];

	delete[] fibonacci_numbers;

	return result;
}

unsigned int fibIt2(int n) {
	unsigned long long prevprev = 1;
	unsigned long long prev = 1;
	unsigned long long result = 1;

	for (unsigned int i = 3; i <= n; i++) {
		result = prev + prevprev;
		prevprev = prev;
		prev = result;
	}

	return result;
}

void measureFib(unsigned long long (*fib)(int n)) {
	int ms;
	int n = 1;

	do {
		auto start = std::chrono::high_resolution_clock::now();

		// code
		fib(n);

		auto end = std::chrono::high_resolution_clock::now();
		auto duration = end - start;
		ms = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
		std::cout << n << ": " << ms << std::endl;
		n++;
	} while (ms < 1000);
}

void measureFibIt(unsigned long long (*fib)(int n)) {
	int ms;
	int n = 10;
	double T = 1000;

	do {
		auto start = std::chrono::high_resolution_clock::now();

		fib(n);

		auto end = std::chrono::high_resolution_clock::now();
		auto duration = end - start;
		ms = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
		std::cout << n << ": " << ms << std::endl;
		n *= T / (ms == 0 ? 1 : ms);
	} while (ms < T);
}

int main() {
	/*for (int i = 1; i < 20; i++) {
		std::cout << i << ": " << fibIt2(i) << std::endl;
	}*/

	std::cout << "It:" << std::endl;

	//measureFib(fibIt);
	measureFibIt(fibIt);
	
	return 0;
}