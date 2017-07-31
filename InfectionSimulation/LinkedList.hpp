/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  LinkedList.hpp
 *  * Author: Danny Tran
 *  * Description: LinkedList implementation file
 *  * Date: 10 Feb 2017
 *  *
 *  ---------------------------------------------------------------------------- */


/***
 * Node Class Methods - Reference for writing LinkedList Methods
 *
 * 	Node(T Value);
 * 	void setValue(T value);
 * 	T getValue() const;
 * 	Node<T>* getNext() const;
 * 	void setNext(Node<T>* nextNodePtr);
 *
 ***/

template<typename T>
LinkedList<T>::LinkedList()
{
	m_front=nullptr;
	m_length=0;
}

	template<typename T>
LinkedList<T>::~LinkedList()
{
	Node<T>* deleteptr = m_front;

	while(m_front != nullptr)
	{
		m_front = m_front->getNext();
		delete deleteptr;
		deleteptr = m_front;
	}
}

template<typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_front == nullptr);
}

template<typename T>
int LinkedList<T>::getLength() const
{
	return(m_length);
}

template<typename T>
int LinkedList<T>::positionOf(T value) const
{
	//if m_front being null case Note: to prevent segmentation faults!!
	if(m_front == nullptr)
	{
		return(0);
	}

	else
	{
		Node<T>* jumper = m_front;

		int position = 1;
		while( !(jumper->getValue() == value) && (position <= m_length) ) //something wrong here gdb says so. (Keep this note here as reminder)
		{                                                              //-->Corrected! was the case of seg fault from null!
			jumper = jumper->getNext();
			position++;

			if(jumper->getNext()==nullptr) //Protective clause for finding value not in list and transversing beyond null
			{
				return(0);
			}

		}

		if( position > m_length)
		{
			return(0);
		}

		else
		{
			return(position);
		}

	}

}

template<typename T>
void LinkedList<T>::addBack(T value)
{
	if(!m_front) //Essentially null
	{
		m_front= new Node<T>(value);
	}
	else
	{
		Node<T>* jumper = m_front;

		while( jumper->getNext() != nullptr)
		{
			jumper = jumper-> getNext();
		}


		//Node<T>* temp = new Node<T>(value);   //This didn't work
		//temp->setNext(jumper);

		jumper->setNext( new Node<T>(value) ); //This worked
	}

	m_length++;
}

template<typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = new Node<T>(value);
	if(m_length==0)
	{
		m_front = temp;
	}
	else
	{
		temp->setNext(m_front);
		m_front=temp;
	}

	m_length++;
}

template<typename T>
bool LinkedList<T>::insert(int position, T value)
{
	if( position < 1 || position > m_length )
	{
		return(false);
	}
	if( position == 1)
	{
		addFront(value);

		return(true);
	}
	else
	{
		Node<T>* insertposptr = m_front;
		for(int i=1; i<position; i++)
		{
			insertposptr = insertposptr->getNext(); //Set ptr at insert site
		}

		Node<T>* reconnectptr = m_front;
		for(int i=1; i<position-1; i++)
		{
			reconnectptr = reconnectptr->getNext(); //Set ptr one before insert site
		}

		Node<T>* insertnodeptr = new Node<T>(value);

		insertnodeptr->setNext(insertposptr);

		reconnectptr->setNext(insertnodeptr);

		m_length++;
		return(true);
	}
}

template<typename T>
bool LinkedList<T>::removeBack()
{
	if( isEmpty() )
	{
		return(false);
	}
	else if(m_length == 1)
	{
		Node<T>* temp = m_front;

		m_front=m_front->getNext();

		delete temp;

		m_length--;

		return(true);
	}
	else
	{
		Node<T>* backptr = m_front;
		for(int i=1; i<m_length; i++)
		{
			backptr=backptr->getNext();
		}

		Node<T>* reconnectptr = m_front;
		for(int i=1; i<m_length-1; i++)
		{
			reconnectptr = reconnectptr->getNext();
		}


		reconnectptr->setNext(backptr->getNext() );
		delete backptr;
		m_length--;

		return(true);
	}
}

template<typename T>
bool LinkedList<T>::removeFront()
{
	if( isEmpty() )
	{
		return(false);
	}
	else
	{
		Node<T>* deleteptr = m_front;
		m_front = m_front->getNext();
		delete deleteptr;
		m_length--;
		return(true);
	}
}

template<typename T>
bool LinkedList<T>::removeAt(int position)
{
	if ( isEmpty() || position < 1 || position > m_length )
	{
		return(false);
	}
	else if ( position == 1)
	{
		removeFront();  //temp removed ->
		return(true);
	}
	else
	{
		Node<T>* removeptr = m_front;
		for(int i=1; i<position; i++)
		{
			removeptr = removeptr->getNext();
		}

		Node<T>* reconnectptr = m_front;
		for(int i=1; i<position-1; i++)
		{
			reconnectptr = reconnectptr->getNext();
		}

		reconnectptr->setNext( removeptr->getNext() );
		delete removeptr;
		m_length--;
		return(true);
	}
}

template<typename T>
void LinkedList<T>::setEntry(int position, T value)
{
	Node<T>* jumper = m_front;
	for(int i=1; i<position; i++)
	{
		jumper = jumper->getNext();
	}

	jumper->setValue(value);
}


template<typename T>
T& LinkedList<T>::getEntry( int position ) const
{
	Node<T>* jumper = m_front;
	for(int i=1; i<position; i++)
	{
		jumper = jumper->getNext();
	}

	return( jumper->getValue() );

}
