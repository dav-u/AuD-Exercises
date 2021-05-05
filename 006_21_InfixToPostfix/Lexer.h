#pragma once
#include "Operators.h"

enum class TokenType {
	NumberLiteral, Operator, OpenParen, ClosedParen, End
};

struct NumberLiteralToken {
	TokenType type = TokenType::NumberLiteral;
};

union GenericToken;

template <TokenType T, typename D>
struct Token {
	TokenType type = T;
	D data;
	operator GenericToken();
};

using NumericLiteralToken = Token<TokenType::NumberLiteral, float>;
using OperatorToken = Token<TokenType::Operator, OperatorType>;

union GenericToken {
	TokenType type;
	NumericLiteralToken numericLiteral;
	OperatorToken op;
};

template<TokenType T, typename D>
Token<T, D>::operator GenericToken()
{
	return *reinterpret_cast<GenericToken*>(this);
}

const GenericToken OpenParenToken = GenericToken{ .type = TokenType::OpenParen };
const GenericToken ClosedParenToken = GenericToken{ .type = TokenType::ClosedParen };
const GenericToken EndToken = GenericToken{ .type = TokenType::End };

class Lexer {
public:
	Lexer(const char* source);
	const GenericToken getNextToken();

private:
	char getNextChar();

	const char* m_source;
	unsigned int m_scanIndex = 0;
};
