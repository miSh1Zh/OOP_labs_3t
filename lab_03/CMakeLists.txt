cmake_minimum_required(VERSION 3.10)
project(lab_03)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SCR scr/Array.cpp scr/Figure.cpp scr/Point.cpp scr/Rectangle.cpp scr/Square.cpp scr/Triangle.cpp)

add_executable(prog main.cpp scr/Array.cpp scr/Figure.cpp scr/Point.cpp scr/Rectangle.cpp scr/Square.cpp scr/Triangle.cpp)

enable_testing()
add_executable(tests test.cpp scr/Array.cpp scr/Figure.cpp scr/Point.cpp scr/Rectangle.cpp scr/Square.cpp scr/Triangle.cpp)
target_link_libraries(tests ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND tests)
