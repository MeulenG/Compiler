# CMakeList.txt : CMake project for Compiler, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_library(Lexer "Lexer.cpp")
add_library(Syntax "Syntax.cpp")
