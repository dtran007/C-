/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  mazerunner.cpp
 *  * Author: Danny Tran
 *  * Description:  Mazerunner implementation file
 *  * Date: 3 Mar 2017
 *  *
 *  ---------------------------------------------------------------------------- */
#include <iostream>

#include "mazerunner.h"
#include "maze.h"

using namespace std;

mazerunner::mazerunner(char** mazeptr, int row, int col, int startrow, int startcol)
	: charArray(mazeptr), numRows(row), numCols(col), startRow(startrow), startCol(startcol)
{
	//initialize int array
	//This array houses the stepCount in recursiveWalk
	intArray = new int*[numRows];
	for (int i=0; i<numRows; i++)
	{
		intArray[i] = new int[numCols];
	}

	//Fill in intArray
	for(int i=0; i<numRows; i++)
	{
		for(int j=0; j<numCols; j++)
		{
			if(charArray[i][j] == 'X')
			{
				intArray[i][j] = 0;
			}
			else if (charArray[i][j] == ' ')
			{
				intArray[i][j] = 0;

			}
			else if (charArray[i][j] == 'E')
			{
				intArray[i][j] = 0;
				setexitRow(i);
				setexitCol(j);
			}
		}
	}


	//Creating a markedArray
	//This is for preventing backtracking in the recursiveWalk iteration calls.
	boolArray = new bool*[numRows];
	for (int i=0; i<numRows; i++)
	{
		boolArray[i] = new bool[numCols];
	}

	for(int i=0; i<numRows; i++)
	{
		for(int j=0; j<numCols; j++)
		{
			boolArray[i][j] = false;
		}
	}
}

bool mazerunner::recursiveWalk(int row, int col) //starting position parameters
{
	stepCount++;

	if(row>=0 && col>=0 && row<=numRows && col<=numCols) //in bounds check
	{

		if(row==exitRow && col==exitCol)  //base case finding E/Exit
		{
			//mark the exit when reached
			intArray[row][col] = stepCount;
			boolArray[row][col] = true;
			found = true;

			return(true);
		}

		if(charArray[row][col] == 'X')
		{
			return(false);
		}
		//mark [row][col] as part of the solution path
		//marking the Start space on the intArray as count#
		intArray[row][col] = stepCount;

		boolArray[row][col]= true;
		//1 is marked path so no backtracking
		if( charArray[row-1][col] != 'X' && boolArray[row-1][col] == false && !found)
		{ //up
			recursiveWalk(row-1, col);
		}

		if( charArray[row][col+1] != 'X' && boolArray[row][col+1] == false && !found)
		{ //right
			recursiveWalk(row, col+1);
		}

		if( charArray[row+1][col] != 'X' && boolArray[row+1][col] == false && !found)
		{ //down
			recursiveWalk(row+1, col);
		}

		if( charArray[row][col-1] != 'X' && boolArray[row][col-1] == false && !found)
		{ //left
			recursiveWalk(row, col-1);
		}

		//unmark x,y path
		if(!found)
		{
			stepCount--;
			//intArray[row][col]=stepCount--;
			intArray[row][col]=0;
		}
	}
	return(found);
}//End recursiveWalk


bool mazerunner::getFound()
{
	return(found);
}

int** mazerunner::getintMaze() const
{
	return(intArray);
}

char** mazerunner::getcharMaze() const
{
	return(charArray);
}

void mazerunner::setexitRow(int e_row)
{
	exitRow=e_row;
}

int mazerunner::getexitRow() const
{
	return(exitRow);
}

void mazerunner::setexitCol(int e_col)
{
	exitCol=e_col;
}

int mazerunner::getexitCol() const
{
	return(exitCol);
}

void mazerunner::setnumRows(int numrows)
{
	numRows=numrows;
}

int mazerunner::getnumRows() const
{
	return(numRows);
}

void mazerunner::setnumCols(int numcols)
{
	numCols=numcols;
}

int mazerunner::getnumCols() const
{
	return(numCols);
}

void mazerunner::setstartRow(int s_row)
{
	startRow=s_row;
}

int mazerunner::getstartRow() const
{
	return(startRow);
}

void mazerunner::setstartCol(int s_col)
{
	startCol=s_col;
}

int mazerunner::getstartCol() const
{
	return(startCol);
}

mazerunner::~mazerunner()
{
	for(int i=0; i<numRows; i++)
	{
		delete intArray[i];
		delete boolArray[i];

	}
	delete[] intArray;
	delete[] boolArray;

}
