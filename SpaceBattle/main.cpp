/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  main.cpp
 *  * Author: Danny Tran
 *  * Description: main.cpp to take in cmd line parameter to run FightManager
 *  * Date: 17 Feb 2017
 *  *
 *  ---------------------------------------------------------------------------- */


#include "SpaceShip.h"
#include "StarWarsShip.h"
#include "StarTrekShip.h"
#include "LinkedList.h"
#include "FightManager.h"

int main(int argc, char* argv[])
{
	if(argc < 2)
	{
		std::cout<<"Incorrect number of parameters.\n";
	}
	else
	{
		string in_string = (argv[1]);
		FightManager LinkedListInstance(in_string);
		LinkedListInstance.Fight();

	}

	return(0);

}
