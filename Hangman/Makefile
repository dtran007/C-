main: main.o Hangman.o GameDriver.o
	g++ -std=c++11 -g -Wall main.o Hangman.o GameDriver.o -o main

main.o: main.cpp Hangman.h GameDriver.h
	g++ -std=c++11 -g -Wall -c main.cpp

GameDriver.o: GameDriver.cpp GameDriver.h Hangman.h
	g++ -std=c++11 -g -Wall -c GameDriver.cpp

Hangman.o: Hangman.cpp Hangman.h
	g++ -std=c++11 -g -Wall -c Hangman.cpp

clean:
	rm *.o main
