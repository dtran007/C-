/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  main.cpp
 *  * Author: Danny Tran
 *  * Description: Main.cpp file for running theatre instance
 *  * Date: 24 Feb 2017
 *  *
 *  ---------------------------------------------------------------------------- */
#include "Theatre.h"

#include <iostream>
#include <string>


using namespace std;

int main(int argc, char* argv[])
{

	if(argc < 2)
	{
		cout<<"Incorrect number of parameters\n";
	}
	else
	{
		string in_string= (argv[1]);

		Theatre theatre_instance(in_string);

	}


	//Test block of Try Catch Exceptions.

	// cout<<"\nMain Execution."<<endl;
	// //Testing Exception Handling with Try/Catch Block
	// Queue<string> testQueue;
	// Stack<string> testStack;
	// try
	// {
	// 	testStack.pop();
	// }
	// catch(PreconditionViolationException pve)
	// {
	// 	cout<<pve.what()<<endl;
	// }
	//
	//
	// try
	// {
	// 	testQueue.peekFront();
	// }
	// catch(PreconditionViolationException pve)
	// {
	// 	cout<<pve.what()<<endl;
	// }
	//
	// try//try dequeue
	// {
	// 	testQueue.dequeue();
	// }
	// catch(PreconditionViolationException pve)
	// {
	// 	cout<<pve.what()<<endl;
	// }
	//
	// cout<<"End of main.cpp. El Psy Congroo."<<endl;
	// //End of Try/Catch Block Testing



}
