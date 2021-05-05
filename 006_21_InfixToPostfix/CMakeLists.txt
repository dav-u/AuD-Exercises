# CMakeList.txt : CMake project for AuD-Exercises, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (006_21_InfixToPostfix "main.cpp" "infix_to_postfix.cpp" "Operators.cpp" "Lexer.cpp")

# TODO: Add tests and install targets if needed.