/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  main.cpp
 *  * Author: Danny Tran
 *  * Description: Main file for implementing classes in Pokemon List Assignment
 *  * Date: 27 Jan 2017
 *  *
 *  ---------------------------------------------------------------------------- */

#include<iostream>

#include "Pokemon.h"
#include "Executive.h"


int main(int argc, char* argv[])
{
	if(argc < 2)
	{
		std::cout<<"Incorrect number of parameters.\n";
	}
	else
	{
		    Executive exec(argv[1]); //sample creation of executive object
		    exec.run(); //handles the calling of all the other member methods
	}


	return(0);
}
