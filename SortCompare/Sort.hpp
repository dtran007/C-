/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  Sort.cpp
 *  * Author: Danny Tran
 *  * Description: Sort Class Templated implementation file
 *  * Date: Mar 17, 2017
 *  *
 *  ---------------------------------------------------------------------------- */

template<typename T>
void Sort<T>::quickSort(T arr[], int size)
{
	//quickSort call, sets median bool to false
	quickSortRec(arr, 0, size-1, false);
}


template<typename T>
void Sort<T>::quickSortWithMedian(T arr[], int size)
{
	//quickSortWithMedian call, sets median bool to true
	quickSortRec(arr, 0, size-1, true);
}


template<typename T>
void Sort<T>::quickSortRec(T arr[], int first, int last, bool median)
{
	if(first < last)
	{
		int pIndex =  partition(arr, first, last, median);
		quickSortRec(arr, first, pIndex-1, median);
		quickSortRec(arr, pIndex+1, last, median);
	}
}


template<typename T>
void Sort<T>::setMedianPivot(T arr[], int first, int last)
{
	//Swapping values for Pivot
	//Increases chance for better pivot to better sort time
	int mid = (first + (last - first) /2);

	if(arr[first] > arr[mid])
	{
		std::swap(arr[first], arr[mid]);
	}
	if(arr[mid] > arr[last])
	{
		std::swap(arr[mid], arr[last]);
	}
	if(arr[first] > arr[mid])
	{
		std::swap(arr[first], arr[mid]);
	}

}


template<typename T>
int Sort<T>::partition(T arr[], int first, int last, bool median)
{
	if(median == true) //Check for median bool to implement quickSortWithMedian
	{
		setMedianPivot(arr, first, last);
	}


		int pivot = arr[last];
		int pIndex = first;

		for(int i = first; i<last; i++)
		{
			if(arr[i] <= pivot)
			{
				std::swap(arr[i], arr[pIndex]);
				pIndex++;
			}
		}

	std::swap(arr[pIndex],arr[last]);
	return(pIndex);
}


template<typename T>
void Sort<T>::merge(T* a1, T* a2, int size1, int size2)
{
	int lindex =0;
	int rindex =0;
	int index =0;

	int size= size1 + size2;

	T* temparr = new T[size];

	//Merging arrays into the temparr which is combined size of parameters
	while(lindex < size1 && rindex < size2)
	{
		if(a1[lindex] <= a2[rindex])
		{
			temparr[index] = a1[lindex];
			lindex++;
		}
		else
		{
			temparr[index] = a2[rindex];
			rindex++;
		}

		index++;
	}

	//In event of residual values if conditions to add to temparr
	if(lindex == size1)
	{
		for(int i= rindex; i<size2; i++)
		{
			temparr[index] = a2[i];
			index++;
		}
	}

	if(rindex == size2)
	{
		for(int i = lindex; i<size1; i++)
		{
			temparr[index]= a1[i];
			index++;
		}

	}

	//Temparr considered an auxilary array to copy values over using full size of array
	for(int i=0; i<size; i++)
	{
		a1[i]=temparr[i];
	}

	//Delete auxilary array
	delete[] temparr;
}


template<typename T>
void Sort<T>::mergeSort(T arr[], int size)
{
	if(size<2)
	{
		return;
	}

	int mid=(size/2);

				//Splitting Array into two
				//Same Array but just pointers
	int leftsize=mid; 		//Left Array Size
	int rightsize=(size-mid);	//Right Array Size


	T* leftarr = (arr + 0);
	T* rightarr = (arr + mid);


	mergeSort(leftarr, leftsize);
	mergeSort(rightarr, rightsize);

	merge(leftarr, rightarr, leftsize, rightsize);

	for(int i=0; i<size; i++)
	{
		arr[i] = leftarr[i];
	}

}

template<typename T>
void Sort<T>::bubbleSort(T arr[], int size)  
{
	bool sorted = false; //false when swap occurs
	int pass =1;
	while(!sorted && (pass < size) )
	{
		sorted = true;
		for(int index=0;index<size-pass;index++)
		{
			int nextIndex=index+1;
			if(arr[index]> arr[nextIndex])
			{
				//Exchang entries
				std::swap(arr[index],arr[nextIndex]);
				sorted=false; //signal exchange
			}//end if
		}//end for

		pass++;
	}//end while
} //end bubblesort


template<typename T>
void Sort<T>::insertionSort(T arr[], int size)
{
	for(int unsorted=1; unsorted<size; unsorted++)
	{
		T nextItem = arr[unsorted];
		int loc = unsorted;
		while( (loc>0) && (arr[loc-1] > nextItem) )
		{
			//Shift arr[loc-1] to the right
			arr[loc] = arr[loc-1];
			loc--;
		}

		arr[loc] = nextItem;
	}
}


template<typename T>
int Sort<T>::findIndexofLargest(T arr[], int n)
{

	int indexSoFar=0; //Index of the largest entry found so far
	for(int currentIndex=1; currentIndex<n; currentIndex++)
	{
		//At this point, arr[indeSoFar] >= all entries in arr[0..currentIndex-1]
		if(arr[currentIndex] > arr[indexSoFar])
		{
			indexSoFar = currentIndex;
		}
	}//End for Loop

	return(indexSoFar); //Index of the largest entry
}//end findIndexofLargest


template<typename T>
void Sort<T>::selectionSort(T arr[], int size)
{
	for(int last=size-1; last>=1; last--)
	{
		int largest = findIndexofLargest(arr, last+1);
		//Swap the largest entry, arr[largest] with arr[last]
		std::swap(arr[largest], arr[last]);
	}//end for
}//end selectionSort
