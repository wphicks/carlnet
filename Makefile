CXX=clang++
CXXFLAGS=-g -Wall -std=c++14
INCFLAGS=-Iinclude
VALFLAGS=--leak-check=full --undef-value-errors=no

OBJS=node.o sandpile.o random_helper.o sand_node.o
EXAMPLE_SRCS=examples/sandpile_example.cpp

all: all_tests all_examples

all_examples: sandpile_example

sandpile_example: $(EXAMPLE_SRCS) $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCFLAGS) examples/sandpile_example.cpp $(OBJS) -o sandpile_example

memory: tests
	valgrind $(VALFLAGS) ./node_test
	valgrind $(VALFLAGS) ./value_node_test
	valgrind $(VALFLAGS) ./sandpile_test

all_tests: node_test value_node_test sand_node_test sandpile_test linking_test

node_test: node.o test/node_test.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) test/node_test.cpp node.o -lboost_unit_test_framework -o node_test
	./node_test

value_node_test: node_test include/value_node.hpp test/value_node_test.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) test/value_node_test.cpp node.o -lboost_unit_test_framework -o value_node_test
	./value_node_test

sand_node_test: value_node_test sand_node.o test/sand_node_test.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) test/sand_node_test.cpp node.o sand_node.o -lboost_unit_test_framework -o sand_node_test
	./sand_node_test

sandpile_test: sand_node_test sandpile.o random_helper.o test/sandpile_test.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) test/sandpile_test.cpp node.o sand_node.o random_helper.o sandpile.o -lboost_unit_test_framework -o sandpile_test
	./sandpile_test

linking_test: sandpile_test test/linking_test.cpp include/linking.hpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) test/linking_test.cpp node.o sand_node.o random_helper.o sandpile.o -lboost_unit_test_framework -o linking_test
	./linking_test

node.o: src/node.cpp include/node.hpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c src/node.cpp

sand_node.o: src/sand_node.cpp include/sand_node.hpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c src/sand_node.cpp

sandpile.o: src/sandpile.cpp include/sandpile.hpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c src/sandpile.cpp

random_helper.o: src/random_helper.cpp include/random_helper.hpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c src/random_helper.cpp

clean:
	rm -f *.o *_test *_example

