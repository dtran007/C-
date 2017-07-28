/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  Node.h
 *  * Author: Danny Tran
 *  * Description:  Node.h file for implementing Node class
 *  * Date: 03 Feb 2017
 *  *
 *  ---------------------------------------------------------------------------- */

#ifndef NODE_H
#define NODE_H

template<typename T>
class Node
{
	public:
		Node(T value);
		void setValue(T value);
		T& getValue(); //const was removed
		Node<T>* getNext() const;
		void setNext(Node<T>* nextNodePtr);


	private:
		T m_value;
		Node<T>* m_next;

};

#include "Node.hpp"
#endif
