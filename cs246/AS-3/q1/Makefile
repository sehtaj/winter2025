# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Werror=vla -g

# Executable name
EXEC = evaluate

# Source files
SRCS = main_q1.cc a3q1.cc varExpr.cc intExpr.cc unaryExpr.cc binaryExpr.cc

# Object files (replace .cc with .o for each source file)
OBJS = $(SRCS:.cc=.o)

# Header files (dependencies)
DEPENDS = varExpr.h intExpr.h unaryExpr.h binaryExpr.h a3q1.h

# Build target
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Compile each .cc file into .o
%.o: %.cc $(DEPENDS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJS) $(EXEC)


