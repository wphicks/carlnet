CXX=clang++
CXXFLAGS=-pg -Wall -std=c++14
INCFLAGS=-Isrc
TEST_SRCS=test/*_test.cpp

OBJS=node.o

# all: src/main.cpp $(OBJS)
#	$(CXX) -o main $(CXXFLAGS) src/main.cpp $(OBJS)

tests: $(TEST_SRCS) $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCFLAGS) $(TEST_SRCS) $(OBJS) -lboost_unit_test_framework -o run_tests

node.o: src/node.cpp
	$(CXX) $(CXXFLAGS) -c src/node.cpp

sand.o: src/sand.cpp
	$(CXX) $(CXXFLAGS) -c src/sand.cpp

clean:
	rm *.o main run_tests

