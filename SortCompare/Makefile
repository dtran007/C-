SortCompare: main.o
	g++ -std=c++11 -g -Wall main.o -o SortCompare


SortTimer.o: SortTimer.h SortTimer.cpp Sort.h
	g++ -std=c++11 -g -Wall -c SortTimer.cpp

main.o: main.cpp Sort.h Sort.hpp SortTimer.h SortTimer.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

clean:
	rm *.o SortCompare
