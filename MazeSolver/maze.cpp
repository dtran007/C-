/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  maze.cpp
 *  * Author: Danny Tran
 *  * Description:  Maze class implementation file
 *  * Date: 3 Mar 2017
 *  *
 *  ---------------------------------------------------------------------------- */

#include "maze.h"

maze::maze(string filename)
{
	ifstream in_stream;

	in_stream.open(filename);

	if(in_stream.fail() )
	{
		cout<<"Fail to open input file. File Does Not Exist.\n";
		exit(1);
	}

	if(in_stream.is_open())
	{
		//		cout<<"File opened."<<endl;
	}

	//Use getline to read in line
	//Substr to fill in array
	int temp_rows=0;
	int temp_cols=0;
	int start_row=0;
	int start_col=0;
	string line="";

	in_stream >> temp_rows;

	in_stream >> temp_cols;

	in_stream >> start_row;

	in_stream >> start_col;
	in_stream.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore buffer

	//	cout<<temp_rows<<" "<<temp_cols<<" "<<start_row<<" "<<start_col<<endl;

	//Try/Catch blocks for checking and catching bad inputs
	try
	{
		setnumRows(temp_rows);
	}
	catch(PreconditionViolationException pve)
	{
		cout<<pve.what()<<endl;
		throw PreconditionViolationException("Not in bounds");
		//exit(1);
	}

	try
	{
		setnumCols(temp_cols);
	}
	catch(PreconditionViolationException pve)
	{
		cout<<pve.what()<<endl;
		throw PreconditionViolationException("Not in bounds");
		//exit(1);
	}

	try
	{
		setstartRow(start_row);
	}
	catch(PreconditionViolationException pve)
	{
		cout<<pve.what()<<endl;
		throw PreconditionViolationException("Not in bounds");
		//exit(1);
	}

	try
	{
		setstartCol(start_col);
	}
	catch(PreconditionViolationException pve)
	{
		cout<<pve.what()<<endl;
		throw PreconditionViolationException("Not in bounds");
		//exit(1);
	}

	//Create an array
	myMaze = new char*[numRows];
	for (int i=0; i<numRows; i++)
	{
		myMaze[i] = new char[numCols];

	}

	//importing maze
	bool eFound=false;

	for(int i=0; i<numRows; i++)
	{
		getline(in_stream, line, '\n');
		for(int j=0; j<numCols; j++)
		{
			myMaze[i][j]=line[j];

			if(myMaze[i][j] == 'E')
			{
				eFound=true;

			}
		}
	}

	//Check for an 'E'char in file
	if(eFound == false)
	{
		throw PreconditionViolationException("Exit Not Found.");
		//cout<<"Exit Not Found."<<endl;
		//exit(1);
	}
	else
	{
		//	cout<<"Exit found."<<endl;
	}

	//Bad Starting Position Test
	if(myMaze[startRow][startCol] == 'X')
	{
		throw PreconditionViolationException("Invalid starting position");
		//cout<<"Invalid Starting Position."<<endl;
		//exit(1);
	}

	cout<<"\nStarting position: "<<getstartRow()<<","<<getstartCol()<<endl;
	cout<<"Size: "<<getnumRows()<<","<<getnumCols()<<endl;

	in_stream.close();
	// mazerunner mazerun(maze_instance.getMaze(), maze_instance.getnumRows(),maze_instance.getnumCols(), maze_instance.getstartRow(), maze_instance.getstartCol());
	mazerunner mazerun(getMaze(), getnumRows(),getnumCols(), getstartRow(), getstartCol());

	mazerun.recursiveWalk(mazerun.getstartRow(), mazerun.getstartCol() );
	for(int i=0; i<mazerun.getnumRows(); i++)
	{
		for(int j=0; j<mazerun.getnumCols(); j++)
		{
			cout<<mazerun.getintMaze()[i][j]<<"\t";
		}
		cout<<endl;
	}

	if(mazerun.getFound())
	{
		cout<<"We escaped!"<<endl;
	}
}


maze::~maze()
{
	//Delete maze
	for(int i=0; i<numRows; i++)
	{
		delete[] myMaze[i];
	}
	delete[] myMaze;
}

char** maze::getMaze() const
{
	return(myMaze);
}


void maze::setnumRows(int numrows) throw(PreconditionViolationException)
{
	if(numrows < 1)
	{
		throw PreconditionViolationException("Error: Row less than 1!");
	}
	else
	{
		numRows=numrows;
	}
}

int maze::getnumRows() const
{
	return(numRows);
}

void maze::setnumCols(int numcols) throw(PreconditionViolationException)
{
	if(numcols < 1) //Exit if column is less than 1
	{
		throw PreconditionViolationException("Error: Column less than 1!");
	}
	else
	{
		numCols=numcols;
	}
}

int maze::getnumCols() const
{
	return(numCols);
}

void maze::setstartRow(int s_row) throw(PreconditionViolationException)
{
	if(s_row < 0 || s_row > numRows)
	{
		throw PreconditionViolationException("Error: Start Row Out of Bounds.");
	}
	else
	{
		startRow=s_row;
	}
}

int maze::getstartRow() const
{
	return(startRow);
}

void maze::setstartCol(int s_col) throw(PreconditionViolationException)
{
	if(s_col < 0 || s_col > numCols)
	{
		throw PreconditionViolationException("Error: Start Column Out of Bounds.");
	}
	else
	{
		startCol=s_col;
	}
}


int maze::getstartCol() const
{
	return(startCol);
}
