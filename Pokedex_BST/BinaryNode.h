/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  BinaryNode.h
 *  * Author: Danny Tran
 *  * Description:  Class of Nodesfor link-based binary tree.
 *  * Date: 31 March 2017
 *  *
 *  ---------------------------------------------------------------------------- */
#ifndef BINARYNODE_H
#define BINARYNODE_H

#include <string>

template<typename ItemType>
class BinaryNode
{
	private:
		ItemType item; 			//Data Portion
		BinaryNode<ItemType>* leftChildPtr; 	//Pointer to left child
		BinaryNode<ItemType>* rightChildPtr;	//Pointer to right child

	public:

		/** @pre None.
		 *   @post Constructor create BinaryNode.
		 *   @return None.
		 */
		BinaryNode();

		/** @pre None.
		 *   @post Constructor initialized with ItemType
		 *   @return None.
		 */
		BinaryNode(const ItemType& anItem);

		/** @pre None.
		 *   @post Constructor with leftPtr and rightPtr as parameters.
		 *   @return None.
		 */
		BinaryNode(const ItemType& anItem, BinaryNode<ItemType>* leftPtr, BinaryNode<ItemType>* rightPtr);

		/** @pre None.
		 *   @post Set ItemType to BinaryNode.
		 *   @return None.
		 */
		void setItem(const ItemType& anItem);

		/** @pre None.
		 *   @post Get ItemType at Node.
		 *   @return None.
		 */
		ItemType getItem() const;

		/** @pre None.
		 *   @post None.
		 *   @return Bool regarding if both leftPtr and rightPtr are nullptr.
		 */
		bool isLeaf() const;

		/** @pre None.
		 *   @post None.
		 *   @return Ptr to Left Child.
		 */
		BinaryNode<ItemType>* getLeftChildPtr() const;

		/** @pre None.
		 *   @post None.
		 *   @return Ptr to Right Child.
		 */
		BinaryNode<ItemType>* getRightChildPtr() const;

		/** @pre None.
		 *   @post Set ptr of left child.
		 *   @return None.
		 */
		void setLeftChildPtr(BinaryNode<ItemType>* leftPtr);

		/** @pre None.
		 *   @post Set ptr of right child.
		 *   @return None.
		 */
		void setRightChildPtr(BinaryNode<ItemType>* rightPtr);


};//End BinaryNode
#include "BinaryNode.hpp"
#endif
