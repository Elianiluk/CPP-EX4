CXX = g++
CXXFLAGS = -std=c++17 -I .

SRCS = Demo.cpp
OBJS = $(SRCS:.cpp=.o)

tree: $(OBJS)
	$(CXX) -o $@ $^

.PHONY: clean all

clean:
	rm -f *.o tree
