/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  pokemon.cpp
 *  * Author: Danny Tran
 *  * Description: Pokemon Class implementation file for Pokemon List Assignment 
 *  * Date:27 Jan 2017
 *  *
 *  ---------------------------------------------------------------------------- */
#include <iostream>
#include <string>

#include "Pokemon.h"
#include "Executive.h"


//Constructor
Pokemon::Pokemon()
{
	ap_name="";
	jp_name="";
	pokeid=0;
}

//Methods get + set

void Pokemon::setAPname(string aname)
{
	ap_name = aname;
}

string Pokemon::getAPname() const
{
	return(ap_name);
}

void Pokemon::setJPname(string jname)
{
	jp_name = jname;
}

string Pokemon::getJPname() const
{
	return(jp_name);
}

void Pokemon::setPokeid(int pid)
{
	pokeid = pid;
}

int Pokemon::getPokeid() const	
{
	return(pokeid);
}
