CXX = g++
CXXFLAGS = -std=c++11 -I .

SRCS = Demo.cpp
OBJS = $(SRCS:.cpp=.o)

tree_example: $(OBJS)
	$(CXX) -o $@ $^

clean:
	rm -f *.o tree_example
