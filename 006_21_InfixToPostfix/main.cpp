#include <iostream>
#include "infix_to_postfix.h"

int main() {
	const char* input = "3*2+5-(3+4)/2";
	//const char* input = "5+(4-2)*2";
	infix_to_postfix(input, std::cout);

	return 0;
}