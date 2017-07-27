/* -----------------------------------------------------------------------------
 *  *
 *  * File Name: Pokemon.h
 *  * Author: Danny Tran
 *  * Description: Header file for Pokemon Class in Pokemon List Assignment
 *  * Date: 27 Jan 2017
 *  *
 *  ---------------------------------------------------------------------------- */
#ifndef POKEMON_H
#define POKEMON_H

#include<iostream>
#include<string>

using namespace std;

class Pokemon
{
	private:
		string ap_name;
		string jp_name;
		int pokeid;


	public:

		Pokemon(); //Constructor

		void setAPname(string aname);
		string getAPname() const;

		void setJPname(string jname);
		string getJPname() const;

		void setPokeid(int pid);
		int getPokeid() const;

};
#endif
