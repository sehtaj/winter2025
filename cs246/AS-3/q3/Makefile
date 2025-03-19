# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

# Source files
SRC = main.cc grid.cc cell.cc
OBJ = $(SRC:.cc=.o)

# Executable name
EXEC = gameoflife

# Default target
all: $(EXEC)

# Build the executable
$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile each .cc file to .o
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $<

# Clean up build artifacts
clean:
	rm -f $(OBJ) $(EXEC)

# Run the program
run: $(EXEC)
	./$(EXEC)


