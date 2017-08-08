/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  Stack.h
 *  * Author: Danny Tran
 *  * Description: Stack Header File
 *  * Date: 24 Feb 2017
 *  *
 *  ---------------------------------------------------------------------------- */
#ifndef STACK_H
#define STACK_H

#include "PreconditionViolationException.h"
#include "StackInterface.h"
#include "Node.h"

template <typename T>
class Stack : public StackInterface<T>
{

	private:
		/** @pre None.
		 *  @post A pointer to stop of Stack.
		 *  @return None.
		 */
		Node<T>* topPtr;  //Pointer to first node, the Stack's top


		/** @pre None.
		 *  @post Value for size of Stack.
		 *  @return None.
		 */
		int m_size=0;


	public:

		/** @pre None.
		 *  @post Stack Constructor.
		 *  @return None.
		 */
		Stack();


		/** @pre A stack instance.
		 *  @post Destructors delete Stack instance.
		 *  @return None.
		 */
		~Stack();


		/** @pre None.
		 *  @post None.
		 *  @return True if stack is empty.
		 */
		bool isEmpty() const;


		/** @pre None.
		 *  @post Value pushed onto Stack.
		 *  @return None.
		 */
		void push(const T value) throw(PreconditionViolationException);


		/** @pre None.
		 *  @post Value is popped off Stack.
		 *  @return None.
		 */
		void pop() throw(PreconditionViolationException);


		/** @pre None.
		 *  @post None.
		 *  @return Value at top of Stack.
		 */
		T peek() const throw(PreconditionViolationException);


		/** @pre None.
		 *  @post None.
		 *  @return Length of Stack.
		 */
		int getLength() const;


};

#include "Stack.hpp"

#endif
