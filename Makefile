CXX=clang++
CXXFLAGS=-g -Wall -std=c++14
INCFLAGS=-Iinclude
VALFLAGS=--leak-check=full --undef-value-errors=no

OBJS=node.o sand.o sandpile.o random_helper.o
EXAMPLE_SRCS=examples/sandpile_example.cpp

all: all_tests all_examples

all_examples: sandpile_example

sandpile_example: $(EXAMPLE_SRCS) $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCFLAGS) examples/sandpile_example.cpp $(OBJS) -o sandpile_example

memory: tests
	valgrind $(VALFLAGS) ./node_test
	valgrind $(VALFLAGS) ./sand_test
	valgrind $(VALFLAGS) ./sandpile_test

all_tests: node_test sand_test sandpile_test linking_test

node_test: $(OBJS) test/node_test.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) test/node_test.cpp $(OBJS) -lboost_unit_test_framework -o node_test
	./node_test

sand_test: $(OBJS) test/sand_test.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) test/sand_test.cpp $(OBJS) -lboost_unit_test_framework -o sand_test
	./sand_test

sandpile_test: $(OBJS) test/sandpile_test.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) test/sandpile_test.cpp $(OBJS) -lboost_unit_test_framework -o sandpile_test
	./sandpile_test

linking_test: $(OBJS) test/linking_test.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) test/linking_test.cpp $(OBJS) -lboost_unit_test_framework -o linking_test
	./linking_test

node.o: src/node.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c src/node.cpp

sand.o: src/sand.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c src/sand.cpp

sandpile.o: src/sandpile.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c src/sandpile.cpp

random_helper.o: src/random_helper.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c src/random_helper.cpp

clean:
	rm *.o main *_test *_example

