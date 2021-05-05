#include <stdexcept>
#include "Operators.h"

Operators::OperatorsStaticMembers Operators::m_static;

bool Operators::contains(char c) {
	return m_static.operator_type_map.find(c) != m_static.operator_type_map.end();
}

bool Operators::same_or_higher_priority(char first, char second) {
	auto second_it = m_static.operator_type_map.find(second);
	if (second_it == m_static.operator_type_map.end()) return false;

	// we expect an entry here
	OperatorType first_type = m_static.operator_type_map.find(first)->second;
	OperatorType second_type = second_it->second;

	return same_or_higher_priority(first_type, second_type);
}

bool Operators::contains(OperatorType type) {
	return m_static.operator_priority_map.find(type) != m_static.operator_priority_map.end();
}

bool Operators::same_or_higher_priority(OperatorType first, OperatorType second) {
	return
		m_static.operator_priority_map.find(second)->second
		>= m_static.operator_priority_map.find(first)->second;
}

OperatorType Operators::convert_char_to_type(char c) {
	auto it = m_static.operator_type_map.find(c);
	if (it == m_static.operator_type_map.end())
		throw std::logic_error("No type found for specified char");

	return it->second;
}
