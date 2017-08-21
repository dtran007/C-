/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  BinarySearchTree.cpp
 *  * Author: Danny Tran
 *  * Description:
 *  * Date: 31 March 2017
 *  *
 *  ---------------------------------------------------------------------------- */
//Either Method functions or pseudocode were taken from the book:
//Prentic.Hall.Data.Abstraction -Author:Carrano Methods

template<typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::inorderTraverse(void visit(ItemType&)) const
{
	inOrder(visit, rootPtr);
}

template<typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::inOrder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
	if(treePtr!=nullptr)
	{
		inOrder(visit, treePtr->getLeftChildPtr());
		ItemType theItem = treePtr->getItem();
		visit(theItem);
		inOrder(visit, treePtr->getRightChildPtr());
	}//end if
}//end inOrder

template<typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::preorderTraverse(void visit(ItemType&)) const
{
	preOrder(visit, rootPtr);
}

template<typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::preOrder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
	if(treePtr!=nullptr)
	{
		ItemType theItem = treePtr->getItem();
		visit(theItem);
		preOrder(visit, treePtr->getLeftChildPtr());
		preOrder(visit, treePtr->getRightChildPtr());

	}//end if
}//end preOrder

template<typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::postorderTraverse(void visit(ItemType&) ) const
{
	postOrder(visit, rootPtr);
}

template<typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::postOrder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
	if(treePtr!=nullptr)
	{
		postOrder(visit, treePtr->getLeftChildPtr());
		postOrder(visit, treePtr->getRightChildPtr());
		ItemType theItem = treePtr->getItem();
		visit(theItem);
	}
}


	template<typename ItemType, typename KeyType>
bool BinarySearchTree<ItemType, KeyType>::search(const KeyType& searchKey)
{
	return( recSearch(searchKey, rootPtr) );

}

	template<typename ItemType, typename KeyType>
bool BinarySearchTree<ItemType, KeyType>::recSearch(const KeyType& searchKey, BinaryNode<ItemType>* subTreePtr)
{
	if(subTreePtr == nullptr)
	{
		return(false);
	}
	else if(subTreePtr->getItem().getAPname() == searchKey)
	{
		return(true);
	}
	else if(searchKey < subTreePtr->getItem().getAPname() )
	{
		return( recSearch(searchKey, subTreePtr->getLeftChildPtr()) );
	}
	else
	{
		return( recSearch(searchKey, subTreePtr->getRightChildPtr()) );
	}
}


	template<typename ItemType, typename KeyType>
ItemType BinarySearchTree<ItemType, KeyType>::getEntry(const KeyType& anEntry) const throw(NotFoundException)
{
	BinaryNode<ItemType>* finder = findNode(rootPtr, anEntry);
	if(finder == nullptr)
	{
		throw NotFoundException("Entry not in BST!\n");
	}
	else
	{
		return(finder->getItem());
	}
}


template<typename ItemType, typename KeyType>
BinaryNode<ItemType>* BinarySearchTree<ItemType, KeyType>::findNode(BinaryNode<ItemType>* subTreePtr, const KeyType& target) const
{
	if(subTreePtr==nullptr)
	{
		return(nullptr);
	}
	else if(subTreePtr->getItem().getAPname() == target)
	{
		cout	<<subTreePtr->getItem().getAPname()<<"->"   //APname()
			<<subTreePtr->getItem().getPokeid()<<","   //getPokeid()
			<<subTreePtr->getItem().getJPname()<<"\n"; //JPname()
		return(subTreePtr);
	}
	else if(subTreePtr->getItem().getAPname() > target)
	{
		return(findNode(subTreePtr->getLeftChildPtr(), target) );
	}
	else
	{
		return(findNode(subTreePtr->getRightChildPtr(), target) );
	}
}


	template<typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::add(const ItemType& newData) throw(NotFoundException)
{
	if(search(newData.getAPname()))
	{
		throw(NotFoundException("Error: BST contains entry.\n"));
	}
	else
	{
		BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newData);
		numNode++;
		rootPtr = recAdd(rootPtr, newNodePtr);
	}
}

	template<typename ItemType, typename KeyType>
BinaryNode<ItemType>* BinarySearchTree<ItemType, KeyType>::recAdd(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNodePtr)
{
	if(subTreePtr == nullptr)
	{
		return(newNodePtr);
	}
	else if( newNodePtr->getItem() < subTreePtr->getItem() )
	{
		BinaryNode<ItemType>* tempPtr = recAdd(subTreePtr->getLeftChildPtr(), newNodePtr);
		subTreePtr->setLeftChildPtr(tempPtr);
	}
	else
	{
		BinaryNode<ItemType>* tempPtr = recAdd(subTreePtr->getRightChildPtr(), newNodePtr);
		subTreePtr->setRightChildPtr(tempPtr);
	}
	return(subTreePtr);
}


template<typename ItemType, typename KeyType>
BinaryNode<ItemType>* BinarySearchTree<ItemType, KeyType>::copyTree(const BinaryNode<ItemType>* copytreePtr) const
{
	BinaryNode<ItemType>* newtreePtr = nullptr;
	if(copytreePtr != nullptr)
	{
		newtreePtr = new BinaryNode<ItemType>(copytreePtr->getItem() );
		newtreePtr->setLeftChildPtr(copyTree(copytreePtr->getLeftChildPtr() ));
		newtreePtr->setRightChildPtr(copyTree(copytreePtr->getRightChildPtr() ));
	}

	return(newtreePtr);
}//End copyTree


	template<typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::copy(BinarySearchTree<ItemType, KeyType>* copytreePtr)
{
	this->destroyTree(rootPtr);
	rootPtr=copyTree(copytreePtr->rootPtr);
}

	template<typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::destroyTree(BinaryNode<ItemType>* subTreePtr)
{

	if(subTreePtr == nullptr)
	{
		return;
	}

	if(subTreePtr->isLeaf() )
	{
		delete subTreePtr;
		return;
	}

	destroyTree(subTreePtr->getLeftChildPtr() );
	destroyTree(subTreePtr->getRightChildPtr() );
	delete subTreePtr;
}

	template<typename ItemType, typename KeyType>
BinarySearchTree<ItemType, KeyType>::BinarySearchTree(const BinarySearchTree<ItemType, KeyType>& treePtr)
{
	rootPtr = copyTree(treePtr.rootPtr);
}


	template<typename ItemType, typename KeyType>
int BinarySearchTree<ItemType, KeyType>::getnumNode()
{
	return(numNode);
}

	template<typename ItemType, typename KeyType>
BinarySearchTree<ItemType, KeyType>::BinarySearchTree() : rootPtr(nullptr), numNode(0)
{

}

	template<typename ItemType, typename KeyType>
BinarySearchTree<ItemType, KeyType>::~BinarySearchTree()
{
	destroyTree(rootPtr);
	//std::cout<<"Tree destroyed.\n";
}


	template<typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::remove(const KeyType& target) throw(NotFoundException)
{
	bool success = false;
	rootPtr = removeValue(rootPtr, target, success);
	if(success == false)
	{
		throw NotFoundException("Error: Item cannot be removed.\n");
	}
}

	template<typename ItemType, typename KeyType>
BinaryNode<ItemType>* BinarySearchTree<ItemType, KeyType>::removeValue(BinaryNode<ItemType>* subTreePtr, const KeyType target, bool& success)
{
	if(subTreePtr == nullptr)
	{
		success = false;
		return(nullptr);
	}
	else if(subTreePtr->getItem().getAPname() == target)
	{	//Item is in the root of some subtree
		subTreePtr = removeNode(subTreePtr); //Remove the item
		success = true;
		return(subTreePtr);
	}
	else if(subTreePtr->getItem().getAPname() > target)
	{	//Search the left subtree
		BinaryNode<ItemType>* tempPtr = removeValue(subTreePtr->getLeftChildPtr(), target, success);
		subTreePtr->setLeftChildPtr(tempPtr);
		return(subTreePtr);
	}
	else
	{
		BinaryNode<ItemType>* tempPtr = removeValue(subTreePtr->getRightChildPtr(), target, success);
		subTreePtr->setRightChildPtr(tempPtr);
		return(subTreePtr);
	}
}


	template<typename ItemType, typename KeyType>
BinaryNode<ItemType>* BinarySearchTree<ItemType, KeyType>::removeNode(BinaryNode<ItemType>* nodePtr)
{
	if(nodePtr->isLeaf() )
	{//Remove leaf from the tree
		delete nodePtr;
		nodePtr = nullptr;
		return(nodePtr);
	}
	else if( (nodePtr->getLeftChildPtr() == nullptr && nodePtr->getRightChildPtr() != nullptr) || (nodePtr->getLeftChildPtr() != nullptr && nodePtr->getRightChildPtr() == nullptr) ) //Only one child case
	{
		BinaryNode<ItemType>* nodeToConnectPtr;
		if(nodePtr->getLeftChildPtr() != nullptr)
		{
			nodeToConnectPtr = nodePtr->getLeftChildPtr();
		}
		else
		{
			nodeToConnectPtr = nodePtr->getRightChildPtr();
		}
		delete nodePtr;
		nodePtr = nullptr;
		return(nodeToConnectPtr);
	}
	else //Two children case
	{
		ItemType newNodeValue;
		BinaryNode<ItemType>* tempPtr = removeLeftmostNode(nodePtr->getRightChildPtr(), newNodeValue);
		nodePtr->setRightChildPtr(tempPtr);
		nodePtr->setItem(newNodeValue); //Put replacement value in node N
		return(nodePtr);
	}
}


	template<typename ItemType, typename KeyType>
BinaryNode<ItemType>* BinarySearchTree<ItemType, KeyType>::removeLeftmostNode(BinaryNode<ItemType>* nodePtr, ItemType& successor)
{
	if(nodePtr->getLeftChildPtr() == nullptr)
	{ //This is desired node; note that it may have right subtree
		successor = nodePtr->getItem();
		return(removeNode(nodePtr));
	}
	else
	{
		nodePtr->setLeftChildPtr(removeLeftmostNode(nodePtr->getLeftChildPtr(), successor));
		return(nodePtr);
	}
}
