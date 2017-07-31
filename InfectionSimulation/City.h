/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  City.h
 *  * Author: Danny Tran
 *  * Description: City Header file for City Class
 *  * Date: 10 Feb 2017
 *  *
 *  ---------------------------------------------------------------------------- */
#ifndef CITY_H
#define CITY_H

#include"LinkedList.h"
#include <string>

using namespace std;

class City
{
	public:
		//City(string cityname, int population, int infectionlvl);
		//Default constructor for now
		City();
		City(string cityname, int population, int infectionlvl);

		//Methods and Mutators

		void setPopulation(int population);
		int getPopulation() const;

		void setInfectionlvl(int infectionlvl);
		int getInfectionlvl() const;

		void setCityname(string cityname);
		string getCityname() const;

	private:
		int m_population;
		int m_infectionlvl;
		string m_cityname;

};
#endif
