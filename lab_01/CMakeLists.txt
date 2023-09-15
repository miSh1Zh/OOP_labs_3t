cmake_minimum_required(VERSION 3.10)
project(lab_01)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(prog src/main.cpp src/function.cpp)


enable_testing()
add_executable(tests tests.cpp  src/function.cpp)
target_link_libraries(tests ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND tests)

