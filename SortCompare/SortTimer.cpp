/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  SortTimer.hpp
 *  * Author: Danny Tran
 *  * Description: SortTimer class implementation file
 *  * Date: Mar 17, 2017
 *  *
 *  ---------------------------------------------------------------------------- */

#include <functional>

template<typename T>
double SortTimer<T>::sortTime(std::function<void(T[], int)> sort, T array[], int size)
	{
		//start the timer
		clock_t t;
		t=clock();

		//call the sort passed in
		sort(array, size);

		//stop the timer
		t=clock()-t;

		//return the time
		return(t/(double)CLOCKS_PER_SEC);
	}
