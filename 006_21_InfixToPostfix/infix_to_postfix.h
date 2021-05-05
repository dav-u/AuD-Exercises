#pragma once
#include <iostream>
#include <vector>
#include "Lexer.h"

void infix_to_postfix(const char* infix_expression, std::ostream& output);
std::vector<GenericToken> infix_to_postfix(Lexer& lexer);
