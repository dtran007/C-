program: main.o MedicalExecutive.o City.o
	g++ -std=c++11 -g -Wall main.o MedicalExecutive.o City.o -o program

main.o: main.cpp LinkedList.h MedicalExecutive.h City.h Node.h
	g++ -std=c++11 -g -Wall -c main.cpp

City.o: City.cpp City.h LinkedList.h MedicalExecutive.h Node.h
	g++ -std=c++11 -g -Wall -c City.cpp

MedicalExecutive.o: MedicalExecutive.cpp MedicalExecutive.h LinkedList.h City.h Node.h
	g++ -std=c++11 -g -Wall -c MedicalExecutive.cpp

clean:
	rm *.o program
