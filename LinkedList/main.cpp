/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  main.cpp
 *  * Author: Danny Tran
 *  * Description: Main for Lab02 - Controls arguments and the -t and -i modes
 *  * Date:03 Feb 2017
 *  *
 *  ---------------------------------------------------------------------------- */
#include<iostream>        //For I/O
#include<cstdlib>         //For exit
#include<limits>          //For failbit
#include<string>          //For string


// #include"Node.h"
#include"LinkedList.h"
#include"LinkedListTester.h"
// #include"LinkedListTester.hpp"
// #include"LinkedList.hpp"

// ./valgrind --leak-check=full -g -v
//check alloc and free match up


using namespace std;
void menu();

int main(int argc, char* argv[])
{
	if(argc <2)
	{
		cout<<"Incorrect number of parameters.\n";
		exit(1);
	}
	else if( (string (argv[1]) != "-i") && (string (argv[1]) != "-t"))
	{
		cout<<"Incorrect parameter choice. Choose parameter: -i or -t"<<endl;
		exit(1);
	}

	/*
	std::cout << "Have " << argc << " arguments:" << std::endl;
	for (int i = 0; i < argc; ++i)
	{
		std::cout << argv[i] << std::endl;
	}
	*/  //Only a test at creation for arguments

	//Instantiate LinkedList

	LinkedList<int> myList;


	if( (string (argv[1]) == "-i"))
	{
		int userOption=0;

		do
		{
			menu();
			cout<<"Choice: ";
			cin>>userOption;
			while(cin.fail()) //control loop
			{
				cin.clear(); //unset failbit
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //skip bad input

				menu();
				cout<<"Choice: ";
				cin>>userOption;
			}

			if(userOption == 1)
			{
				cout<<endl;
				cout<<"~Add Front~"<<endl;
				int temp_addFront=0;
				cout<<"Input Number to Add Front: ";
				cin>>temp_addFront;

				myList.addFront(temp_addFront);
				cout<<endl;
			}

			if(userOption == 2)
			{
				cout<<endl;
				cout<<"~Add Back~"<<endl;
				int temp_addBack=0;
				cout<<"Input Number to Add Back: ";
				cin>>temp_addBack;

				myList.addBack(temp_addBack);
				cout<<endl;

			}

			if(userOption == 3)
			{
				cout<<endl;
				cout<<"~Remove Front~"<<endl;
				myList.removeFront();
				cout<<endl;

			}

			if(userOption == 4)
			{
				cout<<endl;
				cout<<"~Remove Back~"<<endl;
				myList.removeBack();
				cout<<endl;
			}

			if(userOption == 5)
			{
				cout<<endl;
				cout<<"~Insert Value at Position~"<<endl;

				int tempValue;
				int tempPosition;
				cout<<"Please Enter Value: ";
				cin>>tempValue;
				cout<<"Please enter Position: ";
				cin>>tempPosition;

				myList.insert(tempPosition, tempValue);
				cout<<endl;
			}

			if(userOption == 6)
			{
				cout<<endl;
				cout<<"~Print Length~"<<endl;
				cout<<"Length: "<<myList.getLength();
				cout<<endl;
				cout<<endl;

			}

			if(userOption == 7)
			{
				cout<<endl;
				cout<<"~Print List~"<<endl;

				for(int i=1;i<=myList.getLength();i++)
				{

					cout<<myList.getEntry(i)<<"->";

				}
				cout<<endl;
				cout<<endl;
			}

		}while(userOption !=8);
	}




	if( (string (argv[1]) == "-t"))
	{
		cout<<"You have entered Test Mode:"<<endl;

		LinkedListTester myTest;

		myTest.runTest();

	}

	return(0);
}



void menu()
{
	cout<<"Make a selection:"<<endl;
	cout<<"1) Add front"<<endl;
	cout<<"2) Add back"<<endl;
	cout<<"3) Remove front"<<endl;
	cout<<"4) Remove back"<<endl;
	cout<<"5) Insert value at position"<<endl;
	cout<<"6) Print length"<<endl;
	cout<<"7) Print list"<<endl;
	cout<<"8) Exit"<<endl;
}
