/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  Heap.h
 *  * Author: Danny Tran
 *  * Description: Heap implementation file
 *  * Date: 21 April 17
 *  *
 *  ---------------------------------------------------------------------------- */
#ifndef HEAP_H
#define HEAP_H

#include "HeapInterface.h"

#include <stdexcept>
#include <string>

template <typename T>
class Heap

{
	private:
		T* heapPtr;
		int sizeHeap;
		int sizeArr;


	public:

		//template methods //Similar comments in HeapPriorityQueue
		bool isEmpty() const; 				//returns true if empty, false otherwise
		int size() const; 					//returns size of the heap
		void add(T value) throw (std::runtime_error); 	//option to throw exception based on implementation
		void remove() throw(std::runtime_error); 	//throws exception if there is nothing to remove
		T peekTop() const throw(std::runtime_error); 					//returns the item at the top of the heap

		/** @pre None.
		 *   @post Constructor.
		 *   @return None.
		 */
		Heap();

		/** @pre None.
		 *   @post Constructor with parameter.
		 *   @return None.
		 */
		Heap(int size);

		/** @pre None.
		 *   @post Deconstructor.
		 *   @return None.
		 */
		~Heap();

		/** @pre None.
		 *   @post None.
		 *   @return cout of Heap.
		 */
		void printHeap();

		/** @pre None.
		 *   @post None.
		 *   @return index of Left Child.
		 */
		int getLeftChildIndex(int nodeIndex) const;

		/** @pre None.
		 *   @post None.
		 *   @return Index of Right Child.
		 */
		int getRightChildIndex(int nodeIndex) const;

		/** @pre None.
		 *   @post None.
		 *   @return Index of Parent.
		 */
		int getParentIndex(int nodeIndex) const;

		/** @pre None.
		 *   @post None.
		 *   @return Bool if node is leaf.
		 */
		bool isLeaf(int nodeIndex) const;

		/** @pre None.
		 *   @post Min heap structure is upheld (Downheaps the datastructure )
		 *   @return None.
		 */ //Method of the Book
		void heapRebuild(int subTreeRootIndex);

		/** @pre None.
		 *   @post None.
		 *   @return Bool if a right child exists.
		 */
		bool rightChildCheck(int subTreeRootIndex);
};

#include "Heap.hpp"
#endif
