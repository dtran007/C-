/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  Executive.h
 *  * Author: Danny Tran
 *  * Description: Header file for Executive Class in Pokemon List Lab
 *  * Date:27 Jan 2017
 *  *
 *  ---------------------------------------------------------------------------- */
#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <iostream>
#include <string>
#include "Pokemon.h"

using namespace std;

class Executive
{
	private:
		int poke_size;
		Pokemon* poke_arrayptr;



	public:
		Executive(string filename); //Constructor with Parameter
		~Executive();  //Destructor

		void run();
		void menu();

};
#endif
