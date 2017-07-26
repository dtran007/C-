/* -----------------------------------------------------------------------------
 *
 * File name: Hangman.cpp
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

#include "Hangman.h"

using namespace std;
//Constructor                --------Initializer List---------------
Hangman::Hangman(string word) : secretWord(word), MAX_MISSES_ALLOWED(7)
{
	disguisedWordSize=word.length();

	disguisedWord = new char[disguisedWordSize+1];
	disguisedWord[disguisedWordSize] = '\0';
	for(int i=0; i<disguisedWordSize; i++)
	{
		if(secretWord.substr(i,1)!=" ")
		{
			disguisedWord[i]='?';
		}
		else
		{
			disguisedWord[i]=' ';
		}
	}


	missedMarkers = new char[MAX_MISSES_ALLOWED+1];
	missedMarkers[MAX_MISSES_ALLOWED]='\0'; //null string pos
	for(int i=0; i<MAX_MISSES_ALLOWED; i++)
	{
		missedMarkers[i]='O';
	}

	guessCount=0;
	missesCount=0;

}

Hangman::~Hangman()
{
	delete[] missedMarkers;
	delete[] disguisedWord;

}

//Methods
bool Hangman::guessCharacter(char c)
{


	bool charMatch= false;
	guessCount++;      //Accessing private member b/c its part of the class

	string char_string="";          //Intake c parameter
	char_string=char_string+c;      //Make it a string


	for(int i=0; i<disguisedWordSize; i++)
	{
		if(secretWord.substr(i,1).compare(char_string)==0)  //Using string member functions
		{
			disguisedWord[i]=c;
			charMatch=true;
		}
	}


	if(!charMatch)
	{
		missedMarkers[missesCount]='X';
		missesCount=missesCount+1;
	}

	return(charMatch);
}

bool Hangman::isGameOver()
{
	if(missesCount == MAX_MISSES_ALLOWED)
	{
		return(true);
	}
	/*else if((disguisedWord) == (secretWord)) //Can use this or use the function isFound
	{
		return(true);
	}
	*/
	else if(isFound()==true)
	{
		return(true);
	}
	else
	{
		return(false);
	}
}


bool Hangman::isFound()
{
	if(disguisedWord == secretWord)
	{
		return(true);
	}

	else
	{
		return(false);
	}
}

string Hangman::getDisguisedWord()  //Should return a string. Not a char*
{
	string word (disguisedWord);
	return(word);
}

int Hangman::getGuessCount()
{
	return(guessCount);
}

int Hangman::getMissesCount()
{
	return(missesCount);
}
string Hangman::getMissedMarker() //Should return a string. Not a char*
{
	string markers (missedMarkers);
	return(markers);
}
