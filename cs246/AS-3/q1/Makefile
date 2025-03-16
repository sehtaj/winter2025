CXX = g++
CXXFLAGS = -std=c++17 -Wall -Werror=vla -g
EXEC = a3q1
OBJS = main_q1.o a3q1.o
DEPENDS = a3q1.h

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

main_q1.o: main_q1.cc $(DEPENDS)
	$(CXX) $(CXXFLAGS) -c main_q1.cc

a3q1.o: a3q1.cc $(DEPENDS)
	$(CXX) $(CXXFLAGS) -c a3q1.cc

clean:
	rm -f $(OBJS) $(EXEC)


