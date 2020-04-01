CXXFLAGS = -Wall -g -std=c++14 -fsanitize=address 
CXX = g++
CLL = -c
SRCS:=$(wildcard *.cpp)
SRCS:=$(filter-out main.cpp, $(SRCS))
OBJS=$(SRCS:.cpp=.o)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(CLL) $^ -o $@

main: main.cpp $(OBJS)
	$(CXX) $(CXXFLAGS) -o main main.cpp $(OBJS)