CXX=clang++
CXXFLAGS=-pg -Wall -std=c++14
INCFLAGS=-Iinclude

OBJS=node.o sand.o

# all: src/main.cpp $(OBJS)
#	$(CXX) -o main $(CXXFLAGS) src/main.cpp $(OBJS)

tests: $(TEST_SRCS) $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCFLAGS) test/node_test.cpp $(OBJS) -lboost_unit_test_framework -o node_test
	./node_test
	$(CXX) $(CXXFLAGS) $(INCFLAGS) test/sand_test.cpp $(OBJS) -lboost_unit_test_framework -o sand_test
	./sand_test

node.o: src/node.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c src/node.cpp

sand.o: src/sand.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c src/sand.cpp

clean:
	rm *.o main *_test

