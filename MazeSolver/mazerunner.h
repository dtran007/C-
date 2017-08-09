/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  mazerunner.h
 *  * Author: Danny Tran
 *  * Description: Mazerunner headerfile
 *  * Date: 3 Mar 2017
 *  *
 *  ---------------------------------------------------------------------------- */

#ifndef MAZERUNNER_H
#define MAZERUNNER_H

#include "PreconditionViolationException.h"
#include "mazerunner.h"
#include "maze.h"


class mazerunner
{
	private:

		char** charArray;
		int numRows;
		int numCols;
		int startRow;
		int startCol;

		int exitRow;
		int exitCol;

		int** intArray;
		bool isValid;
		bool found = false;

		int stepCount=0;
		bool** boolArray;

	public:

		/** @pre None.
		 *   @post returns charArray (Maze) pointer.
		 *   @return None.
		 */
		char** getcharMaze() const;

		/** @pre None.
		 *   @post returns intArray (Maze) pointer.
		 *   @return None.
		 */
		int** getintMaze() const;

		/** @pre Constructor. Takes in mazeptr from Maze Class with member variables.
		 *   @post Creates a boolArray and intArray and also contains charArray.
		 *   @return None.
		 */
		mazerunner(char** mazeptr, int row, int col, int startrow, int startcol); //initialize int array

		/** @pre Takes in row and col parameters from mazerunner
		 *   @post None.
		 *   @return bool upon path of maze.
		 */
		bool recursiveWalk(int row, int col);

		/** @pre None.
		 *   @post Delete array (Maze) off heap memory allocation.
		 *   @return None.
		 */
		~mazerunner();

		/** @pre None.
		 *   @post Node with value entered is created.
		 *   @return found variable. (Class variable if path is found.)
		 */  //Used as one of the control parameter in recursiveWalk calls.
		bool getFound();

		/** @pre None.
		 *   @post set NumRows.
		 *   @return None.
		 */
		void setnumRows(int numrows);

		/** @pre None.
		 *   @post set NumRows.
		 *   @return numRows value.
		 */
		int getnumRows() const;

		/** @pre None.
		 *   @post set NumCols.
		 *   @return None.
		 */
		void setnumCols(int numcols);

		/** @pre None.
		 *   @post None.
		 *   @return numCols value.
		 */
		int getnumCols() const;

		/** @pre None.
		 *   @post set startRow.
		 *   @return None.
		 */
		void setstartRow(int s_row);

		/** @pre None.
		 *   @post None
		 *   @return startRow.
		 */
		int getstartRow() const;

		/** @pre None.
		 *   @post set startCol.
		 *   @return None.
		 */
		void setstartCol(int s_col);

		/** @pre None.
		 *   @post None.
		 *   @return startCol.
		 */
		int getstartCol() const;

		/** @pre None.
		 *   @post set exitRow.
		 *   @return None.
		 */
		void setexitRow(int e_row);

		/** @pre None.
		 *   @post None.
		 *   @return exitRow.
		 */
		int getexitRow() const;

		/** @pre None.
		 *   @post set exitCol.
		 *   @return None.
		 */
		void setexitCol(int e_row);

		/** @pre None.
		 *   @post None.
		 *   @return exitCol.
		 */
		int getexitCol() const;

};
#endif
