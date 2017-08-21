/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  Pokemon.h
 *  * Author: Danny Tran
 *  * Description:
 *  * Date: 31 March 2017
 *  *
 *  ---------------------------------------------------------------------------- */

#ifndef POKEMON_H
#define POKEMON_H

#include "BinarySearchTree.h"
#include <string>

using namespace std;

class Pokemon
{

	public:

		Pokemon();
		Pokemon(std::string aname, int id, std::string jname);


		void setAPname(string aname);
		string getAPname() const;

		void setJPname(string jname);
		string getJPname() const;

		void setPokeid(int pid);
		int getPokeid() const;

		bool operator<(const Pokemon& rhs) const;
		bool operator>(const Pokemon& rhs) const;
		bool operator==(const Pokemon& rhs) const;


	private:

		string ap_name;
		string jp_name;
		int pokeid;



};
#endif
