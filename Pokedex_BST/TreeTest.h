/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  TreeTest.h
 *  * Author: Danny Tran
 *  * Description:  TreeTest header file.
 *  * Date: 31 March 2017
 *  *
 *  ---------------------------------------------------------------------------- */

#ifndef TREETEST_H
#define TREETEST_H

#include "BinarySearchTree.h"
#include "Pokemon.h"
#include "Executive.h"
#include "BinaryNode.h"

class TreeTest
{
	public:

		/** @pre None.
		 *   @post Constructor.
		 *   @return None.
		 */
		TreeTest();

		/** @pre None.
		 *   @post Menu cout.
		 *   @return None.
		 */
		void menu();

		/** @pre None.
		 *   @post Run Function to run all test methods.
		 *   @return None.
		 */
		void runTest(BinarySearchTree<Pokemon, std::string> bst);

		/** @pre None.
		 *   @post Add to BST method test.
		 *   @return Cout List Inorder.
		 */
		void testAdds(BinarySearchTree<Pokemon, std::string> bst);

		/** @pre None.
		 *   @post Removes from BST method test.
		 *   @return Cout List in Inorder.
		 */
		void testRemoves(BinarySearchTree<Pokemon, std::string> bst);

		/** @pre None.
		 *   @post Ofstream BST inorder traversal test method.
		 *   @return File output.
		 */
		void testWriteToFile(BinarySearchTree<Pokemon, std::string> bst);

		/** @pre None.
		 *   @post Helper ofstream method with traveral type.
		 *   @return None.
		 */
		static void Write(Pokemon& pokemon);

		/** @pre None.
		 *   @post Helper cout method with traversal type.
		 *   @return None.
		 */
		static void Display(Pokemon& pokemon);

		/** @pre None.
		 *   @post Format string method.
		 *   @return Uppcase first character of string. Lowercase rest of string.
		 */
		static std::string NameFormat(std::string name);

};
#endif
