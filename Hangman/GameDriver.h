/* -----------------------------------------------------------------------------
 *
 * File name: GameDriver.h
 * Author: Danny Tran
 * Description: A Hangman game to guess a string within 7 tries.
 * Last Changed: 18 November 2016
 *
 *  ---------------------------------------------------------------------------- */
#include<iostream>        //For cout
#include<string>          //For strings
#include<limits>          //For failbit

#include"Hangman.h"

#ifndef GAMEDRIVER_H
#define GAMEDRIVER_H

using namespace std;

class GameDriver
{
	private:
		string word;

	public:
		void play(string word);

};
#endif
