/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  maze.h
 *  * Author: Danny Tran
 *  * Description:  Maze class header file
 *  * Date: 3 Mar 2017
 *  *
 *  ---------------------------------------------------------------------------- */

#ifndef MAZE_H
#define MAZE_H

#include "PreconditionViolationException.h"
#include "mazerunner.h"

#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <limits>

using namespace std;

class maze
{
	private:
		char** myMaze=nullptr;
		int numRows;
		int numCols;
		int startRow;
		int startCol;

	public:
		/** @pre Constructor. Needs proper file as input as parameter.
		 *   @post Private member variables are set from file data.
		 *   @return None.
		 */
		maze(string filename);

		/** @pre Destructor.
		 *   @post Deletes array which is heap memory allocated.
		 *   @return None.
		 */
		~maze();

		/** @pre None.
		 *   @post None.
		 *   @return Array (Maze) pointer.
		 */
		char** getMaze() const;

		/** @pre None.
		 *   @post set numRows variable.
		 *   @return None.
		 */
		void setnumRows(int numrows) throw(PreconditionViolationException);

		/** @pre None.
		 *   @post None.
		 *   @return numRows value.
		 */
		int getnumRows() const;

		/** @pre None.
		 *   @post Sets numCols.
		 *   @return None.
		 */
		void setnumCols(int numcols) throw(PreconditionViolationException);

		/** @pre None.
		 *   @post None.
		 *   @return numCols value.
		 */
		int getnumCols() const;

		/** @pre None.
		 *   @post set startRow.
		 *   @return None.
		 */
		void setstartRow(int s_row) throw(PreconditionViolationException);

		/** @pre None.
		 *   @post None.
		 *   @return startRow value.
		 */
		int getstartRow() const;

		/** @pre None.
		 *   @post set startCol
		 *   @return None.
		 */
		void setstartCol(int s_col) throw(PreconditionViolationException);

		/** @pre None.
		 *   @post None.
		 *   @return startCol value
		 */
		int getstartCol() const;

};
#endif
