#include <iostream>
#include <string>

void printCharArrayIteratively(const char* charArray, int length) {
	for (int i = 0; i < length; i++)
		std::cout << charArray[i];
}

void printCharArrayRecursively(const char* charArray, int length) {
	if (length == 0) return;
	std::cout << *charArray;
	printCharArrayRecursively(charArray + 1, length - 1);
}

int main() {
	std::string text = "Hello World\n";
	std::string text2 = "Hallo Welt\n";

	printCharArrayIteratively(text.c_str(), text.length());
	printCharArrayRecursively(text2.c_str(), text2.length());

	return 0;
}