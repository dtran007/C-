/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  Theatre.h
 *  * Author: Danny Tran
 *  * Description:  Theatre.h header file for implementing Theatre Class
 *  * Date: 24 Feb 2017
 *  *
 *  ---------------------------------------------------------------------------- */
#ifndef THEATRE_H
#define THEATRE_H

#include "Node.h"
#include "Stack.h"
#include "StackInterface.h"
#include "Queue.h"
#include "QueueInterface.h"


#include <iostream>
#include <string>
#include <fstream>

class Theatre
{
	private:
		/** @pre None.
		 *  @post Pointer to Stack.(The theatre seats.)
		 *  @return None.
		 */
		Stack<string>* TheatreSeat;

		/** @pre None.
		 *  @post Pointer to the Queue (The waiting line.)
		 *  @return None.
		 */
		Queue<string>* WaitingLine;

	public:
		/** @pre Requires action-text file as parameter.
		 *  @post Constructor runs all instances of actions.
		 *  @return None.
		 */
		Theatre(string filename);


		/** @pre Assumes a constructor instance is done.
		 *  @post Deleted pointers used in constructor.
		 *  @return None.
		 */
		~Theatre();


		/** @pre None
		 *  @post Name added to back of Queue.
		 *  @return None.
		 */
		void ticket(string name);


		/** @pre None.
		 *  @post None.
		 *  @return The status of the Movie Theater.
		 */
		void status();


		/** @pre Assumes an non-empty Queue and non-full stack.
		 *  @post Entry from Queue is taken and pushed onto Stack.
		 *  @return Message of who is dequeued.
		 */
		void seating();

		/** @pre None.
		 *  @post Number of entries popped off stack.
		 *  @return Name of entries popped off stack.
		 */
		void ejection(int numPpl);

		/** @pre None.
		 *  @post All entries popped off stack.
		 *  @return Name of entries popped off stack.
		 */
		void credits();

};
#endif
