/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  Executive.cpp
 *  * Author: Danny Tran
 *  * Description:  Executive implementation file
 *  * Date: 31 March 2017
 *  *
 *  ---------------------------------------------------------------------------- */
#include "Executive.h"
ofstream out_stream; //output stream name

void Executive::display(Pokemon& pokemon)
{
	cout<<pokemon.getAPname()<<" "<<pokemon.getPokeid()<<" "<<pokemon.getJPname()<<endl;
}//end display
//method usage: BST->preorderTravere(display) to cout BST with given traversal method

void Executive::write(Pokemon& pokemon)
{
	out_stream<<pokemon.getAPname()<<" "<<pokemon.getPokeid()<<" "<<pokemon.getJPname()<<endl;
} //Same as display except write to ofstream

Executive::Executive(string filename) : copyCreated(0) //Bool to see if copyBST has been generated
{
	ifstream in_stream; //input stream name
	ofstream out_stream; //output stream name

	in_stream.open(filename); //input stream opening file

	if(in_stream.fail() )
	{
		std::cout<<"Fail to open input file.\n";
		exit(1);
	}

	//create Binary Search Tree
	BST = new BinarySearchTree<Pokemon,std::string>();

	if(in_stream.is_open())
	{
		while(!in_stream.eof())
		{
			string temp_ap_name=""; //temp variables
			int temp_pokeid=0;
			string temp_jp_name="";

			getline(in_stream, temp_ap_name, ',');
			in_stream >> temp_pokeid;
			in_stream.ignore(1);
			getline(in_stream, temp_jp_name, '\n');

			if(temp_ap_name=="")
			{
				break;
			}
			string TEMP_AP_NAME=nameFormat(temp_ap_name);
			string TEMP_JP_NAME=nameFormat(temp_jp_name);

			//Visual test what gets cin from file
			//		cout<<"Imported: "<<TEMP_AP_NAME<<" "
			//				<<temp_pokeid<<" "
			//				<<TEMP_JP_NAME<<endl;

			Pokemon t_Pokemon(TEMP_AP_NAME, temp_pokeid, TEMP_JP_NAME);

			BST->add(t_Pokemon);
		}
		//A bunch of tests to test file input/ tree generation
		//	BST->preorderTraverse(display());
		//cout<<"The number of Nodes in Tree: "<<BST->getnumNode()<<endl;
		//	cout<<"Testing display of nodes"<<endl;
		//	BST->inorderTraverse(display);
	}
	in_stream.close();
}

std::string Executive::nameFormat(std::string name) //function to format names similar to infile
{			//Capital first letter, lowercase rest of letters
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


void Executive::menu()
{
	cout<<"\nPokemon Binary Search Tree"<<endl;
	cout<<"Make a selection:"<<endl;
	cout<<"1.)Search"<<endl;
	cout<<"2.)Copy"<<endl;
	cout<<"3.)Add"<<endl;
	cout<<"4.)Remove"<<endl;
	cout<<"5.)Save"<<endl;
	cout<<"6.)Test"<<endl;
	cout<<"7.)Quit"<<endl;
	cout<<"Choice: ";
}


void Executive::run()
{
	int userChoice=0;
	do
	{
		menu();
		cin>>userChoice;

		while(cin.fail() || (userChoice<1) || (userChoice > 7))
		{
			cin.clear(); //unset failbit
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Skip bad input
			cout<<"Sorry retry input"<<endl<<endl;
			menu();
			cin>>userChoice;
			cout<<endl;
		}

		if(userChoice == 1)
		{
			string aname="";
			cout<<"\nSearch: Enter American name -> Return Japanese Name and ID\n";
			cout<<"Enter American name: ";
			cin.ignore(1, '\n');
			getline(cin, aname);
			aname=nameFormat(aname);
			cout<<"Name entered: "<<aname<<endl;
			if(BST->search(aname))
			{
				cout<<"Name in BST!\n";
				//cout<<BST->search(aname)<<endl;
				BST->getEntry(aname);
			}
			else
			{
				cout<<"Name not in BST!\n";
			}
		}//End Choice 1


		if(userChoice ==2)
		{
			if(copyCreated) //Can only run copy of BST once! A checker.
			{
				cout<<"\nDeep copy has already been created!\n";
			}
			else
			{
				cout<<"\nCopy: Create deep copy of BST\n";

				copyBST = new BinarySearchTree<Pokemon, std::string>;
				copyBST->copy(BST);
				copyCreated = true;
				//Testing output of copyBST
				//copyBST->inorderTraverse(display);
				cout<<"\nDeep copy of BST has been created!\n";
				//	copyBST->preorderTraverse(display);
			}
		}//End Choice 2


		if(userChoice ==3)
		{
			if(copyCreated == false)
			{
				cout<<"\nDeep copy of Binary Search Tree has not been created. Please procees first with selection: 2.)Copy\n";
			}
			else if(copyCreated == true)
			{
				string temp_APname="";
				string temp_JPname="";
				int temp_PID;
				cout<<"\nAdd New Pokemon: Please enter info for American name, ID#, and Japanese Name\n";
				cout<<"Enter American name: ";

				cin.ignore(1, '\n');
				getline(cin, temp_APname);
				temp_APname=nameFormat(temp_APname);
				cout<<"Name entered: "<<temp_APname<<endl;

				if( copyBST->search(temp_APname) )
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
					temp_JPname=nameFormat(temp_JPname);
					cout<<"Name entered:"<<temp_JPname<<endl;
					cout<<"New Entry: "<<temp_APname<<" "<<temp_PID<<" "<<temp_JPname<<endl;

					Pokemon t_Pokemon(temp_APname, temp_PID, temp_JPname);
					copyBST->add(t_Pokemon);
					cout<<"\nNode entry added sucessfully!\n";
					//Testing inorder display
					//copyBST->inorderTraverse(display);
				}
			}
		}
		if(userChoice==4)
		{
			if(copyCreated == false)
			{
				cout<<"\nDeep copy of Binary Search Tree has not been created. Please make selection 2.)Copy then proceed:\n";
			}
			else if(copyCreated == true)
			{
				cout<<"\nRemove Entry From Binary Search Tree\n";
				string deleteEntry;

				cout<<"Enter American name to delete: ";

				cin.ignore(1, '\n');
				getline(cin, deleteEntry);
				deleteEntry=nameFormat(deleteEntry);
				cout<<"Name entered: "<<deleteEntry<<endl;
				deleteEntry = nameFormat(deleteEntry);
				try
				{
					copyBST->remove(deleteEntry);
					cout<<deleteEntry<<" has been removed\n";
					//Test if Removal worked
					//copyBST->inorderTraverse(display);
				}
				catch(NotFoundException e)
				{
					cout<< e.what();
				}

			}
		}
		if(userChoice==5)
		{
			if(copyCreated == false)
			{
				cout<<"\nDeep copy of Binary Search Tree has not been created. Please procees first with selection: 2.)Copy\n";
			}
			else if(copyCreated == true)
			{
				cout<<"\nSave Dictionary to File. Enter file name to export.\n";

				string createFile;

				cout<<"\nPlease enter file name to output to: ";
				cin.ignore();
				getline(cin, createFile);

				out_stream.open(createFile); //Open file to create

				if(out_stream.fail())
				{
					cout<<"Output file opening failed.\n";
					exit(1);
				}

				int treeType;
				do
				{
					cin.clear();

					cout<<"Choose dictionary to save: \n"
						<<"1.)Original\n"
						<<"2.)Copy\n"
						<<"Choice: ";
					cin>>treeType;
				}while(cin.fail() || treeType <= 0 || treeType >=3);

				int orderType;
				do
				{
					cin.clear(); //unset failbait

					cout<<"Choose Traversal Order: \n"
						<<"1.) InOrder\n"
						<<"2.) PreOrder\n"
						<<"3.) PostOrder\n"
						<<"Choice: ";

					cin>>orderType;

				}while(cin.fail() || orderType <=0 || orderType >= 4);


				if(orderType==1) //Choosing BST or copyBST to file choices
				{
					if(treeType==1)
					{
						BST->inorderTraverse(write);
					}
					else
					{
						copyBST->inorderTraverse(write);
					}
				}
				else if(orderType==2)
				{
					if(treeType==1)
					{
						BST->preorderTraverse(write);
					}
					else
					{
						copyBST->preorderTraverse(write);
					}
				}
				else if(orderType==3)
				{
					if(treeType==1)
					{
						BST->postorderTraverse(write);
					}
					else
					{
						copyBST->postorderTraverse(write);
					}
				}

				out_stream.close(); //close file
				cout<<"\nFile name created and exported: "<<createFile<<endl;
			}
		}
		if(userChoice==6)
		{

			cout<<"\nTest cases\n";
			TreeTest instance;
			instance.runTest(*(BST)); //Passes BST to TreeTest Class by value
			//The the 3 Test Methods are done via the TreeTest class
		}

	}while(userChoice!=7);

}

Executive::~Executive()
{//Deconstructor
	delete BST;

	if(copyCreated)
	{
		delete copyBST;
	}
}
