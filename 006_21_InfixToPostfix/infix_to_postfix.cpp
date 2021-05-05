#include <unordered_map>
#include "Lexer.h"
#include "infix_to_postfix.h"
#include "Operators.h"
#include "../006_20_Stack/Stack.h"

static bool isDigit(char c) {
	return c >= '0' && c <= '9';
}

void infix_to_postfix(const char* infix_expression, std::ostream& output) {
	Stack<char> stack;
	
	for (int i = 0; infix_expression[i] != '\0'; i++) {
		char current_char = infix_expression[i];
		if (current_char == '(') {
			stack.push('(');
		}
		else if (isDigit(current_char)) {
			output << current_char;
		}
		else if (Operators::contains(current_char)) {
			while (!stack.empty() && Operators::same_or_higher_priority(current_char, stack.top())) {
				output << stack.pop();
			}
			stack.push(current_char);
		}
		else if (current_char == ')') {
			while (stack.top() != '(') {
				output << stack.pop();
			}
			stack.pop();
		}
	}

	while (!stack.empty()) {
		output << stack.pop();
	}
}

std::vector<GenericToken> infix_to_postfix(Lexer& lexer) {
	Stack<GenericToken> stack;
	std::vector<GenericToken> output;

	GenericToken token = lexer.getNextToken();
	while (token.type != TokenType::End) {
		if (token.type == TokenType::OpenParen)
			stack.push(token);
		else if (token.type == TokenType::NumberLiteral) {
			output.push_back(token);
		}
		else if (token.type == TokenType::Operator) {
			while (true) {
				if (stack.empty()
					|| stack.top().type != TokenType::Operator
					|| !Operators::same_or_higher_priority(token.op.data, stack.top().op.data))
					break;

				output.push_back(stack.pop());
			}
			stack.push(token);
		}
		else if (token.type == TokenType::ClosedParen) {
			while (stack.top().type != TokenType::OpenParen)
				output.push_back(stack.pop());

			stack.pop();
		}

		token = lexer.getNextToken();
	}

	while (!stack.empty()) {
		output.push_back(stack.pop());
	}

	return output;
}

