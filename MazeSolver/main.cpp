/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  main.cpp
 *  * Author: Danny Tran
 *  * Description: File to instantiate maze instance
 *  * Date: 3 Mar 2017
 *  *
 *  ---------------------------------------------------------------------------- */

#include "maze.h"
#include "mazerunner.h"

int main(int argc, char* argv[])
{
	if(argc < 2)
	{
		cout<<"Incorrect number of parameters.\n";
	}
	else
	{
	//	cout<<"You have entered correct number of parameters.\n";
		string in_string = (argv[1]);

		//Test file name input
		//cout<<in_string<<endl;

		try {
				maze maze_instance(in_string);
		}
		catch (PreconditionViolationException& e){
			std::cout << e.what() << std::endl;
		}

	}
		//Message test to see if end of main gets reached.
		//cout<<"El psy congroo"<<endl;
	return(0);
}
