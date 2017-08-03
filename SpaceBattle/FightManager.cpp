/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  FightManager.cpp
 *  * Author: Danny Tran
 *  * Description: FightManager implementation file to run filestream and run spaceship battle
 *  * Date: 17 Feb 2017
 *  *
 *  ---------------------------------------------------------------------------- */
#include "SpaceShip.h"
#include "StarTrekShip.h"
#include "StarWarsShip.h"
#include "FightManager.h"
#include "LinkedList.h"

using namespace std;

FightManager::FightManager(string filename)
{
	ifstream in_stream;
	ofstream out_stream;

	in_stream.open(filename);

	if(in_stream.fail())
	{
		std::cout<<"Fail to open input file.\n";
		exit(1);
	}

	ListofShips = new LinkedList<SpaceShip*>;

	string temp_universe="";
	string temp_captainName="";
	string temp_pilotName="";
	int temp_attackPower;
	int temp_crewNumber;  //StarTrek Only
	int temp_maxHull;
	bool temp_shieldStatus;
	string temp_lastWords; //StarWars Only


	if(in_stream.is_open())
	{
		while( (getline(in_stream, temp_universe, ',')))
		{
			if(temp_universe == "StarWars")//StarWars
			{
				getline(in_stream, temp_pilotName, ',');
				in_stream>>temp_attackPower;
				in_stream.ignore(1); //ignore the ,
				in_stream>>temp_maxHull;
				in_stream.ignore(1);
				in_stream>>temp_shieldStatus;
				in_stream.ignore(1);
				getline(in_stream, temp_lastWords, '\n');

				StarWarsShip* StarWarsShipPtr = new StarWarsShip(temp_universe, temp_pilotName, temp_attackPower, temp_maxHull, temp_shieldStatus, temp_lastWords);

				ListofShips->addBack(StarWarsShipPtr);


			}

			if(temp_universe == "StarTrek")//StarTrek
			{
				getline(in_stream, temp_captainName, ',');
				in_stream>>temp_attackPower;
				in_stream.ignore(1); //ignore the ,
				in_stream>>temp_crewNumber;
				in_stream.ignore(1); //ignore the ,
				in_stream>>temp_maxHull;
				in_stream.ignore(1); //ignore the ,
				in_stream>>temp_shieldStatus;
				in_stream.ignore();

				StarTrekShip* StarTrekShipPtr = new  StarTrekShip(temp_universe, temp_captainName, temp_attackPower, temp_crewNumber, temp_maxHull, temp_shieldStatus);

				ListofShips->addBack(StarTrekShipPtr);

			}
		}
	}
	in_stream.close(); //close file
}


void FightManager::Fight() //Run the Fight simulation in the List of Ships //LinkedListtype
{
	//Test Printing
	cout<<"Starting SpaceShips: "<<endl;
	for(int i=1; i<=ListofShips->getLength();i++)
	{
		cout<<ListofShips->getEntry(i)->status()<<endl;
	}


	cout<<"\nCommencing SpaceShip Battle!!\n"<<endl;


	SpaceShip* attacker;
	SpaceShip* defender;

	bool diffUniverse = false;

	while(ListofShips->getLength() > 1)
	{
		for(int i=1; i<=ListofShips->getLength(); i++)
		{
			attacker=ListofShips->getEntry(i);

			for(int j=1; j<=ListofShips->getLength(); j++)
			{
				if(attacker->universe() != ListofShips->getEntry(j)->universe() ) //Different Universe
				{
					diffUniverse = true;

					defender = ListofShips->getEntry(j);

					if(defender->takeDamage(attacker->attackPower() ) )
					{
						delete defender;
						ListofShips->removeAt(j);

					}

					break;
				}
			}
			if(!diffUniverse) //If(!diffUniverse) //AKA similar universe
			{
				for(int j=1; j<=ListofShips->getLength(); j++)
				{
					if(ListofShips->getEntry(j)->name() != attacker->name() )
					{
						defender = ListofShips->getEntry(j);

						if(defender->takeDamage(attacker->attackPower() ) )
						{
							delete defender;
							ListofShips->removeAt(j);
						}
						break;
					}
				}
			}
			diffUniverse = false;
		}//end for statement

		for(int x=1; x<=ListofShips->getLength(); x++)
		{
			cout<<ListofShips->getEntry(x)->status()<<endl;

		}
		cout<<endl;
	}//end while


	if(ListofShips->getLength() == 1)  //Printing Final Winner
	{

		cout<<ListofShips->getEntry(1)->status()<<endl;

		cout<<ListofShips->getEntry(1)->universe()
			<<" is the winner."<<endl;
	}

}//End Fight()



FightManager::~FightManager()
{
	//	cout<<"Fight Manager Destructor got called."<<endl;
	for(int i=1; i<=ListofShips->getLength(); i++)
	{
		delete ListofShips->getEntry(i);
		ListofShips->removeAt(i);
	}
	delete ListofShips;
}
