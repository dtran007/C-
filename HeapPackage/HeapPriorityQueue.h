/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  HeapPriorityQueue.h
 *  * Author: Danny Tran
 *  * Description:  HeapPriorityQueue Header File
 *  * Date: 21 April 2017
 *  *
 *  ---------------------------------------------------------------------------- */

#ifndef HEAPPRIORITYQUEUE_H
#define HEAPPRIORITYQUEUE_H

#include "Heap.h"
#include <string>
#include <stdexcept>

template<typename T>
class HeapPriorityQueue
{
	private:

		Heap<T>* myHeap;

	public:

		/** @pre None.
		 *   @post None.
		 *   @return cout of Heap.
		 */
		void printHeap();

		/** @pre None.
		 *   @post HeapPriorityQueue Constructor.
		 *   @return None.
		 */
		HeapPriorityQueue(int startSize);

		/** @pre None.
		 *   @post HeapPriorityQueue Deconstructor.
		 *   @return None.
		 */
		~HeapPriorityQueue();

		/** @pre None.
		 *   @post None.
		 *   @return Bool if Heap is empty.
		 */
		bool isEmpty() const;

		/** @pre None.
		 *   @post Added a new T entry (Package) to Heap.
		 *   @return None.
		 */
		void add(const T& newEntry) throw(std::runtime_error);

		/** @pre None.
		 *   @post Remove a T entry (Package) from Heap.
		 *   @return None.
		 */
		void remove() throw(std::runtime_error);

		/** @pre None.
		 *   @post None.
		 *   @return Look at first item in Heap.
		 */
		T peekTop() const throw(std::runtime_error);

};

#include "HeapPriorityQueue.hpp"
#endif
