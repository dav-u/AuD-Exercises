#include <iostream>

int ggT(int a, int b) {
	int m = a;
	int n = b;
	int r;

	do {
		if (m < n) {
			int temp = m;
			m = n;
			n = temp;
		}

		r = m - n;
		m = n;
		n = r;
	} while (r != 0);

	return m;
}

int main() {
	std::cout << ggT(119, 544) << std::endl;

	return 0;
}