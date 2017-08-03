/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  StarWarsShip.cpp
 *  * Author: Danny Tran
 *  * Description:  Implementation File for StarWarsShip Class
 *  * Date: 17 Feb 2017
 *  *
 *  ---------------------------------------------------------------------------- */
#include "StarWarsShip.h"


StarWarsShip::StarWarsShip(string universe, string pilotName, int attackPower, int maxHull, bool shieldStatus, string lastWords)
{
	m_universe=universe;
	m_pilotName=pilotName;
	m_attackPower=attackPower;
	m_maxHull=maxHull;
	m_shieldStatus=shieldStatus;
	m_lastWords=lastWords;

	m_currentHull = maxHull;

}

StarWarsShip::~StarWarsShip()
{
	//cout<<"StarWars Destructor got called"<<endl;
	cout<<lastwhisper()<<endl;
}

int StarWarsShip::attackPower() const
{
	return(m_attackPower);
}

int StarWarsShip::currentHull() const
{
	return(m_currentHull);
}

int StarWarsShip::maxHull() const
{
	return(m_maxHull);
}

bool StarWarsShip::takeDamage(int amount)
{

	if(shields())
	{
		amount = amount * (0.5);
	}

	m_currentHull = m_currentHull - amount;

	bool shipDies = false;
	if( m_currentHull <= 0)
	{
		shipDies = true;
	}

	return(shipDies);
}

bool StarWarsShip::shields() const
{
	return(m_shieldStatus);
}

string StarWarsShip::universe() const
{
	return(m_universe);
}

string StarWarsShip::status() const
{
	return(m_pilotName +"'s ship has " + to_string(m_currentHull) +" out of " + to_string(m_maxHull) +" remaining." );
}

string StarWarsShip::name() const
{
	return(m_pilotName);
}


string StarWarsShip::lastwhisper() const
{
	return("The final message from "+m_pilotName+": \""+m_lastWords+"\"");
}
