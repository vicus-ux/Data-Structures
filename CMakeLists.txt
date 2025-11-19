cmake_minimum_required(VERSION 3.14)
project(Data_Structures)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

include_directories(include)
include_directories(${googletest_SOURCE_DIR}/googletest/include)

# Основное приложение со ВСЕМИ тестами
add_executable(Main_app 
    Main/Main.cpp
    test/test_structures.cpp      # ← ДОБАВЬТЕ тестовые файлы
    test/testForwardList.cpp      # ← ДОБАВЬТЕ тестовые файлы
)
target_link_libraries(Main_app gtest gtest_main)

# Отдельные тестовые исполняемые файлы (опционально)
add_executable(test_structures test/test_structures.cpp)
target_link_libraries(test_structures gtest gtest_main)

add_executable(test_forwardlist test/testForwardList.cpp)
target_link_libraries(test_forwardlist gtest gtest_main)

enable_testing()
add_test(NAME DataStructuresTests COMMAND test_structures)
add_test(NAME ForwardListTests COMMAND test_forwardlist)
add_test(NAME AllTests COMMAND Main_app)