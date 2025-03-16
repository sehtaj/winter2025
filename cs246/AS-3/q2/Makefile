CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

TARGET = a3q2

all: $(TARGET)

$(TARGET): main_q2.o a3q2.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) main_q2.o a3q2.o

main_q2.o: main_q2.cc a3q2.h
	$(CXX) $(CXXFLAGS) -c main_q2.cc

a3q2.o: a3q2.cc a3q2.h
	$(CXX) $(CXXFLAGS) -c a3q2.cc

clean:
	rm -f $(TARGET) *.o



