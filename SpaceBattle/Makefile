SpaceBattle: main.o FightManager.o StarWarsShip.o StarTrekShip.o
	g++ -std=c++11 -g -Wall main.o FightManager.o StarWarsShip.o StarTrekShip.o -o SpaceBattle

main.o: main.cpp StarWarsShip.h StarTrekShip.h LinkedList.h LinkedList.hpp Node.h Node.hpp SpaceShip.h FightManager.h
	g++ -std=c++11 -g -Wall -c main.cpp

StarTrekShip.o: StarTrekShip.h StarTrekShip.cpp SpaceShip.h
	g++ -std=c++11 -g -Wall -c StarTrekShip.cpp

StarWarsShip.o: StarWarsShip.h StarWarsShip.cpp SpaceShip.h
	g++ -std=c++11 -g -Wall -c StarWarsShip.cpp

FightManager.o: FightManager.h FightManager.cpp SpaceShip.h
	g++ -std=c++11 -g -Wall -c FightManager.cpp

clean:
	rm *.o SpaceBattle
