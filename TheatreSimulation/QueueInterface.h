/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  QueueInterface.h
 *  * Author: Danny Tran
 *  * Description: QueueInterface Interface File
 *  * Date: 24 Feb 2017
 *  *
 *  ---------------------------------------------------------------------------- */

#ifndef QUEUEINTERFACE_H
#define QUEUEINTERFACE_H

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;


template <typename T>
class QueueInterface
{
	public:
		/** @pre A virtual destructor.
		 *  @post Destructors for all derived classes.
		 *  @return None.
		 */
		virtual ~QueueInterface() {}


		/** @pre A pure virtual method for isEmpty.
		 *  @post A derived Queue class with isEmpty method.
		 *  @return true if the stack is empty, false otherwise
		 */
		virtual bool isEmpty() const = 0;


		/** @pre A pure virtual method for enqueue.
		 *  @post A derived Queue class with enqueue method.
		 *  @return None.
		 */
		virtual void enqueue(const T value) throw(PreconditionViolationException) = 0;

		/** @pre A pure virtual method for dequeue.
		 *  @post A derived Queue class with dequeue method.
		 *  @return None.
		 */
		virtual void dequeue() throw(PreconditionViolationException) = 0;


		/** @pre A pure virtual method for peekFront.
		 *  @post A derived Queue class with peekFront method.
		 *  @return Front entry of Queue.
		 */
		virtual T peekFront() const throw(PreconditionViolationException) = 0;

};
#endif
