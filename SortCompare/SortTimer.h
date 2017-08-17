/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  SortTimer.h
 *  * Author: Danny Tran
 *  * Description: SortTimer Class
 *  * Date: Mar 17, 2017
 *  *
 *  ---------------------------------------------------------------------------- */

//Screen command:
//in terminal
//Keep program running when away
/*
> Screen
>./lab7 ...
>ctrl a + d
>screen -r
*/

#ifndef SORTTIMER_H
#define SORTTIMER_H

#include "Sort.h"

#include <functional>
#include <time.h>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

template<typename T>
class SortTimer
{
	private:

	public:

	/** @pre Needs to take in an array and size.
	*   @post None.
	*   @return Time a sort function runs.
	*/
	double sortTime(std::function<void(T[], int)> sort, T array[], int size);

};


#include "SortTimer.cpp"
#endif
