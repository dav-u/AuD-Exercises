#include <iostream>
#include <sstream>
#include <string>
#include "../006_20_Stack/Stack.h"
#include "../006_21_InfixToPostfix/infix_to_postfix.h"

static bool isDigit(const char c) {
	return c >= '0' && c <= '9';
}

double evalPostfix(const char* expression) {
	Stack<double> stack;

	for (int i = 0; expression[i] != '\0'; i++) {
		const char current_char = expression[i];

		if (isDigit(current_char)) {
			stack.push(current_char - '0');
		}
		else {
			double second = stack.pop();
			double first = stack.pop();
			if (current_char == '+') {
				stack.push(first + second);
			}
			else if (current_char == '-') {
				stack.push(first - second);
			}
			else if (current_char == '*') {
				stack.push(first * second);
			}
			else if (current_char == '/') {
				stack.push(first / second);
			}
		}
	}

	return stack.pop();
}

int main() {
	const char* input = "3*2+5-(3+4)/2"; // = 11-3.5 = 7.5
	std::stringstream ss;
	infix_to_postfix(input, ss);

	std::string converted_string = ss.str();
	std::cout << "postfix: " << converted_string << std::endl;

	std::cout << evalPostfix(converted_string.c_str()) << std::endl;

	return 0;
}