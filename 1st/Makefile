CXX = g++
CXXFLAGS = -std=c++11

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = maze_game

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) $(OBJS)

