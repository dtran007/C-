/* -----------------------------------------------------------------------------
 *
 * File name: main.cpp
 * Author: Danny Tran
 * Description: A Hangman game to guess a string within 7 tries.
 * Last Changed: 18 November 2016
 *
 *  ---------------------------------------------------------------------------- */
#include<iostream>        //For cout
#include<string>          //For strings
#include<fstream>         //For file I/O
#include<cstdlib>         //For exit
#include<limits>          //For failbit

#include"GameDriver.h"
#include"Hangman.h"

using namespace std;

int main(int argc, char** argv) //Remember argc is number of arguments
{                               //argv points to a string array of the actual arguments

	string initialWord="";
	if(argc >=2)
	{


		for (int i=1; i<argc; i++) //Create a string with "spaces" from user input arguments
		{
			if(i==1)
			{
				initialWord=initialWord+argv[i]; //No space for first entry.
			}
			else if (i<argc)
			{
				initialWord = initialWord+" "+argv[i]; //Space for every entry after first.
			}

		}
	//	cout<<initialWord<<endl;  //Just a test print for correct arguments to strings
	}
	else
	{
		cout<<"Error. Invalid number of arguments. Minimum of two required. (Enter the Hangman arguement.)"<<endl;
		exit(1);
	}

//	cout<<initialWord<<"Testing"<<endl; //Test print two... comment out later
	GameDriver driver;
	driver.play(initialWord);

	return(0);
}
