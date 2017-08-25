/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  main.cpp
 *  * Author: Danny Tran
 *  * Description:  Main.cpp for Lab09
 *  * Date: 21 April 17
 *  *
 *  ---------------------------------------------------------------------------- */

#include <iostream>
#include <string>

#include "Warehouse.h"
#include "Heap.h"
#include "HeapPriorityQueue.h"

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

		Warehouse myWarehouse(in_string);
	}
	//Test if end of main is reached
//	cout<<"End of main\n";
	return(0);
}
