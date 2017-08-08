/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  Theatre.cpp
 *  * Author: Danny Tran
 *  * Description:  Theatre implementation file for Theatre Class
 *  * Date: 25 Feb 2017
 *  *
 *  ---------------------------------------------------------------------------- */
#include "Theatre.h"

using namespace std;

Theatre::~Theatre()
{
	delete TheatreSeat;
	delete WaitingLine;
}

Theatre::Theatre(string filename)
{
	ifstream in_stream;

	TheatreSeat = new Stack<string>();
	WaitingLine = new Queue<string>();
	in_stream.open(filename);

	if(in_stream.fail())
	{
		std::cout<<"Fail to open input file.\n";
		exit(1);
	}
	// if(in_stream.is_open())
	// {
	//   cout<<"File opened."<<endl;
	// }


	if(in_stream.is_open()) //Precondition: Assuming the file is tab delimited
		//If it is comma delimited, then usage of a comma delimiter is needed
	{			//Note that getline with comma delimited is available but assumed not needed (getline,variable,delim)
		//Opting to go for in_stream>>variable
		//I wonder if I need to use a try catch for import handling if something fails in import?
		while(!in_stream.eof())
		{
			//Declared Variables inside will be reset
			string variable="";
			string temp_name="";
			int num_eject=0;

			in_stream>>variable;

			//getline(in_stream,variable,delim);

			if(variable=="")
			{
				break;
			}//end if check break

			if(variable=="TICKET")  //Ticket Import Block (Enqueue)
			{
				in_stream>>temp_name;
				ticket(temp_name);
				//cout<<WaitingLine->peekBack()<<" <-this is peekBack remove at the end of testing"<<endl;
			}//End of Ticket Import Block


			if(variable=="STATUS") //Status Import Block (Peek)
			{
				status();
				cout<<endl;
			}//End Status Import Block


			if(variable=="SEATING") //Seating Import Block (Peek, Push, Dequeue)
			{
				seating();
			}//End Seating Import Block


			if(variable=="EJECTION") //Eject Import Block
			{

				in_stream>>num_eject;
				cout<<"Ejecting this many folks: "<<num_eject<<endl;
				ejection(num_eject);

			}//End Eject Import Block


			if(variable=="CREDITS") //Credits Import Block
			{
				credits();
			}//End Credits Import Block



		}//end while loop of oef import
	}//end if

	in_stream.close();
}//End constructor



//Command functions
void Theatre::ticket(string name)
{
	try{
		WaitingLine->enqueue(name);
	}
	catch(PreconditionViolationException& pve)
	{
		cout<<pve.what()<<endl;;
	}
}


void Theatre::status()
{

	cout<<"\nWelcome to Theatre CinePlex:"<<endl;
	if(TheatreSeat->isEmpty())
	{
		cout<<"The theatre is empty."<<endl;
	}
	else
	{
		cout<<"The theatre is not empty."<<endl;
	}

	//cout next in line
	if(WaitingLine->isEmpty())
	{
		cout<<"The ticket line is empty."<<endl;
	}
	else
	{
		cout<<WaitingLine->peekFront()<<" is next in the ticket line."<<endl;
	}
	//cout first person to leave theather
	if(TheatreSeat->isEmpty())
	{
		//cout<<"The theatre is empty."<<endl;
	}
	else
	{
		cout<<TheatreSeat->peek()<<" will be the first person to leave the theatre."<<endl;
	}
}


void Theatre::seating()
{
	try
	{
		while(TheatreSeat->getLength() < 10)
		{
			TheatreSeat->push(WaitingLine->peekFront());
			cout<<WaitingLine->peekFront()<<" has left the line."<<endl;
			WaitingLine->dequeue();
		}
	}

	catch(PreconditionViolationException& pve)
	{
		cout<<pve.what()<<endl;
	}
}


void Theatre::ejection(int numPpl)
{
	while(numPpl != 0)
	{
		try
		{
			string temp_ejected = TheatreSeat->peek();
			TheatreSeat->pop();
			cout<<temp_ejected<<" has left the theather."<<endl;
		}
		catch(PreconditionViolationException& pve)
		{
			cout<< pve.what() <<endl;
			break;
		}
		numPpl--;
	}
}

void Theatre::credits()
{
	try{
		while(!(TheatreSeat->isEmpty()) )
		{
			string temp_ejected = TheatreSeat->peek();
			TheatreSeat->pop();
			cout<<temp_ejected<<" has left the theather."<<endl;
		}
	}
	catch(PreconditionViolationException& pve)
	{
		cout<<pve.what()<<endl;
	}
}
