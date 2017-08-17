/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  Sort.h
 *  * Author: Danny Tran
 *  * Description: Sort Class
 *  * Date: Mar 17, 2017
 *  *
 *  ---------------------------------------------------------------------------- */

#ifndef SORT_H
#define SORT_H

using namespace std;

template<typename T>
class Sort

{
	private:

	/** @pre Called and used by mergeSort
	*   @post None.
	*   @return Merged array.
	*/
	static void merge(T* a1, T* a2, int size1, int size2);


	/** @pre Recursion called by quickSort and quickSortWithMedian
	*   @post None.
	*   @return Sorted array
	*/
	static void quickSortRec(T arr[], int first, int last, bool median);


	/** @pre Used by quickSortWithMedian
	*   @post Swaps median Pivot between first, middle and last array values
	*   @return None.
	*/
	static void setMedianPivot(T arr[], int first, int last);


	/** @pre Used by quickSort and quickSortWithMedian, chooses pivot based on median flag
 	*	 if median is true, use setMedianPivot, otherwise select last element in array
	*   @post None.
	*   @return None.
	*/
	static int partition(T arr[], int first, int last, bool median);


	/** @pre Used by selectionSort
	*   @post None.
	*   @return index of largest element
	*/
	static int findIndexofLargest(T arr[], int size);

	public:

	/** @pre None.
	*   @post Sorted array via iterative method
	*   @return None.
	*/
	static void bubbleSort(T arr[], int size);


	/** @pre None.
	*   @post Sorted array via iterative method
	*   @return None.
	*/
	static void insertionSort(T arr[], int size);


	/** @pre None.
	*   @post Sorted array via recursive method
	*   @return None.
	*/
	static void mergeSort(T arr[], int size);


	/** @pre None.
	*   @post Sorted array via recursive method
	*   @return None.
	*/
	static void quickSort(T arr[], int size);


	/** @pre None.
	*   @post Sorted array via recursive method
	*   @return None.
	*/
	static void quickSortWithMedian(T arr[], int size);


	/** @pre None.
	*   @post Sort array via iterative method
	*   @return None.
	*/
	static void selectionSort(T arr[], int size);


};

#include "Sort.hpp"

#endif
