# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -g

# Source files
SRC_FILES = a2q3.cc canvas.cc point.cc rectangle.cc

# Output executable
EXE = a2q3

# Default target
all: $(EXE)

# Compile and link everything into the executable
$(EXE): $(SRC_FILES)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Clean up
clean:
	rm -f $(EXE)

.PHONY: all clean