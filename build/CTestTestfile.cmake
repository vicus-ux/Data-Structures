# CMake generated Testfile for 
# Source directory: C:/gitprojs/Data-Structures
# Build directory: C:/gitprojs/Data-Structures/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(DataStructuresTests "C:/gitprojs/Data-Structures/build/Debug/test_structures.exe")
  set_tests_properties(DataStructuresTests PROPERTIES  _BACKTRACE_TRIPLES "C:/gitprojs/Data-Structures/CMakeLists.txt;26;add_test;C:/gitprojs/Data-Structures/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(DataStructuresTests "C:/gitprojs/Data-Structures/build/Release/test_structures.exe")
  set_tests_properties(DataStructuresTests PROPERTIES  _BACKTRACE_TRIPLES "C:/gitprojs/Data-Structures/CMakeLists.txt;26;add_test;C:/gitprojs/Data-Structures/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(DataStructuresTests "C:/gitprojs/Data-Structures/build/MinSizeRel/test_structures.exe")
  set_tests_properties(DataStructuresTests PROPERTIES  _BACKTRACE_TRIPLES "C:/gitprojs/Data-Structures/CMakeLists.txt;26;add_test;C:/gitprojs/Data-Structures/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(DataStructuresTests "C:/gitprojs/Data-Structures/build/RelWithDebInfo/test_structures.exe")
  set_tests_properties(DataStructuresTests PROPERTIES  _BACKTRACE_TRIPLES "C:/gitprojs/Data-Structures/CMakeLists.txt;26;add_test;C:/gitprojs/Data-Structures/CMakeLists.txt;0;")
else()
  add_test(DataStructuresTests NOT_AVAILABLE)
endif()
subdirs("_deps/googletest1-build")
