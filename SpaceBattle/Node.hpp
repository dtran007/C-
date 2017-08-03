/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  Node.hpp
 *  * Author: Danny Tran
 *  * Description:  Node.hpp implementation file for Node class
 *  * Date: 17 Feb 2017
 *  *
 *  ---------------------------------------------------------------------------- */

template<typename T>
Node<T>::Node(T value)
{
	m_next=nullptr;
	m_value=value;
}

template<typename T>
void Node<T>::setValue(T value)
{
	m_value=value;
}


template<typename T>
T& Node<T>::getValue()
{
	return(m_value);
}



template<typename T>
Node<T>* Node<T>::getNext() const
{
	return m_next;
}


template<typename T>
void Node<T>::setNext(Node<T>* nextNodePtr)
{
	m_next=nextNodePtr;
}
