cmake_minimum_required(VERSION 3.14)
project(Data_Structures)

set(CMAKE_CXX_STANDARD 17)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

#add_subdirectory(googletest)
include(FetchContent)
FetchContent_Declare(
  googletest1
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest1)



include_directories(include)

add_executable(test_structures test/test_structures.cpp)

target_link_libraries(test_structures gtest gtest_main)

enable_testing()
add_test(NAME DataStructuresTests COMMAND test_structures)