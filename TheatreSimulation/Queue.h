/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  Queue.h
 *  * Author: Danny Tran
 *  * Description: Queue headerfile
 *  * Date: 24 Feb 2017
 *  *
 *  ---------------------------------------------------------------------------- */

//Queue- ticket line

#ifndef QUEUE_H
#define QUEUE_H

#include "PreconditionViolationException.h"
#include "QueueInterface.h"
#include "Node.h"


template <typename T>
class Queue : public QueueInterface<T>
{
	private:
		/** @pre None.
		 *  @post None.
		 *  @return None.
		 */
		Node<T>* m_front;

		/** @pre None.
		 *  @post None.
		 *  @return None.
		 */
		Node<T>* m_back;

		/** @pre None.
		 *  @post None.
		 *  @return None.
		 */
		int m_length=0;

	public:
		/** @pre None.
		 *  @post Default constructor.
		 *  @return None.
		 */
		Queue();


		/** @pre None.
		 *  @post Destructor delete Queue instance.
		 *  @return None.
		 */
		~Queue();


		/** @pre None.
		 *  @post None.
		 *  @return true if the stack is empty, false otherwise
		 */
		bool isEmpty() const;

		/** @pre None.
		 *  @post Value is added to back of queue.
		 *  @return None.
		 */
		void enqueue(const T value) throw(PreconditionViolationException);

		/** @pre Assumes queue is not empty.
		 *  @post Front value of queue is removed.
		 *  @return None.
		 */
		void dequeue() throw(PreconditionViolationException);

		/** @pre None.
		 *  @post None.
		 *  @return Returns value of front of queue.
		 */
		T peekFront() const throw(PreconditionViolationException);

		/** @pre Assumes queue is not empty.
		 *  @post None.
		 *  @return Returns value of front of queue.
		 */ //Note: Method is not implemented was only for debug/testing.
		T peekBack() const throw(PreconditionViolationException);

};

#include "Queue.hpp"

#endif
