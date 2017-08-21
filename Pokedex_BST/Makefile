Pokedex: main.o Executive.o Pokemon.o NotFoundException.o TreeTest.o
	g++ -std=c++11 -g -Wall main.o Executive.o Pokemon.o NotFoundException.o TreeTest.o -o Pokedex

main.o: main.cpp BinarySearchTree.hpp BinarySearchTree.h BinaryNode.h BinaryNode.hpp Pokemon.h NotFoundException.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.cpp Executive.h BinaryNode.h BinarySearchTree.h Pokemon.h
	g++ -std=c++11 -g -Wall -c Executive.cpp

NotFoundException.o: NotFoundException.h NotFoundException.cpp
	g++ -std=c++11 -g -Wall -c NotFoundException.cpp

Pokemon.o: Pokemon.cpp Pokemon.h NotFoundException.h BinarySearchTree.h BinarySearchTree.hpp BinaryNode.h BinaryNode.hpp
	g++ -std=c++11 -g -Wall -c Pokemon.cpp

TreeTest.o: TreeTest.cpp BinarySearchTree.h BinaryNode.h BinarySearchTree.hpp BinaryNode.hpp NotFoundException.h Pokemon.h Executive.h
	g++ -std=c++11 -g -Wall -c TreeTest.cpp

clean:
	rm *.o Pokedex
