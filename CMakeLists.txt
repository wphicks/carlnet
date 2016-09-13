cmake_minimum_required(VERSION 3.5.1)
project (carlnet)

SET(CMAKE_CXX_COMPILER "clang++")
SET(CMAKE_CXX_FLAGS "-Wall -std=c++14")
SET(CMAKE_EXPORT_COMPILE_COMMANDS, "1")
SET(_CMAKE_TOOLCHAIN_PREFIX "llvm-")

include_directories(include)

file(GLOB TEST_SRCS "test/*_test.cpp")
file(GLOB SRCS "src/*.cpp")

add_executable(run_tests ${SRCS} ${TEST_SRCS})
