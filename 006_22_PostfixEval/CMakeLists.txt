# CMakeList.txt : CMake project for AuD-Exercises, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (006_22_PostfixEval
	"main.cpp"
	"../006_21_InfixToPostfix/infix_to_postfix.cpp"
	"../006_21_InfixToPostfix/Lexer.cpp"
	"../006_21_InfixToPostfix/Operators.cpp"
	)

# TODO: Add tests and install targets if needed.