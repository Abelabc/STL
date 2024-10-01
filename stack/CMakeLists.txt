cmake_minimum_required(VERSION 3.26)
project(stack)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS -fno-elide-constructors)
add_executable(untitled main.cpp stk.h)
