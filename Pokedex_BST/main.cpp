/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  main.cpp
 *  * Author: Danny Tran
 *  * Description: main.cpp file
 *  * Date: 31 March 2017
 *  *
 *  ---------------------------------------------------------------------------- */
#include "BinarySearchTree.h"
#include "Executive.h"
#include "Pokemon.h"

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

		cout<<"Parameter entered: "<<in_string<<endl;

		Executive exec(in_string);
		exec.run();

	}
	//Test if end of main is reached
	//cout<<"End of main\n";
	return(0);
}
