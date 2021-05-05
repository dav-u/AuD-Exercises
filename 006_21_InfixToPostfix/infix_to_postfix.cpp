#include <iostream>
#include <unordered_map>
#include "../006_20_Stack/Stack.h"

class Operators {
	struct OperatorsStaticMembers {
		OperatorsStaticMembers() : operator_priority_map({
			{ '+', 1 },
			{ '-', 1 },
			{ '*', 2 },
			{ '/', 2 }
			}) { }
		std::unordered_map<char, int> operator_priority_map;
	};

public:
	static bool contains(char c) {
		return m_static.operator_priority_map.find(c) != m_static.operator_priority_map.end();
	}

	static bool same_or_higher_priority(char first, char second) {
		auto second_it = m_static.operator_priority_map.find(second);
		if (second_it == m_static.operator_priority_map.end()) return false;
		return
			second_it->second
			>= m_static.operator_priority_map.find(first)->second;
	}
private:
	static OperatorsStaticMembers m_static;
};

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

Operators::OperatorsStaticMembers Operators::m_static;
