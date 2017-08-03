/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  StarTrekShip.cpp
 *  * Author: Danny Tran
 *  * Description:  Implementation File for StarTrekShip Class
 *  * Date: 17 Feb 2017
 *  *
 *  ---------------------------------------------------------------------------- */
#include "StarTrekShip.h"


StarTrekShip::StarTrekShip(string universe, string captainName, int attackPower, int crewNumber, int maxHull, bool shieldStatus)
{
	m_universe=universe;
	m_captainName=captainName;
	m_attackPower=attackPower;
	m_crewNumber=crewNumber;
	m_maxHull=maxHull;
	m_shieldStatus=shieldStatus;

	m_currentHull = m_maxHull;

}

StarTrekShip::~StarTrekShip()
{
	//cout<<"StarTrek Destructor got called"<<endl;
	cout<<lastwhisper()<<endl;
}

int StarTrekShip::attackPower() const
{
	return(m_attackPower);
}

int StarTrekShip::currentHull() const
{
	return(m_currentHull);
}

int StarTrekShip::maxHull() const
{
	return(m_maxHull);
}

bool StarTrekShip::takeDamage(int amount)
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

bool StarTrekShip::shields() const
{
	return(m_shieldStatus);
}

string StarTrekShip::universe() const
{
	return(m_universe);
}

string StarTrekShip::status() const
{
	return(m_captainName + "'s ship holding "+ to_string(m_crewNumber) + " crew members has " + to_string(m_currentHull) + " out of " + to_string(m_maxHull) + " remaining.");
}

string StarTrekShip::name() const
{
	return(m_captainName);
}

string StarTrekShip::lastwhisper() const
{
	return("The final message from " +m_captainName+": \"My greatest honor was being the captain for "+ to_string(m_crewNumber)+" crew members.\"");
}
