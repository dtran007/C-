/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  BinarySearchTree.h
 *  * Author: Danny Tran
 *  * Description:  Header file for link-based implementation of BinarySearchTree
 *  * Date: 31 March 2017
 *  *
 *  ---------------------------------------------------------------------------- */

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "BinaryNode.h"
#include "NotFoundException.h"

#include <string>
#include <iostream>

using namespace std;

template<typename ItemType, typename KeyType>
class BinarySearchTree
{

	private:
		BinaryNode<ItemType>* rootPtr;
		int numNode;

		//protected:

		/** @pre A call from public search.
		 *   @post None.
		 *   @return Bool if searchKey is within BST.
		 */
		bool recSearch(const KeyType& searchKey, BinaryNode<ItemType>* subTreePtr);

		/** @pre None.
		 *   @post Connect Node to BST to consider it added to tree.
		 *   @return None.
		 */
		BinaryNode<ItemType>* recAdd(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNodePtr);

		/** @pre None.
		 *   @post Delete Node from BST recursively.
		 *   @return None.
		 */
		void destroyTree(BinaryNode<ItemType>* subTreePtr);

	public:

		/** @pre None.
		 *   @post None.
		 *   @return Number of nodes added in BST
		 */
		int getnumNode();

		/** @pre None.
		 *   @post Public search call to recSearch.
		 *   @return Bool if searchKey is in BST.
		 */
		bool search(const KeyType& searchKey);


		/** @pre None.
		 *   @post Create new node to add to BST.
		 *   @return None.
		 */
		void add(const ItemType& newData) throw(NotFoundException);


		/** @pre None.
		 *   @post None.
		 *   @return Node entry info.
		 */
		BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* subTreePtr, const KeyType& target) const;

		/** @pre None.
		 *   @post None.
		 *   @return ItemType in BST that contains KeyType.
		 */
		ItemType getEntry(const KeyType& anEntry) const throw(NotFoundException);


		/** @pre None.
		 *   @post Recursive preOrder traverse.
		 *   @return None.
		 */
		void preOrder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;

		/** @pre None.
		 *   @post Call to preOrder recursion.
		 *   @return None.
		 */
		void preorderTraverse(void visit(ItemType&) ) const;

		/** @pre None.
		 *   @post Recursive postOrder traverse.
		 *   @return None.
		 */
		void postOrder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;

		/** @pre None.
		 *   @post Call to postOrder recursion.
		 *   @return None.
		 */
		void postorderTraverse(void visit(ItemType&) ) const;

		/** @pre None.
		 *   @post Resurive inOrder traverse.
		 *   @return None.
		 */
		void inOrder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;

		/** @pre None.
		 *   @post Call to inOrder traverse.
		 *   @return None.
		 */
		void inorderTraverse(void visit(ItemType&)) const;

		/** @pre None.
		 *   @post Constructor.
		 *   @return None.
		 */
		BinarySearchTree();

		/** @pre None.
		 *   @post Destructor.
		 *   @return None.
		 */
		virtual ~BinarySearchTree();


		/** @pre None.
		 *   @post None.
		 *   @return BinaryNode* to deep copy of a BST.
		 */
		BinaryNode<ItemType>* copyTree(const BinaryNode<ItemType>* copytreePtr) const;

		/** @pre None.
		 *   @post Deep Copy of BinarySearchTree constructor.
		 *   @return None.
		 */
		BinarySearchTree(const BinarySearchTree<ItemType, KeyType>& treePtr);

		/** @pre None.
		 *   @post Call to the recursive copyTree.
		 *   @return None.
		 */
		void copy(BinarySearchTree<ItemType, KeyType>* treePtr);


		/** @pre None.
		 *   @post Call to remove Node that contains Key.
		 *   @return None.
		 */
		void remove(const KeyType& removeKey) throw(NotFoundException);

		/** @pre None.
		 *   @post Call to remove ItemType from BST.
		 *   @return None.
		 */
		BinaryNode<ItemType>* removeValue(BinaryNode<ItemType>* subTreePtr, const KeyType target, bool& success);

		/** @pre None.
		 *   @post Call to remove Leaft from BST.
		 *   @return None.
		 */
		BinaryNode<ItemType>* removeNode(BinaryNode<ItemType>* nodePtr);

		/** @pre None.
		 *   @post Call to find leftmost node in right subtree to replace removed node.
		 *   @return None.
		 */
		BinaryNode<ItemType>* removeLeftmostNode(BinaryNode<ItemType>* nodePtr, ItemType& successor);


};
#include "BinarySearchTree.hpp"
#endif
