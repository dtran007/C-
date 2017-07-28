/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  LinkedListTester.cpp
 *  * Author: Danny Tran
 *  * Description:Implementation File for LinkedListTester class
 *  * Date:03 Feb 2017
 *  *
 *  ---------------------------------------------------------------------------- */
#include "LinkedListTester.h"

#include<iostream>

using namespace std;

/** @pre None.
 *   @post Constructor - For instantiation of LinkedListTester
 */
LinkedListTester::LinkedListTester()
{

}


/** @pre None.
 *   @post None. Runs a sweep of tests under one call.
 */
void LinkedListTester::runTest()
{
	//Runs test 01 to 16
	test01();
	test02();
	test03();
	test04();
	test05();
	test06();
	test07();
	test08();
	test09();
	test10();
	test11();
	test12();
	test13();
	test14();
	test15();
	test16();

	//Every new needs to have a delete
}


/**
 * @brief: Test size of empty list is zero
 **/
void LinkedListTester::test01()
{
	LinkedList<int>* myLinkedList = new LinkedList<int>();

	if( myLinkedList->isEmpty() )
	{
		cout<<"Test#01: size of empty list is zero: ~PASSED"<<endl;
	}
	else
	{
		cout<<"Test#01: size of empty list is zero: ~FAILED"<<endl;
	}
	delete myLinkedList;
}



/**
 * @brief: Test size returns correct value after 1 addFront
 **/
void LinkedListTester::test02()
{
	LinkedList<int>* myLinkedList = new LinkedList<int>();

	myLinkedList->addFront(1);

	if( (myLinkedList->getLength()) == 1)
	{
		cout<<"Test#02: size returns correct value after 1 addFront: ~PASSED"<<endl;
	}
	else
	{
		cout<<"Test#02: size returns correct value after 1 addFront: ~FAILED"<<endl;
	}
	delete myLinkedList;
}



/**
 * @brief: Test size returns correct value after 1 addBack
 **/
void LinkedListTester::test03()
{
	LinkedList<int>* myLinkedList = new LinkedList<int>();

	myLinkedList->addBack(1);

	if( (myLinkedList->getLength() ) == 1)
	{
		cout<<"Test#03: size returns correct value after 1 addBack: ~PASSED"<<endl;
	}
	else
	{
		cout<<"Test:03: size returns correct value after 1 addBack: ~FAILED"<<endl;
	}
	delete myLinkedList;
}


/**
 * @brief: Test size returns correct value after multiple addFront
 **/
void LinkedListTester::test04()
{
	LinkedList<int>* myLinkedList = new LinkedList<int>();

	myLinkedList->addFront(7);
	myLinkedList->addFront(3);
	myLinkedList->addFront(3);
	myLinkedList->addFront(1);

	if( (myLinkedList->getLength() ) == 4)
	{
		cout<<"Test#04: size returns correct value after multiple addFront: ~PASSED"<<endl;
	}
	else
	{
		cout<<"Test#04: size returns correct value after multiple addFront: ~FAILED"<<endl;
	}
	delete myLinkedList;
}


/**
 * @brief: Test size returns correct value after multiple addBack
 **/
void LinkedListTester::test05()
{
	LinkedList<int>* myLinkedList = new LinkedList<int>();

	myLinkedList->addBack(1);
	myLinkedList->addBack(10);
	myLinkedList->addBack(100);
	myLinkedList->addBack(1000);

	if( (myLinkedList->getLength() ) == 4)
	{
		cout<<"Test#05: size returns correct value after multiple addBack: ~PASSED"<<endl;
	}
	else
	{
		cout<<"Test#05: size returns correct value after multiple addBack: ~FAILED"<<endl;
	}
	delete myLinkedList;
}


/**
 * @brief: Test size returns correct value after adds and removeFront
 **/
void LinkedListTester::test06()
{
	LinkedList<int>* myLinkedList = new LinkedList<int>();
	int testnum=5;
	for(int i=0; i<testnum; i++)  //Loop to add
	{
		myLinkedList->addFront(i);
		myLinkedList->addBack(i);
	}

	for(int i=0; i<(2*testnum); i++) //Loop to delete
	{
		myLinkedList->removeFront();
	}

	if( (myLinkedList->getLength() ) == 0)
	{
		cout<<"Test#06: size returns correct value after adds and removeFront: ~PASSED"<<endl;
	}
	else
	{
		cout<<"Test#06: size returns correct value after adds and removeFront: ~FAILED"<<endl;
	}
	delete myLinkedList;
}


/**
 * @brief: Test size returns correct value after adds and removeBack
 **/
void LinkedListTester::test07()
{
	LinkedList<int>* myLinkedList = new LinkedList<int>();
	int testnum=5;
	for(int i=0; i<testnum; i++)  //Loop to add
	{
		myLinkedList->addFront(i);
		myLinkedList->addBack(i);
	}

	for(int i=0; i<(2*testnum); i++) //Loop to delete
	{
		myLinkedList->removeBack();
	}

	if( (myLinkedList->getLength() ) == 0)
	{
		cout<<"Test#07: size returns correct value after adds and removeBack: ~PASSED"<<endl;
	}
	else
	{
		cout<<"Test#07: size returns correct value after adds and removeBack: ~FAILED"<<endl;
	}
	delete myLinkedList;
}


/**
 * @brief: Test size reduced by 1 removeFront on populated list
 **/
void LinkedListTester::test08()
{
	LinkedList<int>* myLinkedList = new LinkedList<int>();
	int testnum=5;
	for(int i=0; i<testnum; i++)  //Loop to add
	{
		myLinkedList->addFront(i);
		myLinkedList->addBack(i);
	}

	myLinkedList->removeFront();//1 removeFront

	if( (myLinkedList->getLength() ) == ((2*testnum)-1))
	{
		cout<<"Test#08: size reduced by 1 removeFront on populated list: ~PASSED"<<endl;
	}
	else
	{
		cout<<"Test#08: size reduced by 1 removeFront on populated list: ~FAILED"<<endl;
	}
	delete myLinkedList;
}


/**
 * @brief: Test size reduced by 1 removeBack on populated list
 **/
void LinkedListTester::test09()
{
	LinkedList<int>* myLinkedList = new LinkedList<int>();
	int testnum=5;
	for(int i=0; i<testnum; i++)  //Loop to add
	{
		myLinkedList->addFront(i);
		myLinkedList->addBack(i);
	}

	myLinkedList->removeBack();//1 removeBack

	if( (myLinkedList->getLength() ) == ((2*testnum)-1))
	{
		cout<<"Test#09: size reduced by 1 removeBack on populated list: ~PASSED"<<endl;
	}
	else
	{
		cout<<"Test#09: size reduced by 1 removeBack on populated list: ~FAILED"<<endl;
	}
	delete myLinkedList;
}


/**
 * @brief: Test positionOf returns 0 on empty list
 **/
void LinkedListTester::test10()
{
	int testvalue=5;

	LinkedList<int>* myLinkedList = new LinkedList<int>();
	//cout << "0" << '\n';
	//cout<<myLinkedList->positionOf(testvalue)<<" testing"<<endl;   //Testing gdb! fixed issue
	//cout << "1" << '\n';
	if( (myLinkedList->positionOf(testvalue)) == 0)
	{
		cout<<"Test#10: positionOf returns 0 on empty list: ~PASSED"<<endl;
	}
	else
	{
		cout<<"Test#10: positionOf returns 0 on empty list: ~FAILED"<<endl;
	}
	delete myLinkedList;
}


/**
 * @brief:Test positionOf returns 0 when value not in list
 **/
void LinkedListTester::test11()
{
	int testvalue=777;   //Value to test (Note value not in the LinkedList)

	LinkedList<int>* myLinkedList = new LinkedList<int>();

	for(int i=1; i<10; i++)  //Only populate list of 1 to 9
	{
		myLinkedList->addBack(i);
	}

	if( (myLinkedList->positionOf(testvalue)) == 0) //Suppose to return 0 if not in list
	{
		cout<<"Test#11: positionOf returns 0 when value not in list: ~PASSED"<<endl;
	}
	else
	{
		cout<<"Test#11: positionOf returns 0 when value not in list: ~FAILED"<<endl;
	}
	delete myLinkedList;
}


/**
 * @brief: Test positionOf returns true if value is in populated list
 **/
void LinkedListTester::test12()
{
	int testvalue=5; //Value to test (Note value is in the LinkedList)
	//Value is added in the FOR-loop below

	LinkedList<int>* myLinkedList = new LinkedList<int>();

	for(int i=1; i<10; i++)   //Populating LinkedList (5 is in ths range)
	{
		myLinkedList->addFront(i); //did addBack in Test11 doing addFront this time;
	}

	if( (myLinkedList->positionOf(testvalue) != 0) ) //Not returning zero for position
	{
		cout<<"Test#12: positionOf returns true if value is in populated list: ~PASSED"<<endl;
	}
	else
	{
		cout<<"Test#12: positionOf returns true if value is in populated list: ~FAILED"<<endl;
	}

	delete myLinkedList;
}

/**
 * @brief: Test removeFront on empty list returns false
 **/
void LinkedListTester::test13()
{

	LinkedList<int>* myLinkedList = new LinkedList<int>(); //Empty LinkedList

	if( (myLinkedList->removeFront() == false) )
	{
		cout<<"Test#13: removeFront on empty list returns false: ~PASSED"<<endl;
	}
	else
	{
		cout<<"Test#13: removeFront on empty list returns false: ~FAILED"<<endl;
	}

	delete myLinkedList;
}


/**
 * @brief: Test removeBack on empty list returns false
 **/
void LinkedListTester::test14()
{
	LinkedList<int>* myLinkedList = new LinkedList<int>(); //Empty LinkedList

	if( (myLinkedList->removeBack() == false) )
	{
		cout<<"Test#14: removeFront on empty list returns false: ~PASSED"<<endl;
	}
	else
	{
		cout<<"Test#14: removeFront on empty list returns false: ~FAILED"<<endl;
	}

	delete myLinkedList;
}


/**
 * @brief: Test insert returns false given an invalid position
 **/
void LinkedListTester::test15()
{

	int insertPos = 20; //outside range of LinkedList to be created below
	int arbitraryVal = 9; //Arbitrary value "to add" also it is not currently in LinkedList

	LinkedList<int>* myLinkedList = new LinkedList<int>();

	for(int i=1; i<6; i++)
	{
		myLinkedList->addBack(i);
	}

	if( (myLinkedList->insert(insertPos, arbitraryVal) == false) )
	{
		cout<<"Test#15: insert returns false given an invalid position: ~PASSED"<<endl;
	}
	else
	{
		cout<<"Test#15 insert returns false given an invalid position: ~FAILED"<<endl;
	}

	delete myLinkedList;
}


/**
 * @brief: Test order preserved by insert on populated list
 **/
void LinkedListTester::test16()
{
	LinkedList<int>* myLinkedList = new LinkedList<int>();

	for(int i=1; i<6; i++)
	{
		myLinkedList->addBack(i);
	}

	//Printing -- test to see what linked list looked prior to add
	/*
	   for(int i=1;i<=myLinkedList->getLength();i++)
	   {

	   cout<<myLinkedList->getEntry(i)<<"->";

	   }
	   cout<<endl;
	   */
	//end Printing
	//format of insert(position, value)

	int addPos = 2;
	int addVal = 9;

	myLinkedList->insert(addPos, addVal);

	//Test if added position is correct along with the added value at the given position is true
	//using getEntry and positionOF
	if( (myLinkedList->getEntry(addPos) == addVal) && (myLinkedList->positionOf(addVal) == addPos) )
	{
		cout<<"Test#16: order preserved by insert on populated list: ~PASSED"<<endl;
	}
	else
	{
		cout<<"Test#16: order preserved by insert on populated list: ~FAILED"<<endl;
	}
	//For a list of 1 to 5..
	//Inserting value of 9 into position 2


	//Printing-- to see what linked list looked like after adding value
	/*
	   for(int i=1;i<=myLinkedList->getLength();i++)
	   {

	   cout<<myLinkedList->getEntry(i)<<"->";

	   }
	   cout<<endl;
	   */

	delete myLinkedList;
}
