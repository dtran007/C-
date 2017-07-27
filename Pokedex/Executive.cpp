/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  Executive.cpp
 *  * Author: Danny Tran
 *  * Description: Executive Class implementation file for Pokemon List Assignment
 *  * Date:27 Jan 2017
 *  *
 *  ---------------------------------------------------------------------------- */
#include "Executive.h"
#include "Pokemon.h"

#include <iostream> //For cin/cout
#include <string>  //For string class
#include <fstream> //For file I/O
#include <cstdlib> //For exit
#include <limits>  //For failbit
#include <ctype.h> //for toupper() for uppercasing lowercase char
//#include <string.h> //For strtok which ended up not using

using namespace std;

Executive::Executive(string filename) //Constructor with Parameter
{
	ifstream in_stream; //input stream name
	ofstream out_stream; //output stream name

	in_stream.open(filename); //input stream opening file test

	if(in_stream.fail())
	{
		cout<<"Fail to open input file.\n";
		exit(1);
	}


	in_stream >> poke_size; //Formatted file (First line is number of rows in file)
	in_stream.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore buffer

	poke_arrayptr = new Pokemon[poke_size]; //Create an array of Pokemon

	for(int i=0; i<poke_size; i++)
	{
		string temp_ap_name;    //temporary variables to import data
		int temp_pokeid=0;
		string temp_jp_name;

		//getline implementation
		getline(in_stream, temp_ap_name, ',');   //getline delimit with ','
		in_stream >> temp_pokeid;
		in_stream.ignore(1);  //ignore(1) or ignore() remove comma. more than that will start chopping input
		getline(in_stream, temp_jp_name, '\n');

		poke_arrayptr[i].setAPname(temp_ap_name);
		poke_arrayptr[i].setPokeid(temp_pokeid);
		poke_arrayptr[i].setJPname(temp_jp_name);



		//strtok implementation -- too messy --> went with getline function instead
		//Note: parsing this way makes pokeid into a string and need stoi to convert back number
		//Note to use getline and .ignore instead when dealing with mixed data types.
		/*****************************************************
		  string line;
		  getline(in_stream, line);

		  char* a = new char[line.length()+1];
		  strcpy(a, line.c_str());

		  char* pch;

		  pch = strtok(a, ",");

		  poke_arrayptr[i].setAPname(pch);

		  pch=strtok(NULL, ",");
		  poke_arrayptr[i].setPokeid(stoi(pch));

		  pch=strtok(NULL, ",");

		  poke_arrayptr[i].setJPname(pch);

		  delete[] a;
		 ****************************************************/
		//strtok //stoi methods

	}


	in_stream.close(); //close file



}


Executive::~Executive()
{
	delete[] poke_arrayptr;

}

void Executive::menu()
{
	cout<<"\n1. Print the data for a Pokemon based on ID"<<endl;
	cout<<"2. Print all pokemon whose IDs are between a range"<<endl;
	cout<<"3. Write all Japanese names to file"<<endl;
	cout<<"4. Print all pokemon whose names begin with a certain letter"<<endl;
	cout<<"5. Exit"<<endl;
}



void Executive::run()
{
	int userChoice=0;
	bool b_enter;
	bool b_lowchoice;
	bool b_upperchoice;

	do
	{	
		do
		{
			menu();
			cout<<"\nEnter menu choice: ";
			cin>>userChoice;

			b_enter = cin.fail();

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			b_lowchoice=(userChoice <= 0);	//Bool loop
			b_upperchoice=(userChoice >= 6);
			if(b_lowchoice == true || b_upperchoice == true)
			{
				cout << "\nInvalid input !!\nShould be a number in the range: 1-5!\n";
				cout << "Enter a number based on options: " << endl<<endl;;
			}
		}while(b_enter == true || b_upperchoice == true || b_lowchoice == true); //Repeat loop 





		if(userChoice == 1) //Print all Pokemon info
		{

			for(int i=0; i<poke_size; i++)
			{
				cout<<"Pokemon #<"<<poke_arrayptr[i].getPokeid()<<">: <"<<poke_arrayptr[i].getAPname()<<"> (USA), <"<<poke_arrayptr[i].getJPname()<<"> (JPN)"<<endl;
			}


		}

		if(userChoice == 2) //Print range of Pokemon info
		{
			int range1=0;
			int range2=0;
			bool b_fail;
			bool b_range;  //Bool for ranges 
			bool b_min;
			bool b_max;

			do
			{
				cout<<"\n~Pokemon Ranges are between 1 to 151~"<<endl;
				cout<<"Enter Pokemon Range1: ";
				cin>>range1;

				b_fail = cin.fail();

				cin.clear();    //Unset failbit
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Ignore Buffer

				b_min=(range1 <= 0);

			}while(b_fail == true || b_min == true);

			do
			{

				cout<<"Enter Pokemon Range2: ";
				cin>>range2;

				b_fail = cin.fail();

				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				b_range=(range1 > range2);	//Bool- if range1 greater than range2 keep repeating loop until higher value entered		
				b_max=(range2 >=152);
			}while(b_fail == true || b_range == true || b_max == true); //Repeat loop if failbit true or range parameter true


			cout<<"Entered ranges are from : "<<range1<<" to "<<range2<<endl<<endl;

			for(int i=range1-1; i<=range2-1; i++)
			{                                                                                                                                                            	
				cout<<"Pokemon #<"<<poke_arrayptr[i].getPokeid()<<">: <"<<poke_arrayptr[i].getAPname()<<"> (USA), <"<<poke_arrayptr[i].getJPname()<<"> (JPN)"<<endl;
			}
		}

		if(userChoice == 3) //Print to File
		{

			string createFile;


			cout<<"\nPlease enter file name to output Japanese Pokemon name to: ";
			getline(cin, createFile);


			ofstream out_stream;  //output stream name

			out_stream.open(createFile);  //Open file to create

			if(out_stream.fail())
			{
				cout<<"Output file opening failed.\n";
				exit(1);
			}

			for(int i=0; i<poke_size; i++)
			{

				out_stream<<poke_arrayptr[i].getJPname()<<"(JPN)"<<" Pokemon#<"<<poke_arrayptr[i].getPokeid()<<">"<<endl;

			}	

			cout<<"File name created with Japanese Pokemon Name exported: "<<createFile<<endl;


			out_stream.close(); //Close file


		}



		if(userChoice == 4) 
		{

			char pChar='\n';
			char PChar='\n';
			bool b_char;

			do
			{

				cout<<"\nPlease enter letter to print all Pokemon that begin with that letter: ";
				cin>>pChar;

				b_char= cin.fail();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');


			}while(b_char == true);	//Loop until proper char input

			PChar = toupper(pChar); //toupper() changing lowercase to uppercase

			for(int i=0; i<poke_size; i++)
			{
				if(poke_arrayptr[i].getAPname()[0] == PChar)
				{

					cout<<poke_arrayptr[i].getAPname()<<"(USA)"<<" #<"<<poke_arrayptr[i].getPokeid()<<">"<<endl;
				}
			}

		}
		if(userChoice == 5)
		{
			cout<<"Exiting!"<<endl;
		}
	}while(userChoice != 5);
}
