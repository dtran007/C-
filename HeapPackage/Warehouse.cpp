/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  Warehouse.cpp
 *  * Author: Danny Tran
 *  * Description: Warehouse implementation to process packages
 *  * Date: 21 April 17
 *  *
 *  ---------------------------------------------------------------------------- */

#include "Warehouse.h"
#include "Package.h"

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib> //For exit
#include <limits> //for failbit
#include <locale> //std::locale, std::toupper

using namespace std;



Warehouse::Warehouse(std::string filename)
{
	ifstream in_stream;

	int size = 16;
	packageHeap = new HeapPriorityQueue<Package>(size);

	in_stream.open(filename);

	if(in_stream.fail() )
	{
		std::cout<<"Fail to open input  file.\n";
		exit(1);
	}

	if(in_stream.is_open() )
	{
		while(!in_stream.eof() )
		{
			string t_entry="";
			string t_priority="";
			string t_content="";
			string t_destination="";
			int t_size;

			getline(in_stream, t_entry, ',');

			if(t_entry == "TRUCK")
			{//Do Truck Stuff
				string temp_size="";
				getline(in_stream, temp_size, '\n');
				t_size = stoi(temp_size);

				//Testin input
				//cout<<"Input: "<<t_entry<<"~"<<t_size<<endl<<endl;

				cout<<"\nTruck has arrived!"<<endl;
				cout<<"Loading the following packages:"<<endl;

				for(int i=1; i<=t_size; i++)
				{//Display package
					try
					{
						cout<<i<<". Priority: "<<packageHeap->peekTop().getPriority()<<"; "
							<<"Contents: "<<packageHeap->peekTop().getContent()<<"; "
							<<"Destination: "<<packageHeap->peekTop().getDestination()<<" "
							<<endl;

						//Remove package
						packageHeap->remove();
					}
					catch(std::runtime_error e)
					{
						cout<<e.what()<<endl;
					}
				}
				cout<<"Truck is leaving!"<<endl;
			}
			else if(t_entry =="")
			{
				break;
			}


			else
			{
				t_priority = t_entry;

				getline(in_stream, t_content, ',');
				getline(in_stream, t_destination, '\n');

				//Testing input
				//	cout<<"Input: "<<t_priority<<"~"<<t_content<<"~"<<t_destination<<endl;

				try
				{
					Package t_Package(t_priority, t_content, t_destination);
					packageHeap->add(t_Package);
				}
				catch(std::runtime_error e)
				{
					std::cout<<e.what();
				}
			}
		}
	}
	//Testing
	cout<<"\nRemaining packages in Warehouse/Heap:"<<endl;
	packageHeap->printHeap();
	cout<<std::endl;
	in_stream.close();

	//Testing
	//Appears enums is not the right means for operator overloading but note this is the syntax for calling enums
	/*
	   cout<<"Testing shipPriority: "<<endl;
	   cout<< "This is the int value of whenever: "<<Package::shipPriority::whenever<<endl;
	   cout<< "This is the int value of ground: "<<Package::shipPriority::ground<<endl;
	   cout<< "This is the int value of day: "<<Package::shipPriority::TwoDay<<endl;
	   cout<< "This is the int value of overnight: "<<Package::shipPriority::overnight<<endl;
	   */

	//Testing operator overload
	//	std::string xpriority = "overnight";
	//	std::string xcontent = "food";
	//	std::string xdestination = "California";

	//	std::string ypriority = "overnight";
	//	std::string ycontent = "apples";
	//	std::string ydestination = "Washington";

	//	Package a(xpriority, xcontent, xdestination);
	//	Package b(ypriority, ycontent, ydestination);

	//	bool xcompare = (a>b);
	//	cout<<"Bool output: "<<xcompare<<endl;

}


Warehouse::Warehouse()
{

}

Warehouse::~Warehouse()
{
	delete packageHeap;
}
