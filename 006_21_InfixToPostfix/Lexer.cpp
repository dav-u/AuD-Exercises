#include <stdexcept>
#include "Lexer.h"
#include "Operators.h"

Lexer::Lexer(const char* source) : m_source(source) {}

static bool isDigit(char c) {
	return c >= '0' && c <= '9';
}

const GenericToken Lexer::getNextToken() {
	char current_char = getNextChar();
	if (current_char == '(')
		return OpenParenToken;
	else if (current_char == ')')
		return ClosedParenToken;
	else if (current_char == '\0')
		return EndToken;
	else if (Operators::contains(current_char)) {
		OperatorType opType = Operators::convert_char_to_type(current_char);
		//return GenericToken{ .op = OperatorToken{.data = opType } };
		return OperatorToken{.data = opType };
	}
	else if (isDigit(current_char)) {
		std::string num;
		num.push_back(current_char);
		bool allowDot = true;

		while (true) {
			current_char = getNextChar();

			if (current_char == '.' && allowDot) {
				allowDot = false;
			}
			else if (!isDigit(current_char)) {
				m_scanIndex--;
				break;
			}

			num.push_back(current_char);
		}

		float result = std::atof(num.c_str());
		return NumericLiteralToken{.data = result };
	}
	else throw std::logic_error("Unknown symbol");
}

char Lexer::getNextChar() {
	return m_source[m_scanIndex++];
}
