main: main.o Executive.o Pokemon.o
	g++ -std=c++11 -g -Wall main.o Executive.o Pokemon.o -o main

main.o: main.cpp Executive.h Pokemon.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.cpp Executive.h Pokemon.h
	g++ -std=c++11 -g -Wall -c Executive.cpp

Pokemon.o: Pokemon.cpp Pokemon.h Executive.h
	g++ -std=c++11 -g -Wall -c Pokemon.cpp

clean:
	rm *.o main

