cmake_minimum_required(VERSION 3.10)
project(OOP_LAB2)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDART 20)
SET(CMAKE_CXX_STANDART_REQUIRED ON)

add_executable(main main.cpp BitString.h)

enable_testing()
add_executable(tests tests.cpp BitString.h)
target_link_libraries(tests ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND tests)