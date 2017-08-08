theatre: main.o Theatre.o PreconditionViolationException.o
	g++ -std=c++11 -g -Wall main.o Theatre.o PreconditionViolationException.o -o theatre

main.o: main.cpp Theatre.h PreconditionViolationException.h Node.h Node.hpp
	g++ -std=c++11 -g -Wall -c main.cpp

Theatre.o: Theatre.h Theatre.cpp Node.h Node.hpp Stack.h Stack.hpp Queue.h Queue.hpp
	g++ -std=c++11 -g -Wall -c Theatre.cpp

PreconditionViolationException.o: PreconditionViolationException.h PreconditionViolationException.cpp
	g++ -std=c++11 -g -Wall -c PreconditionViolationException.cpp

clean:
	rm *.o theatre
