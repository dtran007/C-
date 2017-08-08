/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  StackInterface.h
 *  * Author: Danny Tran
 *  * Description: StackInterface for Stack Classes
 *  * Date: 24 Feb 2017
 *  *
 *  ---------------------------------------------------------------------------- */
#ifndef STACKINTERFACE_H
#define STACKINTERFACE_H

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

template <typename T>
class StackInterface
{
	public:
		/** @pre A virtual destructor.
		 *  @post Destructors for all derived classes.
		 *  @return None.
		 */
		virtual ~StackInterface() {};


		/** @pre A pure virtual method for Stack classes.
		 *  @post isEmpty method for derived Stack classes.
		 *  @return True if stack is empty.
		 */
		virtual bool isEmpty() const = 0;

		/** @pre A pure virtual method for Stack classes.
		 *  @post A push method for Stack class.
		 *  @return None.
		 */
		virtual void push(const T value) throw(PreconditionViolationException) = 0;


		/** @pre A pure virtual method for Stack classes.
		 *  @post A pop method for Stack class.
		 *  @return None.
		 */
		virtual void pop() throw(PreconditionViolationException) = 0;


		/** @pre A pure virtual method for Stack classes.
		 *  @post A peek method for Stack class.
		 *  @return Value at top of Stack.
		 */
		virtual T peek() const throw(PreconditionViolationException) = 0;

};
#endif
