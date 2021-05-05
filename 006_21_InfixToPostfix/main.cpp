#include <iostream>
#include "infix_to_postfix.h"
#include "Lexer.h"

const char* operatorToString(OperatorType type) {
	switch (type)
	{
	case OperatorType::Plus:
		return "Plus+";
	case OperatorType::Minus:
		return "Minus-";
	case OperatorType::Mult:
		return "Mult*";
	case OperatorType::Div:
		return "Div/";
	default:
		return "Invalid?";
	}
}

void printTokens(const std::vector<GenericToken> tokens) {
	for (const GenericToken& token : tokens) {
		switch (token.type)
		{
		case TokenType::ClosedParen:
			std::cout << "<ClosedParen> ";
			break;
		case TokenType::OpenParen:
			std::cout << "<OpenParen> ";
			break;
		case TokenType::NumberLiteral:
			std::cout << "<NumberLiteral(" << token.numericLiteral.data << ")> ";
			break;
		case TokenType::Operator:
			std::cout << "<Operator(" << operatorToString(token.op.data) << ")> ";
			break;
		}
	}

	std::cout << std::endl;
}

void naiveVariant() {
	const char* input = "3*2+5-(3+4)/2";
	//const char* input = "5+(4-2)*2";
	infix_to_postfix(input, std::cout);
	std::cout << std::endl;
}

void lexerVariant() {
	const char* input = "3*2+5-(3+4)/2";
	Lexer lexer{ input };
	auto tokens = infix_to_postfix(lexer);
	printTokens(tokens);
}

void testLexer() {
	const char* input = "32+5()";
	Lexer lexer{ input };
	std::vector<GenericToken> tokens;
	GenericToken token = lexer.getNextToken();
	while (token.type != TokenType::End) {
		tokens.push_back(token);
		token = lexer.getNextToken();
	}

	printTokens(tokens);
}

int main() {
	naiveVariant();
	lexerVariant();
	//testLexer();

	return 0;
}