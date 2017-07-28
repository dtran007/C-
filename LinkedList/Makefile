linkedlist: main.o LinkedListTester.o
	g++ -std=c++11 -g -Wall main.o LinkedListTester.o -o linkedlist

main.o: main.cpp LinkedList.h LinkedListTester.h Node.h Node.hpp LinkedList.hpp LinkedListTester.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

LinkedListTester.o: LinkedListTester.cpp LinkedListTester.h
	g++ -std=c++11 -g -Wall -c LinkedListTester.cpp

clean:
	rm *.o linkedlist
