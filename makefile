# Compiler
CXX := g++
# Compiler flags
CXXFLAGS := -std=c++17 -Wall -Wextra
# SFML libraries
SFML_LIBS := -lsfml-graphics -lsfml-window -lsfml-system
# SFML include directory
SFML_INCLUDE := -I/path/to/sfml/include
# SFML library directory
SFML_LIB_DIR := -L/path/to/sfml/lib
# Target executable
TARGET := tree
# Source files
SRCS := Demo.cpp Complex.cpp Test.cpp TestCounter.cpp

TESTS := Test.cpp TestCounter.cpp
# Object files
OBJS := $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET) $(SFML_LIB_DIR) $(SFML_LIBS)

test: $(TESTS)
	./$(TESTS) test

.cpp.o:
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean test
