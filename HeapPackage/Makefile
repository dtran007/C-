HeapPackage: main.o Warehouse.o  Package.o
	g++ -std=c++11 -g -Wall main.o Package.o Warehouse.o -o HeapPackage

main.o: main.cpp Warehouse.h Package.h Heap.h HeapPriorityQueue.h
	g++ -std=c++11 -g -Wall -c main.cpp

Warehouse.o: Warehouse.cpp Warehouse.h Package.h Heap.h HeapPriorityQueue.h Heap.hpp HeapPriorityQueue.hpp
	g++ -std=c++11 -g -Wall -c Warehouse.cpp

Package.o: Package.cpp Package.h Heap.h HeapPriorityQueue.h Heap.hpp HeapPriorityQueue.hpp
	g++ -std=c++11 -g -Wall -c Package.cpp

clean:
	rm *.o HeapPackage
