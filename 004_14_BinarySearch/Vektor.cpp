#include "Vektor.h"
#include <stdexcept>

Vektor::Vektor(int dim)
	: dimension(dim), daten(new int[dim]) { }

Vektor::~Vektor() {
	delete[] daten;
}

void Vektor::set(int i, int val) {
	if (i < 0 || i >= dimension)
		throw std::out_of_range("index out of range");
	daten[i] = val;
}

int Vektor::get(int i) {
	if (i < 0 || i >= dimension)
		throw std::out_of_range("index out of range");

	return daten[i];
}

int Vektor::bin_suche(int sw) {
	int l_u = 0, l_o = dimension - 1; // untere und obere Grenze des Sucharrays
	// 0 1 2 3 4
	// 0 1     2     3 4
	// 0   1
	//     1


	// 0 1 2 3
	// 0    1    2 3
	// 
	while (l_u < l_o) {
		int middle = (l_u + l_o) / 2;
		int element = daten[middle];
		if (element == sw) return middle;
		else if (sw < element) {
			l_o = middle - 1;
		}
		else {
			l_u = middle + 1;
		}
	}
	if (daten[l_u] == sw) return l_u;
	else return -1;
}
