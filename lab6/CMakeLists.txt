cmake_minimum_required(VERSION 3.10)
project(OOP_LAB6)
set(CMAKE_CXX_STANDARD 20)


add_subdirectory(googletest)

add_executable(main main.cpp factory.cpp npc.cpp observer.cpp Knight.cpp SlaveSaler.cpp Squirrel.cpp)

add_executable(tests tests.cpp factory.cpp npc.cpp observer.cpp Knight.cpp SlaveSaler.cpp Squirrel.cpp)

target_link_libraries(tests PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)