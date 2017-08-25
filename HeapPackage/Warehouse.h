/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  Warehouse.h
 *  * Author: Danny Tran
 *  * Description:  Warehouse Headerfile
 *  * Date: 21 April 2017
 *  *
 *  ---------------------------------------------------------------------------- */
#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include "Package.h"
#include "Heap.h"
#include "HeapPriorityQueue.h"

#include <string>
#include <iostream>

class Warehouse
{
	private:

		HeapPriorityQueue<Package>* packageHeap;


	public:

		/** @pre None.
		 *   @post Constructor of Warehouse.
		 *   @return None.
		 */
		Warehouse();

		/** @pre None.
		 *   @post Constructor with parameter.
		 *   @return None.
		 */
		Warehouse(std::string filename);

		/** @pre None.
		 *   @post Destructor of Warehouse.
		 *   @return None.
		 */
		~Warehouse();

};
#endif
