CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -pedantic

SRC = a3q1.cc date.cc call.cc plan.cc
OBJ = $(SRC:.cc=.o)
EXEC = plan

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJ)

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: all clean
