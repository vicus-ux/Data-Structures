cmake_minimum_required(VERSION 3.14)
project(Data_Structures)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(googletest)

include_directories(include)

add_executable(test_structures test/test_structures.cpp)

target_link_libraries(test_structures gtest gtest_main)

enable_testing()
add_test(NAME DataStructuresTests COMMAND test_structures)