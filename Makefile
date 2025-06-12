CXX = g++
CXXFLAGS = -Wall -std=c++17

all: main

main: main.o FA.o
	$(CXX) $(CXXFLAGS) main.o FA.o -o main

main.o: main.cpp FA.h
	$(CXX) $(CXXFLAGS) -c main.cpp

FA.o: FA.cpp FA.h
	$(CXX) $(CXXFLAGS) -c FA.cpp

clean:
	rm -f *.o main
