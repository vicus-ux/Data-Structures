# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "C:/gitprojs/Data-Structures/build/_deps/googletest1-src")
  file(MAKE_DIRECTORY "C:/gitprojs/Data-Structures/build/_deps/googletest1-src")
endif()
file(MAKE_DIRECTORY
  "C:/gitprojs/Data-Structures/build/_deps/googletest1-build"
  "C:/gitprojs/Data-Structures/build/_deps/googletest1-subbuild/googletest1-populate-prefix"
  "C:/gitprojs/Data-Structures/build/_deps/googletest1-subbuild/googletest1-populate-prefix/tmp"
  "C:/gitprojs/Data-Structures/build/_deps/googletest1-subbuild/googletest1-populate-prefix/src/googletest1-populate-stamp"
  "C:/gitprojs/Data-Structures/build/_deps/googletest1-subbuild/googletest1-populate-prefix/src"
  "C:/gitprojs/Data-Structures/build/_deps/googletest1-subbuild/googletest1-populate-prefix/src/googletest1-populate-stamp"
)

set(configSubDirs Debug)
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/gitprojs/Data-Structures/build/_deps/googletest1-subbuild/googletest1-populate-prefix/src/googletest1-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/gitprojs/Data-Structures/build/_deps/googletest1-subbuild/googletest1-populate-prefix/src/googletest1-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
