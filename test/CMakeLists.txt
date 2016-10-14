set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
find_package(Boost COMPONENTS unit_test_framework)
add_executable("node_test" "node_test.cpp")
