/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  HeapPriorityQueue.hpp
 *  * Author: Danny Tran
 *  * Description:  Implementation of HeapPriorityQueue
 *  * Date: 21 April 2017
 *  *
 *  ---------------------------------------------------------------------------- */

 template<typename T>
 void HeapPriorityQueue<T>::printHeap()
 {
	 myHeap->printHeap();
 }

template<typename T>
HeapPriorityQueue<T>::HeapPriorityQueue(int startSize) :  myHeap(new Heap<T>(startSize))
{

}

template<typename T>
HeapPriorityQueue<T>::~HeapPriorityQueue()
{
	delete myHeap;
}


template<typename T>
bool HeapPriorityQueue<T>::isEmpty() const
{
	return Heap<T>::isEmpty();
}


template<typename T>
void HeapPriorityQueue<T>::add(const T& newEntry) throw(std::runtime_error)
{
	try
	{
		myHeap->add(newEntry);
	}
	catch(std::runtime_error e)
	{
		throw std::runtime_error("Error: Add cannot be done on heap\n");
	}
}

template<typename T>
void HeapPriorityQueue<T>::remove() throw(std::runtime_error)
{
	try
	{
		myHeap->remove();
	}
	catch(std::runtime_error e)
	{
		throw std::runtime_error("Error: Remove cannot be done on heap\n.");
	}
}

template<typename T>
T HeapPriorityQueue<T>::peekTop() const throw(std::runtime_error)
{
	try
	{
		T tempPeek = myHeap->peekTop();
		return(tempPeek);
	}
	catch(std::runtime_error e)
	{
		throw std::runtime_error("Error: Peek into empty priority queue.");
	}

}
