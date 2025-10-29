cmake_minimum_required(VERSION 3.14)
project(Data_Structures)

set(CMAKE_CXX_STANDARD 17)

# Добавляем папку gtest как подпроект
add_subdirectory(gtest)

# Директории с заголовочными файлами
include_directories(include)
include_directories(gtest)  # Добавляем путь к gtest.h

# Исполняемый файл тестов
add_executable(test_structures test/test_structures.cpp)

# Линковка с Google Test
target_link_libraries(test_structures gtest)

enable_testing()
add_test(NAME DataStructuresTests COMMAND test_structures)