/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  MedicalExecutive.cpp
 *  * Author: Danny Tran
 *  * Description: The implementation file for MedicalExecutive Class
 *  * Date: 10 Feb 2017
 *  *
 *  ---------------------------------------------------------------------------- */
#include "City.h"
#include "MedicalExecutive.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string.h>

using namespace std;

MedicalExecutive::MedicalExecutive(string filename)
{
	ifstream in_stream; //input stream name
	ofstream out_stream; //output stream name

	in_stream.open(filename); //input stream opening file test

	if(in_stream.fail())
	{
		std::cout<<"Fail to open input file.\n";
		exit(1);
	}

	myInfectedCityList = new LinkedList<City>();

	myQuarantineCityList = new LinkedList<City>();

	string temp_cityname="";
	int temp_population=0;
	int temp_infectionlvl=0;

	if(in_stream.is_open())
	{
		while( (getline(in_stream, temp_cityname, ',')))
		{
			//Import data -Assumes a perfect import file. If not will have to add methods to format during import.
			in_stream>>temp_population;
			in_stream.ignore(1); //ignore the ;
			in_stream>>temp_infectionlvl;
			in_stream.ignore();

		//	cout<<temp_cityname<<" "<<temp_population<<" "<<temp_infectionlvl<<endl; //Testing to see if getline worked on formated file comment out when done

			//myInfectedCityList already created at constructer
			//Creating Nodes
			//City t_City(temp_cityname, temp_population, temp_infectionlvl);
			City t_City(temp_cityname, temp_population, temp_infectionlvl);

			sortAdd(myInfectedCityList, t_City);
		}
	}
		//print list- Test printing to see if file import and LinkedList constructor worked out - comment out when done
	/*
		cout<<myInfectedCityList->getLength();
		cout<<endl<<endl;
		for(int i=1;i<=myInfectedCityList->getLength();i++)
		{
			cout<<myInfectedCityList->getEntry(i).getCityname()<<" "<<myInfectedCityList->getEntry(i).getPopulation()<<" "<<myInfectedCityList->getEntry(i).getInfectionlvl()<<"->";
		}
	cout<<endl;
	for(int i=1;i<=myInfectedCityList->getLength();i++)
	{
		cout<<myInfectedCityList->getEntry(i).getCityname()<<" "<<myInfectedCityList->getEntry(i).getPopulation()<<" "<<myInfectedCityList->getEntry(i).getInfectionlvl()<<"->";
	}
	cout<<endl;
 */

	in_stream.close(); //close file

}

void MedicalExecutive::sortAdd(LinkedList<City>* CityPtr, City tmp_City)
{
	if(CityPtr->isEmpty() )
	{
		CityPtr->addFront(tmp_City);
	}
	else
	{

		for(int i=1; i<=CityPtr->getLength(); i++)
		{
			if(tmp_City.getPopulation() > CityPtr->getEntry(i).getPopulation() )
			{
				CityPtr->insert(i, tmp_City);
				return;
			}
			if( (tmp_City.getPopulation() == CityPtr->getEntry(i).getPopulation()) && (tmp_City.getInfectionlvl() > CityPtr->getEntry(i).getInfectionlvl() )  )
			{
				CityPtr->insert(i, tmp_City);
				return;
			}
			if( (tmp_City.getPopulation() == CityPtr->getEntry(i).getPopulation()) && (tmp_City.getInfectionlvl() == CityPtr->getEntry(i).getInfectionlvl() )  )
			{

				if(tmp_City.getCityname()[0] < CityPtr->getEntry(i).getCityname()[0] )
				{
					CityPtr->insert(i, tmp_City);
					return;
				}

			}
			if( tmp_City.getPopulation() < CityPtr->getEntry(CityPtr->getLength()).getPopulation() )
			{
				CityPtr->addBack(tmp_City);
			}
		}
	}

}


void MedicalExecutive::menu()
{
	cout<<"\nMake a selection:"<<endl;
	cout<<"1) Increase infection level of all cities"<<endl;
	cout<<"2) Increase infection level of specific city"<<endl;
	cout<<"3) Print status of a specific city"<<endl;
	cout<<"4) Create quarantine log"<<endl;
	cout<<"5) Print all cities above an infection level"<<endl;
	cout<<"6) Exit"<<endl;
	cout<<"Choice: ";
}

void MedicalExecutive::Selection1() //Increase infection level by 1
{
	cout<<"\nThe infection level for all cities has been increased."<<endl;
	for(int i=myInfectedCityList->getLength(); i>=1; i--)
	{
		int templvl;
		templvl=myInfectedCityList->getEntry(i).getInfectionlvl();
		templvl=templvl+1;

		myInfectedCityList->getEntry(i).setInfectionlvl(templvl);
		//adding monitor

		if(myInfectedCityList->getEntry(i).getInfectionlvl() == 1)
		{
			string temp_cityname = myInfectedCityList->getEntry(i).getCityname();
			int temp_population = myInfectedCityList->getEntry(i).getPopulation();
			temp_population = (temp_population * 0.9);
			int temp_infectionlvl = myInfectedCityList->getEntry(i).getInfectionlvl();

			myInfectedCityList->removeAt(i);

			City t_City(temp_cityname, temp_population, temp_infectionlvl);

			sortAdd(myInfectedCityList, t_City);
		}

		if(myInfectedCityList->getEntry(i).getInfectionlvl() == 2)
		{
			string temp_cityname = myInfectedCityList->getEntry(i).getCityname();
			int temp_population = myInfectedCityList->getEntry(i).getPopulation();
			temp_population = (temp_population * 0.8);
			int temp_infectionlvl = myInfectedCityList->getEntry(i).getInfectionlvl();

			myInfectedCityList->removeAt(i);

			City t_City(temp_cityname, temp_population, temp_infectionlvl);

			sortAdd(myInfectedCityList, t_City);
		}
		if(myInfectedCityList->getEntry(i).getInfectionlvl() == 3)
		{
			string temp_cityname = myInfectedCityList->getEntry(i).getCityname();
			int temp_population = myInfectedCityList->getEntry(i).getPopulation();
			temp_population = (temp_population * 0.75);
			int temp_infectionlvl = myInfectedCityList->getEntry(i).getInfectionlvl();

			string temp_newcityname = myInfectedCityList->getEntry(i).getCityname();
			temp_newcityname="New "+temp_newcityname;
			int temp_newpopulation = myInfectedCityList->getEntry(i).getPopulation();
			temp_newpopulation = (temp_population * 0.25);
			int temp_newinfectionlvl = 0;

			myInfectedCityList->removeAt(i);

			City t_City(temp_cityname, temp_population, temp_infectionlvl);
			City t_newCity(temp_newcityname, temp_newpopulation, temp_newinfectionlvl);
			sortAdd(myInfectedCityList, t_City);
			sortAdd(myInfectedCityList, t_newCity);

		}

		if(myInfectedCityList->getEntry(i).getInfectionlvl() >= 4)
		{
			cout<<myInfectedCityList->getEntry(i).getCityname()<<" has been placed in quarantine!"<<endl;

			string temp_cityname = myInfectedCityList->getEntry(i).getCityname();
			int temp_population = myInfectedCityList->getEntry(i).getPopulation();
			int temp_infectionlvl = myInfectedCityList->getEntry(i).getInfectionlvl();

			City t_City(temp_cityname, temp_population, temp_infectionlvl);

			sortAdd(myQuarantineCityList, t_City); //Add to quarantine list
			//Need to remove lvl 4 or higher city ~If a city gets imported as lvl 4 it will be turned to 5 and moved to quarantine list
			myInfectedCityList->removeAt(i);
		}
		//end of monitor
	}

}
void MedicalExecutive::Selection2()
{
	string c_name="";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout<<"\nWhat city do you want to infect?: ";
	getline(cin, c_name);

	bool notfound = true;

	for(int i=1; i<=myInfectedCityList->getLength(); i++)
	{
		if(myInfectedCityList->getEntry(i).getCityname() == c_name)
		{
			int templvl;
			templvl=myInfectedCityList->getEntry(i).getInfectionlvl();
			templvl=templvl+1;

			myInfectedCityList->getEntry(i).setInfectionlvl(templvl);

			cout<<"Infection level for \""<<c_name<<"\" increased by 1"<<endl;
		//monitor
		if(myInfectedCityList->getEntry(i).getInfectionlvl() == 1)
		{
			string temp_cityname = myInfectedCityList->getEntry(i).getCityname();
			int temp_population = myInfectedCityList->getEntry(i).getPopulation();
			temp_population = (temp_population * 0.9);
			int temp_infectionlvl = myInfectedCityList->getEntry(i).getInfectionlvl();

			myInfectedCityList->removeAt(i);

			City t_City(temp_cityname, temp_population, temp_infectionlvl);


			sortAdd(myInfectedCityList, t_City);

		}

		if(myInfectedCityList->getEntry(i).getInfectionlvl() == 2)
		{
			string temp_cityname = myInfectedCityList->getEntry(i).getCityname();
			int temp_population = myInfectedCityList->getEntry(i).getPopulation();
			temp_population = (temp_population * 0.8);
			int temp_infectionlvl = myInfectedCityList->getEntry(i).getInfectionlvl();

			myInfectedCityList->removeAt(i);

			City t_City(temp_cityname, temp_population, temp_infectionlvl);



			sortAdd(myInfectedCityList, t_City);
		}
		if(myInfectedCityList->getEntry(i).getInfectionlvl() == 3)
		{
			string temp_cityname = myInfectedCityList->getEntry(i).getCityname();
			int temp_population = myInfectedCityList->getEntry(i).getPopulation();
			temp_population = (temp_population * 0.75);
			int temp_infectionlvl = myInfectedCityList->getEntry(i).getInfectionlvl();

			string temp_newcityname = myInfectedCityList->getEntry(i).getCityname();
			temp_newcityname="New "+temp_newcityname;
			int temp_newpopulation = myInfectedCityList->getEntry(i).getPopulation();
			temp_newpopulation = (temp_population * 0.25);
			int temp_newinfectionlvl = 0;

			myInfectedCityList->removeAt(i);

			City t_City(temp_cityname, temp_population, temp_infectionlvl);
			City t_newCity(temp_newcityname, temp_newpopulation, temp_newinfectionlvl);
			sortAdd(myInfectedCityList, t_City);
			sortAdd(myInfectedCityList, t_newCity);

		}

		if(myInfectedCityList->getEntry(i).getInfectionlvl() >= 4)
		{
			cout<<myInfectedCityList->getEntry(i).getCityname()<<" has been placed in quarantine!"<<endl;

			string temp_cityname = myInfectedCityList->getEntry(i).getCityname();
			int temp_population = myInfectedCityList->getEntry(i).getPopulation();
			int temp_infectionlvl = myInfectedCityList->getEntry(i).getInfectionlvl();

			City t_City(temp_cityname, temp_population, temp_infectionlvl);

			sortAdd(myQuarantineCityList, t_City); //Add to quarantine list
			//Need to remove lvl 4 or higher city
			myInfectedCityList->removeAt(i);


		}
		//monitor end

		notfound = false;
		}

	}

	if(notfound)
	{
		cout<<"Sorry, "<<c_name<<" is not a city in the list."<<endl;
	}
}


void MedicalExecutive::Selection3()
{
	string c_name="";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout<<"\nWhat city do you want to print status of?: ";
	getline(cin, c_name);
	bool notfound = true;
	for(int i=1; i<=myInfectedCityList->getLength(); i++)
	{
		if(myInfectedCityList->getEntry(i).getCityname() == c_name)
		{

			cout<<myInfectedCityList->getEntry(i).getCityname()<<", ";
			cout<<myInfectedCityList->getEntry(i).getPopulation()<<", ";
			cout<<myInfectedCityList->getEntry(i).getInfectionlvl()<<endl;

			notfound = false;
		}

	}
	if(notfound)
	{
		cout<<"Sorry, "<<c_name<<"\" is not a city in the list."<<endl;
	}
}
void MedicalExecutive::Selection4()
{
	string createLog;

	cout<<"\nPlease enter file name to output Quarantine Log to: ";
	cin.ignore();
	getline(cin, createLog);

	ofstream out_stream; //output stream name

	out_stream.open(createLog); //Open file to create

	if(out_stream.fail())
	{
		cout<<"Output file opening failed."<<endl;
	}

	//Enter loop to print quartine linked list

	for(int i=1;i<=myQuarantineCityList->getLength();i++)
	{

		out_stream<<myQuarantineCityList->getEntry(i).getCityname()<<","<<myQuarantineCityList->getEntry(i).getPopulation()<<","<<myQuarantineCityList->getEntry(i).getInfectionlvl()<<endl;

	}


	cout<<"File created: "<<createLog<<endl;
	out_stream.close(); //Close file
}


void MedicalExecutive::Selection5()
{
	int i_lvl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout<<"\nPlease enter an infection level: ";
	cin>> i_lvl;

	while ( cin.fail() )
    	{
        	cin.clear(); // unset failbit
        	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // skip bad input
        	cout << "Sorry, your input did not seem to be an int. Try again: ";
        	cin >> i_lvl;
    }

	for(int i=1; i<=myInfectedCityList->getLength(); i++)
	{
		if(myInfectedCityList->getEntry(i).getInfectionlvl() >= i_lvl)
		{
			cout<<myInfectedCityList->getEntry(i).getCityname()<<",";
			cout<<myInfectedCityList->getEntry(i).getPopulation()<<",";
			cout<<myInfectedCityList->getEntry(i).getInfectionlvl()<<endl;
		}
	}
}


MedicalExecutive::~MedicalExecutive()
{
	//Call a linked list destructor?

	//~LinkedList()
	delete myQuarantineCityList;
	delete myInfectedCityList;

}


void MedicalExecutive::run()
{

	int userChoice=0;
do
{

	menu();
	cin>>userChoice;

	while(cin.fail() || (userChoice <1) || (userChoice > 6))
	{
		cin.clear(); //unset failbit
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Skip bad input
		cout<<"Sorry retry input"<<endl<<endl;;
		menu();
		cin>>userChoice;
		cout<<endl;
	}

	if(userChoice ==1)
	{
		Selection1();
	}
	if(userChoice ==2)
	{
		Selection2();
	}
	if(userChoice ==3)
	{
		Selection3();
	}
	if(userChoice==4)
	{
		Selection4();
	}
	if(userChoice ==5)
	{
		Selection5();
	}

	/* 	Note: This was only used during debugging process to print and view after every option~
	if(userChoice==6)
	{
		cout<<"Quarantine List"<<endl;
		for(int i=1;i<=myQuarantineCityList->getLength();i++)
		{
			cout<<myQuarantineCityList->getEntry(i).getCityname()<<" "<<myQuarantineCityList->getEntry(i).getPopulation()<<" "<<myQuarantineCityList->getEntry(i).getInfectionlvl()<<"->";
		}

		cout<<endl<<endl;
		cout<<"\nRegular List"<<endl;
		//Printing to view differences
		for(int i=1;i<=myInfectedCityList->getLength();i++)
		{
			cout<<myInfectedCityList->getEntry(i).getCityname()<<" "<<myInfectedCityList->getEntry(i).getPopulation()<<" "<<myInfectedCityList->getEntry(i).getInfectionlvl()<<"->";
		}
		cout<<endl;
	}
	*/


}while(userChoice != 6);

}


//sort
void MedicalExecutive::Bubblesort(LinkedList<City>* CityPtr)
{
	for(int i=1; i<=CityPtr->getLength(); i++)
	{
		for(int j=1; j<=CityPtr->getLength(); j++)
		{
			if(i != CityPtr->getLength())
			{
				if(CityPtr->getEntry(i).getPopulation() < CityPtr->getEntry(i+1).getPopulation())
				{
					string temp_cityname = CityPtr->getEntry(i+1).getCityname();
					int temp_population = CityPtr->getEntry(i+1).getPopulation();
					int temp_infectionlvl = CityPtr->getEntry(i+1).getInfectionlvl();

					City t_City(temp_cityname, temp_population, temp_infectionlvl);

					CityPtr->removeAt(i+1);

					CityPtr->insert(i, t_City);
				}
			}
			}
	}
}

void MedicalExecutive::duplicates()
{
for(int i=1; i<=myInfectedCityList->getLength(); i++)
{
	if(i != myInfectedCityList->getLength())
	{
		if(myInfectedCityList->getEntry(i).getCityname() == myInfectedCityList->getEntry(i+1).getCityname())
		{
			myInfectedCityList->removeAt(i);
		}
	}
}
}

void MedicalExecutive::monitor()
{
	for(int i=myInfectedCityList->getLength(); i>=1; i--)
	{
		if(myInfectedCityList->getEntry(i).getInfectionlvl() == 1)
		{
			string temp_cityname = myInfectedCityList->getEntry(i).getCityname();
			int temp_population = myInfectedCityList->getEntry(i).getPopulation();
			temp_population = (temp_population * 0.9);
			int temp_infectionlvl = myInfectedCityList->getEntry(i).getInfectionlvl();

			myInfectedCityList->removeAt(i);

			City t_City(temp_cityname, temp_population, temp_infectionlvl);

			sortAdd(myInfectedCityList, t_City);
		}

		if(myInfectedCityList->getEntry(i).getInfectionlvl() == 2)
		{
			string temp_cityname = myInfectedCityList->getEntry(i).getCityname();
			int temp_population = myInfectedCityList->getEntry(i).getPopulation();
			temp_population = (temp_population * 0.8);
			int temp_infectionlvl = myInfectedCityList->getEntry(i).getInfectionlvl();

			myInfectedCityList->removeAt(i);

			City t_City(temp_cityname, temp_population, temp_infectionlvl);

			sortAdd(myInfectedCityList, t_City);
		}
		if(myInfectedCityList->getEntry(i).getInfectionlvl() == 3)
		{
			string temp_cityname = myInfectedCityList->getEntry(i).getCityname();
			int temp_population = myInfectedCityList->getEntry(i).getPopulation();
			temp_population = (temp_population * 0.75);
			int temp_infectionlvl = myInfectedCityList->getEntry(i).getInfectionlvl();

			string temp_newcityname = myInfectedCityList->getEntry(i).getCityname();
			temp_newcityname="New "+temp_newcityname;
			int temp_newpopulation = myInfectedCityList->getEntry(i).getPopulation();
			temp_newpopulation = (temp_population * 0.25);
			int temp_newinfectionlvl = 0;

			myInfectedCityList->removeAt(i);

			City t_City(temp_cityname, temp_population, temp_infectionlvl);
			City t_newCity(temp_newcityname, temp_newpopulation, temp_newinfectionlvl);
			sortAdd(myInfectedCityList, t_City);
			sortAdd(myInfectedCityList, t_newCity);

		}

		if(myInfectedCityList->getEntry(i).getInfectionlvl() >= 4)
		{
			cout<<myInfectedCityList->getEntry(i).getCityname()<<" has been placed in quarantine!"<<endl;

			string temp_cityname = myInfectedCityList->getEntry(i).getCityname();
			int temp_population = myInfectedCityList->getEntry(i).getPopulation();
			int temp_infectionlvl = myInfectedCityList->getEntry(i).getInfectionlvl();

			City t_City(temp_cityname, temp_population, temp_infectionlvl);

			sortAdd(myQuarantineCityList, t_City); //Add to quarantine list
			//Need to remove lvl 4 or higher city ~If a city gets imported as lvl 4 it will be turned to 5 and moved to quarantine list
			myInfectedCityList->removeAt(i);
		}
	}
	//print lists
/*
	for(int i=1;i<=myQuarantineCityList->getLength();i++)
	{
		cout<<myQuarantineCityList->getEntry(i).getCityname()<<" "<<myQuarantineCityList->getEntry(i).getPopulation()<<" "<<myQuarantineCityList->getEntry(i).getInfectionlvl()<<"->";
	}
	cout<<endl<<endl;
	//Printing to view differences
	for(int i=1;i<=myInfectedCityList->getLength();i++)
	{
		cout<<myInfectedCityList->getEntry(i).getCityname()<<" "<<myInfectedCityList->getEntry(i).getPopulation()<<" "<<myInfectedCityList->getEntry(i).getInfectionlvl()<<"->";
	}
*/
}
