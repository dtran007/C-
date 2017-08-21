/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  Executive.h
 *  * Author: Danny Tran
 *  * Description:  Executive File for Lab08
 *  * Date: 31 March 2017
 *  *
 *  ---------------------------------------------------------------------------- */

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <iostream>
#include <fstream>
#include <cstdlib> //For exit
#include <limits> //for failbit
#include <string>
#include <locale> //std::locale, std::toupper
#include "BinaryNode.h"
#include "BinarySearchTree.h"
#include "Pokemon.h"
#include "TreeTest.h"


using namespace std;

class Executive
{
	public:

		/** @pre None.
		 *   @post Helper cout function.
		 *   @return None.
		 */
		static void display(Pokemon& pokemon);

		/** @pre None.
		 *   @post Helper ofstream Function
		 *   @return None.
		 */
		static void write(Pokemon& pokemon);

		/** @pre None.
		 *   @post Constructor takes in command line input file argument.
		 *   @return None.
		 */
		Executive(string filename);

		/** @pre None.
		 *   @post Deconstructor.
		 *   @return None.
		 */
		~Executive();

		/** @pre None.
		 *   @post Format string to Uppercase first letter. Lowercase rest of string.
		 *   @return None.
		 */
		static std::string nameFormat(std::string name);

		/** @pre None.
		 *   @post Run function.
		 *   @return None.
		 */
		void run();

		/** @pre None.
		 *   @post Menu cout
		 *   @return None.
		 */
		void menu();


	private:

		BinarySearchTree<Pokemon, std::string>* BST;
		BinarySearchTree<Pokemon, std::string>* copyBST;
		bool copyCreated;

};
#endif
