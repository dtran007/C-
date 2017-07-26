/* -----------------------------------------------------------------------------
 *
 * File name: Hangman.h
 * Author: Danny Tran
 * Description: A Hangman game to guess a string within 7 tries.
 * Last Changed: 18 November 2016
 *
 *  ---------------------------------------------------------------------------- */
#include<iostream>        //For cout
#include<string>          //For strings

#ifndef HANGMAN_H
#define HANGMAN_H

using namespace std;

class Hangman
{
	private:
		const string secretWord;
		char* disguisedWord;
		int disguisedWordSize;
		int guessCount;
		int missesCount;
		const int MAX_MISSES_ALLOWED;
		char* missedMarkers;


	public:
		Hangman(string word); //Constructor initialize all instance variables
		~Hangman(); //Destructor
		bool guessCharacter(char c);
		bool isGameOver();
		bool isFound();
		string getDisguisedWord();
		int getGuessCount();
		int getMissesCount();
		string getMissedMarker();


};
#endif
