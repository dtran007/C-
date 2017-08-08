/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  Stack.cpp
 *  * Author: Danny Tran
 *  * Description: Stack Templated Implementation File
 *  * Date: 24 Feb 2017
 *  *
 *  ---------------------------------------------------------------------------- */
//Start your program.
template<typename T>
Stack<T>::Stack() : topPtr(nullptr)
{

}//end default constructor


template <typename T>
Stack<T>::~Stack()
{
	//Pop until stack is empty
	while(!isEmpty() )
	{
		pop();
	}
}//End Destructor

template <typename T>
bool Stack<T>::isEmpty() const
{
	return(topPtr==nullptr);
}//End isEmpty

template <typename T>
void Stack<T>::push(const T value) throw(PreconditionViolationException)
{
	if(m_size >= 10) //Setting Size of Stack
	{
		throw(PreconditionViolationException("Error: Stack is Full."));
	}
	else
	{
	Node<T>* newNodePtr = new Node<T>(value, topPtr);
	topPtr = newNodePtr;
	newNodePtr = nullptr;
	m_size++;
	}
}//End push


template <typename T>
void Stack<T>::pop() throw(PreconditionViolationException)
{
	if(isEmpty() ) //if empty throw error
	{
		throw(PreconditionViolationException("Error in Stack Pop. Empty Stack."));
	}
	else
	{//Stack is not empty delete top
		Node<T>* nodeToDeletePtr = topPtr;
		topPtr = topPtr->getNext();

		//Return deleted node to system
		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
		nodeToDeletePtr = nullptr;
		m_size--;
	}//end if


}//end pop

template <typename T>
T Stack<T>::peek() const throw(PreconditionViolationException)
{
	if(isEmpty() )
	{
		throw(PreconditionViolationException("Error: Peek attempted on Empty Stack."));
	}
	else
	{
		return(topPtr->getValue() );
	}


}//end peek / get top value


template<typename T>
int Stack<T>::getLength() const
{
	return(m_size);
}//End getLength
