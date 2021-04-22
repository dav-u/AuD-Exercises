#include <iostream>
#include "Vektor.h"

int main() {
	Vektor v{ 5 };
	v.set(0, 3);
	v.set(1, 5);
	v.set(2, 8);
	v.set(3, 9);
	v.set(4, 12);

	std::cout << v.bin_suche(4) << std::endl;

	return 0;
}