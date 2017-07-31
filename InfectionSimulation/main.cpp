/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  main.cpp
 *  * Author: Danny Tran
 *  * Description: main.cpp file
 *  * Date: 10 Feb 2017
 *  *
 *  ---------------------------------------------------------------------------- */


#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>         //For exit
#include<limits>          //For failbit


#include"LinkedList.h"
#include"City.h"
#include"MedicalExecutive.h"


using namespace std;

int main(int argc, char* argv[])
{
	if(argc < 2)
	{
		std::cout<<"Incorrect number of parameters.\n";
	}
	else
	{
		string in_string = (argv[1]);
		MedicalExecutive LinkedListInstance(in_string); //sample creation of executive object
		LinkedListInstance.run(); //handles the calling of all the other member methods
	}

	return(0);
}
