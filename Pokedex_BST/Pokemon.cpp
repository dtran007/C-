/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  Pokemon.cpp
 *  * Author: Danny Tran
 *  * Description:
 *  * Date: 31 March 2017
 *  *
 *  ---------------------------------------------------------------------------- */

#include "Pokemon.h"
#include "Executive.h"


Pokemon::Pokemon()
{
	ap_name="";
	jp_name="";
	pokeid=0;

}

Pokemon::Pokemon(std::string aname, int id, std::string jname)
{
	ap_name= aname;
	pokeid = id;
	jp_name= jname;


}


void Pokemon::setAPname(string aname)
{
	ap_name= aname;
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


//Operator Overloaded
bool Pokemon::operator==(const Pokemon& rhs) const
{
	std::string str1 = this->getAPname();
	std::string str2 = rhs.getAPname();
	if(str1.length() != str2.length()) {
		return false;
	}
	else {
		std::locale loc;
		for (std::string::size_type i=0; i<str1.length(); ++i){
			if(std::toupper(str1[i],loc) != std::toupper(str2[i],loc)) {
				return false;
			}
		}
	}
	return true;
}

bool Pokemon::operator<(const Pokemon& rhs) const
{
	/*
	   std::string str1 = this->getAPname();
	   std::string str2 = rhs.getAPname();

	   std::locale loc;
	   for (std::string::size_type i=0; i<str1.length(); ++i){
	   if(std::toupper(str1[i],loc) > std::toupper(str2[i],loc)) {
	   return false;
	   }
	   }

	   return true;
	   */
	return(this->ap_name < rhs.ap_name);

}

bool Pokemon::operator>(const Pokemon& rhs) const
{
	/*
	   std::string str1 = this->getAPname();
	   std::string str2 = rhs.getAPname();

	   std::locale loc;
	   for (std::string::size_type i=0; i<str1.length(); ++i){
	   if(std::toupper(str1[i],loc) < std::toupper(str2[i],loc)) {
	   return false;
	   }
	   }

	   return true;
	   */
	return(this->ap_name > rhs.ap_name);
}
