# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("AuD-Exercises")

# Include sub-projects.
add_subdirectory ("001_01_Collatz")
add_subdirectory ("001_02_Hanoi")
add_subdirectory ("002_05")
add_subdirectory ("002_06_ggT")
add_subdirectory ("002_07_Harmonische_Reihe")
add_subdirectory ("003_08_PI")
add_subdirectory ("003_09_PrintCharArray")
add_subdirectory ("004_13_Fibonacci")
add_subdirectory ("004_14_BinarySearch")
add_subdirectory ("004_15")

