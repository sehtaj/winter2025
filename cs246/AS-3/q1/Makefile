CXX = g++
CXXFLAGS = -std=c++17 -Wall -Werror=vla -g
EXEC = program
OBJS = main.o a4q1.o
DEPENDS = a4q1.h

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

main.o: main.cc $(DEPENDS)
	$(CXX) $(CXXFLAGS) -c main.cc

a4q1.o: a4q1.cc $(DEPENDS)
	$(CXX) $(CXXFLAGS) -c a4q1.cc

clean:
	rm -f $(OBJS) $(EXEC)


