/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  City.cpp
 *  * Author: Danny Tran
 *  * Description: City Implemnetation File for City Class
 *  * Date: 10 Feb 2017
 *  *
 *  ---------------------------------------------------------------------------- */

#include"City.h"

/*
   City::City(string cityname, int population, int infectionlvl) : m_cityname(cityname), m_population(population), m_infectionlvl(infectionlvl)
   {

   m_cityname = cityname;
   m_population = population;
   m_infectionlvl = infectionlvl;

   }
   */

City::City()
{
	m_cityname="";
	m_population=0;
	m_infectionlvl=0;
}

City::City(string cityname, int population, int infectionlvl)
{
	m_cityname=cityname;
	m_population=population;
	m_infectionlvl=infectionlvl;
}


void City::setPopulation(int population)
{
	m_population = population;
}

int City::getPopulation() const
{
	return(m_population);
}

void City::setInfectionlvl(int infectionlvl)
{
	m_infectionlvl = infectionlvl;
}

int City::getInfectionlvl() const
{
	return(m_infectionlvl);
}

void City::setCityname(string cityname)
{
	m_cityname = cityname;
}

string City::getCityname() const
{
	return(m_cityname);
}
