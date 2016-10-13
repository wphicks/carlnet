cmake_minimum_required(VERSION 3.5.1)
project (carlnet)

SET(CMAKE_CXX_COMPILER "clang++")
SET(CMAKE_CXX_FLAGS "-Wall -std=c++14")
SET(CMAKE_EXPORT_COMPILE_COMMANDS, "1")
SET(_CMAKE_TOOLCHAIN_PREFIX "llvm-")

SET(PROJECT_BINARY_DIR "${CMAKE_BINARY_DIR}/bin")

SET(carlnet_VERSION_MAJOR 0)
SET(carlnet_VERSION_MINOR 1)
configure_file (
  "include/carlnetConfig.hpp.in"
  "${PROJECT_BINARY_DIR}/carlnetConfig.hpp"
)

include_directories("include" "${PROJECT_BINARY_DIR}")
file(GLOB SOURCES "src/*.cpp")

option(BUILD_TESTS "Build test executables" ON)
option(BUILD_EXAMPLES "Build example executables" ON)


if (BUILD_TESTS)
  add_subdirectory("test")
endif (BUILD_TESTS)

if (BUILD_EXAMPLES)
  add_subdirectory("examples")
endif (BUILD_EXAMPLES)

