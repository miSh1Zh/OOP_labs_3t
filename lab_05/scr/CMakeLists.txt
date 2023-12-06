cmake_minimum_required(VERSION 3.14)
project(lab_05)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -Wall")
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(prog main.cpp)

enable_testing()
add_executable(tests test.cpp)
target_link_libraries(tests ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND tests)
