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

double evalPostfix(const std::vector<GenericToken>& tokens) {
	Stack<double> stack;

	for (const GenericToken& token : tokens) {
		if (token.type == TokenType::NumberLiteral)
			stack.push(token.numericLiteral.data);
		else {
			double second = stack.pop();
			double first = stack.pop();

			switch (token.op.data)
			{
			case OperatorType::Plus:
				stack.push(first + second);
				break;
			case OperatorType::Minus:
				stack.push(first - second);
				break;
			case OperatorType::Mult:
				stack.push(first * second);
				break;
			case OperatorType::Div:
				stack.push(first / second);
				break;
			}
		}
	}

	return stack.pop();
}

void testNaive() {
	const char* input = "3*2+5-(3+4)/2"; // = 11-3.5 = 7.5
	std::stringstream ss;
	infix_to_postfix(input, ss);

	std::string converted_string = ss.str();
	std::cout << "postfix: " << converted_string << std::endl;

	std::cout << evalPostfix(converted_string.c_str()) << std::endl;
}

void testLexer() {
	//const char* input = "3*2+5-(3+4)/2"; // = 11-3.5 = 7.5
	const char* input = "25-23"; // = 2
	Lexer lexer{ input };
	auto tokens = infix_to_postfix(lexer);

	double result = evalPostfix(tokens);

	std::cout << result << std::endl;
}

int main() {
	testLexer();

	return 0;
}