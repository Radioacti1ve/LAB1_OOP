cmake_minimum_required(VERSION 3.0)
project(OOP_LAB2)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

SET(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main main.cpp BitString.h BitString.cpp)

enable_testing()
add_executable(tests tests.cpp BitString.h BitString.cpp)
target_link_libraries(tests ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND tests)