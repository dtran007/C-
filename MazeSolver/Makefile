MazeSolver: main.o maze.o mazerunner.o PreconditionViolationException.o
	g++ -std=c++11 -g -Wall main.o maze.o mazerunner.o PreconditionViolationException.o -o MazeSolver

main.o: main.cpp maze.h PreconditionViolationException.h
	g++ -std=c++11 -g -Wall -c main.cpp

PreconditionViolationException.o: PreconditionViolationException.h PreconditionViolationException.cpp
	g++ -std=c++11 -g -Wall -c PreconditionViolationException.cpp

maze.o: maze.cpp maze.h PreconditionViolationException.h
	g++ -std=c++11 -g -Wall -c maze.cpp

mazerunner.o: mazerunner.cpp mazerunner.h maze.h PreconditionViolationException.h
	g++ -std=c++11 -g -Wall -c mazerunner.cpp

clean:
	rm *.o MazeSolver
