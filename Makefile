CXX=clang++
CXXFLAGS=-g -Wall -std=c++14
INCFLAGS=-Iinclude
VALFLAGS=--leak-check=full --undef-value-errors=no

OBJS=node.o value_node.o sandpile.o random_helper.o sand_node.o
EXAMPLE_SRCS=examples/sandpile_example.cpp

all: all_tests all_examples

all_examples: sandpile_example

sandpile_example: $(EXAMPLE_SRCS) $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCFLAGS) examples/sandpile_example.cpp $(OBJS) -o sandpile_example

memory: tests
	valgrind $(VALFLAGS) ./node_test
	valgrind $(VALFLAGS) ./value_node_test
	valgrind $(VALFLAGS) ./sandpile_test

all_tests: node_test value_node_test sandpile_test linking_test

node_test: $(OBJS) test/node_test.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) test/node_test.cpp $(OBJS) -lboost_unit_test_framework -o node_test
	./node_test

value_node_test: $(OBJS) test/value_node_test.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) test/value_node_test.cpp $(OBJS) -lboost_unit_test_framework -o value_node_test
	./value_node_test

sandpile_test: $(OBJS) test/sandpile_test.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) test/sandpile_test.cpp $(OBJS) -lboost_unit_test_framework -o sandpile_test
	./sandpile_test

linking_test: $(OBJS) test/linking_test.cpp include/linking.hpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) test/linking_test.cpp $(OBJS) -lboost_unit_test_framework -o linking_test
	./linking_test

node.o: src/node.cpp include/node.hpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c src/node.cpp

value_node.o: src/value_node.cpp include/value_node.hpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c src/value_node.cpp

sand_node.o: src/sand_node.cpp include/sand_node.hpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c src/sand_node.cpp

sandpile.o: src/sandpile.cpp include/sandpile.hpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c src/sandpile.cpp

random_helper.o: src/random_helper.cpp include/random_helper.hpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c src/random_helper.cpp

clean:
	rm *.o main *_test *_example

