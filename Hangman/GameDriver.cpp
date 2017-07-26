/* -----------------------------------------------------------------------------
 *
 * File name: GameDriver.cpp
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

#include"Hangman.h"
#include"GameDriver.h"

using namespace std;


void GameDriver::play(string initialWord)
{

	Hangman* game = new Hangman(initialWord);   //Initial Instance of Hangman

	bool playAgain = true;
	while(playAgain != false)
	{

		cout<<"Welcome to Hangman Game!"<<endl;
		cout<<"------------------------";

		while(!(*game).isGameOver())
		{
			char guess=' ';
			int currentMisses = (*game).getMissesCount();
			cout<<"\n\nGuess this: "<<(*game).getDisguisedWord()<<endl;
			cout<<"Guesses so far: "<<(*game).getGuessCount()<<endl;
			cout<<"Misses:"<<(*game).getMissedMarker()<<endl;
			cout<<"Enter your guess character: ";
			cin>>guess;

			game->guessCharacter(guess);
			if(game->getMissesCount() == currentMisses)
			{
				cout<<guess<<" is in the secret word!";
			}
			else
			{
				cout<<guess<<" is not in the secret word. Death draws closer.";
			}

		}

		cout<<"\nGame over!"<<endl;
		if( game->getMissesCount() == 7)
		{
			cout<<"You died. Next time, guess as if your life depended on it."<<endl;

		}
		else
		{
			string revealWord=game->getDisguisedWord();

			cout<<"Congradulations! You guessed the secret word: ";
			cout<<revealWord<<" in "<<game->getGuessCount()<<" guess!"<<endl;

		}
		delete game; //delete instance for new one to begin
		game = nullptr;


		char playChoice = '\0';
		cout<<"Do you want to play again? (y/n) "<<endl;
		while(playChoice != 'n' && playChoice != 'y')       //Ensure either Y/N input
		{
			cin>>playChoice;
		}

		if(playChoice =='y')
		{

			cout<<"Input a new secret word: ";
			cin.ignore(255,'\n');                            //Cout 100 Lines to hide word
			getline(cin, word);


			for(int i=0; i<101; i++)
			{
				cout<<endl;
			}
		}
		if(playChoice =='n')
		{
			playAgain = false;
			break;
		}
		game = new Hangman(word); //New Instances of Hangman with new input word
	}
	cout<<"\nThanks for playing Hangman!"<<endl;
}
