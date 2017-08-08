/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  Node.h
 *  * Author: Danny Tran
 *  * Description:  Node.h file for implementing Node class
 *  * Date: 24 Feb 2017
 *  *
 *  ---------------------------------------------------------------------------- */

#ifndef NODE_H
#define NODE_H

template<typename T>
class Node
{
	public:

		/** @pre None.
		 *   @post Default constructor.
		 *   @return None.
		 */
		Node();

		/** @pre None.
		 *   @post Node with value entered is created.
		 *   @return None.
		 */
		Node(T value);

		/** @pre None.
		 *   @post Node with value and pointer is created and set.
		 *   @return None.
		 */
		Node(T value, Node<T>* nextNodePtr);

		/** @pre None.
		 *   @post Sets Value of Node
		 *   @return None.
		 */
		void setValue(T value);

		/** @pre None.
		 *   @post None.
		 *   @return value of Node
		 */
		T getValue() const;

		/** @pre None.
		 *   @post None.
		 *   @return pointer to Next Node.
		 */
		Node<T>* getNext() const;

		/** @pre None.
		 *   @post Pointer to next Node.
		 *   @return None.
		 */
		void setNext(Node<T>* nextNodePtr);


	private:
		/** @pre None.
		 *   @post Templated Type Value for Node
		 *   @return None.
		 */
		T m_value;

		/** @pre None.
		 *   @post Node pointer to Next Node
		 *   @return None.
		 */
		Node<T>* m_next;

};

#include "Node.hpp"
#endif
