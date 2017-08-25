/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  Heap.hpp
 *  * Author: Danny Tran
 *  * Description: Heap Implmentation
 *  * Date: 21 April 2017
 *  *
 *  ---------------------------------------------------------------------------- */
#include<iostream>
#include<string>

using namespace std;

template<typename T>
void Heap<T>::printHeap()
{
	if(sizeHeap == 0)
	{
		cout<<"No packages are in Heap. Empty!";
	}
	else
	{
		for(int i=0; i<sizeHeap; i++)
		{
			cout<<heapPtr[i].getPriority()<<","
	      		<<heapPtr[i].getContent()<<","
		   	 <<heapPtr[i].getDestination()<<"\n";
		}
	}
}

template<typename T>
int Heap<T>::getLeftChildIndex(int nodeIndex) const
{
	return( (2*nodeIndex) + 1);
}

template<typename T>
int Heap<T>::getRightChildIndex(int nodeIndex) const
{
	return( (2*nodeIndex) + 2);
}

template<typename T>
int Heap<T>::getParentIndex(int nodeIndex) const
{
	return( (nodeIndex - 1) / 2 );
}


template<typename T>
bool Heap<T>::isLeaf(int nodeIndex) const
{
	if( nodeIndex >= (sizeHeap/2) && nodeIndex <= sizeHeap)
	{
		return(true);
	}
	return(false);
}

template<typename T>
bool Heap<T>::isEmpty() const
{
	if(sizeHeap == 0)
	{
		return(true);
	}

	return(false);
}

template<typename T>
int Heap<T>::size() const
{
	return(sizeHeap);
}


template<typename T>
T Heap<T>::peekTop() const throw(std::runtime_error)
{
	if(isEmpty() )
	{
		throw(std::runtime_error("Error: Heap is empty. Cannot Peek.\n"));
	}
	return(heapPtr[0]);
}

template<typename T>
void Heap<T>::add(T value) throw(std::runtime_error)
{
	if(sizeHeap >= sizeArr) //Resize
	{
		T* tempArr = new T[sizeArr*2];

		for(int i=0;i<sizeHeap; i++)
		{
			tempArr[i] = heapPtr[i];
		}

		delete[] heapPtr;
		heapPtr = tempArr;
		sizeArr=(sizeArr*2);
	}

	heapPtr[sizeHeap] = value;

	int valueIndex=sizeHeap;

	bool inPlace = false;

	while((valueIndex>0) && !inPlace)
	{
		int parentIndex = ((valueIndex-1)/2);
		if(heapPtr[parentIndex] < heapPtr[valueIndex]) //Min Heap
		{
			inPlace = true;
		}
		else
		{
			T temp = heapPtr[parentIndex];
			heapPtr[parentIndex] = heapPtr[valueIndex];
			heapPtr[valueIndex]=temp;

			valueIndex = parentIndex;
		}
	}
	sizeHeap++;
}

template<typename T>
void Heap<T>::remove() throw(std::runtime_error)
{
	if(isEmpty())
	{
		throw std::runtime_error("Error: Cannot remove when Empty!");
	}
	else
	{
		heapPtr[0] = heapPtr[sizeHeap-1];
		sizeHeap--;

		heapRebuild(0);
	}
}

template<typename T>
bool Heap<T>::rightChildCheck(int subTreeRootIndex)
{
	int rightChildIndex = ((2*subTreeRootIndex) +1);

	return(rightChildIndex <= sizeHeap-1);
}


template<typename T> //Min Heap - Books calls it heapRebuid but is similar to downHeap
void Heap<T>::heapRebuild(int subTreeRootIndex)
{
	if( !(isLeaf(subTreeRootIndex)) )
	{

		int smallerChildIndex =  ((2*subTreeRootIndex)+1);

		if( rightChildCheck(subTreeRootIndex) )
		{
			int rightChildIndex = smallerChildIndex+1;

			if(heapPtr[rightChildIndex] < heapPtr[smallerChildIndex])
			{
				smallerChildIndex = rightChildIndex;
			}
		}

		if(heapPtr[subTreeRootIndex] > heapPtr[smallerChildIndex])
		{
			T temp = heapPtr[subTreeRootIndex];

			heapPtr[subTreeRootIndex] = heapPtr[smallerChildIndex];

			heapPtr[smallerChildIndex] = temp;

			heapRebuild(smallerChildIndex);
		}
	}
}

template<typename T>
Heap<T>::Heap()
{

}

template<typename T>
Heap<T>::Heap(int size)
{
	heapPtr = new T[size];
	sizeArr=size;
	sizeHeap=0;
}


template<typename T>
Heap<T>::~Heap()
{
	delete[] heapPtr;
}
