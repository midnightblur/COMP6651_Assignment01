cmake_minimum_required(VERSION 3.8)
project(COMP6651_Assignment01)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES driver.cpp BKTree.cpp BKTree.h Levenshtein.cpp Levenshtein.h)
add_executable(COMP6651_Assignment01 ${SOURCE_FILES})