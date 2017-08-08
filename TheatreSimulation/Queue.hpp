/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  Queue.hpp
 *  * Author: Danny Tran
 *  * Description: Queue Templated Implementation File
 *  * Date: 24 Feb 2017
 *  *
 *  ---------------------------------------------------------------------------- */

template<typename T>
Queue<T>::Queue()
{
	m_front=nullptr;
	m_back=nullptr;
	m_length=0;
}


template<typename T>
Queue<T>::~Queue()
{
	while(!isEmpty() )
	{
		dequeue();
	}
}


template<typename T>
bool Queue<T>::isEmpty() const
{
	return(m_front==nullptr);
}

template<typename T>
void Queue<T>::enqueue(const T value) throw(PreconditionViolationException)
{
	bool nodeAdd = false;

	Node<T>* tempNode = new Node<T>(value);
	if(m_length==0)
	{
		m_front = tempNode;
		m_back = tempNode;
		m_length++;
		nodeAdd = true;
	}
	else
	{
		m_back->setNext(tempNode);
		m_back = m_back->getNext();
		m_length++;
		nodeAdd = true;
	}

	if(nodeAdd==false)
	{
		throw(PreconditionViolationException("Enqueue Error: Could not add to Queue."));
	}
}

template<typename T>
void Queue<T>::dequeue() throw(PreconditionViolationException)
{
	if(m_front == nullptr) //isEmpty()
	{
		throw(PreconditionViolationException("Dequeue Error: Queue is Empty."));
	}
	else
	{
		Node<T>* deletePtr = m_front;
		m_front = m_front->getNext();
		delete deletePtr;
		m_length--;
	}
}

template<typename T>
T Queue<T>::peekFront() const throw(PreconditionViolationException)
{
	if(m_front == nullptr)
	{
		throw(PreconditionViolationException("Peek Error: Queue is Empty."));
	}
	else
	{
		return(m_front->getValue());
	}
}

template<typename T> //Only for Testing During Debug --> will not used in implementation
T Queue<T>::peekBack() const throw(PreconditionViolationException)
{
	if(m_front == nullptr)
	{
		throw(PreconditionViolationException("Peek Error: Queue is Empty."));
	}
	else
	{
		return(m_back->getValue());
	}
}
