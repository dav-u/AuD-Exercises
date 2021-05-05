#pragma once
#include <unordered_map>

enum class OperatorType {
	Plus, Minus, Mult, Div
};

class Operators {
	struct OperatorsStaticMembers {
		OperatorsStaticMembers() : operator_priority_map({
			{ OperatorType::Plus, 1 },
			{ OperatorType::Minus, 1 },
			{ OperatorType::Mult, 2 },
			{ OperatorType::Div, 2 }
			}),
			operator_type_map({
			{ '+', OperatorType::Plus },
			{ '-', OperatorType::Minus },
			{ '*', OperatorType::Mult },
			{ '/', OperatorType::Div }
			}) { }
		std::unordered_map<OperatorType, int> operator_priority_map;
		std::unordered_map<char, OperatorType> operator_type_map;
	};

public:
	static bool contains(char c);
	static bool same_or_higher_priority(char first, char second);
	static bool contains(OperatorType type);
	static bool same_or_higher_priority(OperatorType first, OperatorType second);
	static OperatorType convert_char_to_type(char c);

private:
	static OperatorsStaticMembers m_static;
};
