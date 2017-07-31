/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  MedicalExecutive.h
 *  * Author: Danny Tran
 *  * Description:Headerfile for Medical Executive Class
 *  * Date: 10 Feb 2017
 *  *
 *  ---------------------------------------------------------------------------- */

#ifndef MEDICALEXECUTIVE_H
#define MEDICALEXECUTIVE_H
#include <iostream>
#include <fstream> //For file I/O
#include <cstdlib> //For exit
#include <limits>  //For failbit
#include <string>

#include "LinkedList.h"

using namespace std;

class MedicalExecutive
{
	public:

		/** @pre None.
		 *   @post Constructor to read in file and create Lists
		 *   @return None
		 */
		MedicalExecutive(string filename);

		/** @pre None.
		 *   @post Deletes all LinkedList<City>*
		 *   @return None.
		 */
		~MedicalExecutive();

		/** @pre Needs CityPtr and City to utilize
		 *   @post Adds Node to LinkedList in Sorted Fashion.
		 *   @return None.
		 */
		void sortAdd(LinkedList<City>* CityPtr, City tmp_City);

		/** @pre None.
		 *   @post Prints Menu.
		 *   @return None.
		 */
		void menu();

		/** @pre None.
		 *   @post Runs Menu and Selections.
		 *   @return None.
		 */
		void run();

		/** @pre None.
		 *   @post Node infection levels increase by one.
		 *   @return None.
		 */
		void Selection1();

		/** @pre None.
		 *   @post Specific Node infection level increased by one.
		 *   @return None.
		 */
		void Selection2();

		/** @pre None.
		 *   @post Status of Specific Node Printed.
		 *   @return None.
		 */
		void Selection3();

		/** @pre None.
		 *   @post None.
		 *   @return Quarantine log outputted.
		 */
		void Selection4();

		/** @pre None.
		 *   @post None.
		 *   @return Out put above certain threshold printed.
		 */
		void Selection5();


		/** @pre N/A Ended up not being used. Would loop thorugh list and take action based on infection level.
		 *   @post N/A
		 *   @return N/A
		 */
		void monitor();

		/** @pre N/A Implementation was not used. But would sort a LinkedList to be in order.
		 *   @post N/A
		 *   @return N/A
		 */
		void Bubblesort(LinkedList<City>* CityPtr);

		/** @pre N/A Not used but would remove duplicates from Linked List
		 *   @post N/A
		 *   @return N/A
		 */
		void duplicates();

	private:
		/** @pre N/A
		 *   @post LinkedList Pointer
		 *   @return N/A
		 */
		LinkedList<City>* myInfectedCityList;

		/** @pre N/A
		 *   @post LinkedList Pointer
		 *   @return N/A
		 */
		LinkedList<City>* myQuarantineCityList;

};
#endif
