/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  TreeTest.cpp
 *  * Author: Danny Tran
 *  * Description: TreeTest Implementation File
 *  * Date: 31 March 2017
 *  *
 *  ---------------------------------------------------------------------------- */

#include "TreeTest.h"

ofstream test_stream; //output of test stream name

TreeTest::TreeTest()
{

}


void TreeTest::runTest(BinarySearchTree<Pokemon, std::string> bst)
{
	int testChoice;

	menu();

	cin>>testChoice;

	while(cin.fail() || (testChoice<1) || (testChoice >3))
	{
		cin.clear(); //unset failbit
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Skip bad input
		cout<<"Sorry retry input"<<endl<<endl;
		menu();
		cin>>testChoice;
		cout<<endl;
	}

	if(testChoice == 1)
	{
		testAdds(bst);
	}
	if(testChoice == 2)
	{
		testRemoves(bst);
	}
	if(testChoice ==3)
	{
		testWriteToFile(bst);
	}
}


void TreeTest::testAdds(BinarySearchTree<Pokemon, std::string> bst)
{

	string temp_APname="";
	string temp_JPname="";
	int temp_PID;
	cout<<"Add New Pokemon: Please enter info for American name, ID#, and Japanese Name\n";
	cout<<"Enter American name: ";

	cin.ignore(1, '\n');
	getline(cin, temp_APname);
	temp_APname=NameFormat(temp_APname);
	cout<<"Name entered: "<<temp_APname<<endl;


	if( bst.search(temp_APname) )
	{
		cout<<"Name is already in Binary Search Tree\n";
	}

	else
	{
		cout<<"Enter ID#: ";
		cin>>temp_PID;

		//Control for proper input loop
		while( cin.fail()  )
		{
			cin.clear(); //unset failbit
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //skip bad input
			cout<<"Please enter a proper numberic ID#: ";
			cin>>temp_PID;

		}

		cout<<"Enter Japanese name: ";
		cin.ignore(1, '\n');
		getline(cin, temp_JPname);
		temp_JPname=NameFormat(temp_JPname);
		cout<<"Name entered:"<<temp_JPname<<endl;
		cout<<"New Entry: "<<temp_APname<<" "<<temp_PID<<" "<<temp_JPname<<endl;

		Pokemon t_Pokemon(temp_APname, temp_PID, temp_JPname);
		bst.add(t_Pokemon);
		cout<<"Node added: :"<<bst.search(temp_APname);
		bst.inorderTraverse(Display);
	}
}


void TreeTest::testRemoves(BinarySearchTree<Pokemon, std::string> bst)
{


	cout<<"\nRemove Entry From Test Binary Search Tree\n";
	string deleteEntry;


	cout<<"Enter American name to delete: ";

	cin.ignore(1, '\n');
	getline(cin, deleteEntry);
	deleteEntry=NameFormat(deleteEntry);
	cout<<"Name entered: "<<deleteEntry<<endl;
	deleteEntry = NameFormat(deleteEntry);
	try
	{
		bst.remove(deleteEntry);
		cout<<deleteEntry<<" has been removed\n"<<endl;
		bst.inorderTraverse(Display);

	}
	catch(NotFoundException e)
	{
		cout<< e.what();
	}
}

void TreeTest::testWriteToFile(BinarySearchTree<Pokemon, std::string> bst)
{

	cout<<"Save Test Dictionary to File. Enter file name to export with inOrder Traversal.\n";

	string createFile;

	cout<<"\nPlease enter file name to output to: ";
	cin.ignore();
	getline(cin, createFile);

	test_stream.open(createFile); //Open file to create

	if(test_stream.fail())
	{
		cout<<"Output file opening failed.\n";
		exit(1);
	}

	bst.inorderTraverse(Write);


	test_stream.close(); //close file
	cout<<"File name created and exported: "<<createFile<<endl;
}


void TreeTest::Display(Pokemon& pokemon)
{
	cout<<pokemon.getAPname()<<" "<<pokemon.getPokeid()<<" "<<pokemon.getJPname()<<endl;
}//end display



void TreeTest::Write(Pokemon& pokemon)
{
	test_stream<<pokemon.getAPname()<<" "<<pokemon.getPokeid()<<" "<<pokemon.getJPname()<<endl;
}//end display

std::string TreeTest::NameFormat(std::string name)
{
	std::locale loc;
	for(std::string::size_type i=0; i<name.length(); i++)
	{
		if( i==0 )
		{
			name[i]=toupper(name[i]);
		}
		else
		{
			name[i]=tolower(name[i]);
		}

	}
	return(name);
}


void TreeTest::menu()
{

	cout<<"~TreeTest Mode~ Please Choose a Following test:\n";
	cout<<"1.) testAdds\n";
	cout<<"2.) testRemoves\n";
	cout<<"3.) testWriteToFile\n";
	cout<<"Choice: ";
}
