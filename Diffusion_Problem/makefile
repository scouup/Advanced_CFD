# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -O2

# Target name
TARGET = DiffusionSolver

# Source files
SRCS = main.cpp Diffusion_Solver.cpp

# Header files (optional, for tracking)
HDRS = Diffusion_Solver.h

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)

