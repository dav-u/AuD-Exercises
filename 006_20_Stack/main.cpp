#include <iostream>
#include "Stack.h"

int main() {
	Stack<int> stack;
	std::cout << "empty: " << stack.empty() << std::endl;
	std::cout << "length: " << stack.length() << std::endl;
	std::cout << "pushing 5" << std::endl;
	stack.push(5);
	std::cout << "empty: " << stack.empty() << std::endl;
	std::cout << "length: " << stack.length() << std::endl;
	std::cout << "top: " << stack.top() << std::endl;
	std::cout << "empty: " << stack.empty() << std::endl;
	std::cout << "length: " << stack.length() << std::endl;
	std::cout << "pop: " << stack.pop() << std::endl;
	std::cout << "empty: " << stack.empty() << std::endl;
	std::cout << "length: " << stack.length() << std::endl;
	std::cout << "pushing 4" << std::endl;
	stack.push(4);
	std::cout << "pushing 3" << std::endl;
	stack.push(3);
	std::cout << "length: " << stack.length() << std::endl;
	std::cout << "top: " << stack.top() << std::endl;
	std::cout << "pop: " << stack.pop() << std::endl;
	std::cout << "top: " << stack.top() << std::endl;

	return 0;
}