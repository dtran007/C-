/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  main.cpp
 *  * Author: Danny Tran
 *  * Description:  Main.cpp file
 *  * Date: Mar 17, 2017
 *  *
 *  ---------------------------------------------------------------------------- */
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include "Sort.h"
#include "SortTimer.h"

using std::ofstream;
using namespace std;

std::ostream& bold_on(std::ostream& os)
{
	return os << "\e[1m";
}

std::ostream& bold_off(std::ostream& os)
{
	return os << "\e[0m";
}

void menu();

int main(int argc, char* argv[])
{
	if(argc != 6)
	{
		cout<< bold_on <<"\nError: Incorrect number of parameters.\n" << bold_off;

		menu();
		exit(0);
	}
	else
	{
		try
		{

			string in_string = (argv[1]); //Sort Input Type
			int lower_bound = stoi(argv[2]); //Lower Bound
			int upper_bound = stoi(argv[3]); //Upper Bound
			int increment_size = stoi(argv[4]); //Increment_size
			string output_filename = (argv[5]); //Output filename
			cout<<"Parameters: "
				<<in_string<<" "
				<<lower_bound<<" "
				<<upper_bound<<" "
				<<increment_size<<" "
				<<output_filename<<endl;

			if( in_string != "bubble" && in_string != "selection" && in_string != "insertion" && in_string != "merge" && in_string != "quick" && in_string != "quickWithMedian" )
			{
				menu();
				exit(0);
			}

			ofstream out_stream; //output stream Name
			out_stream.open(output_filename); //open file

			if(out_stream.fail() )
			{
				cout<<"Output file opening failed.";
				exit(1);
			}


			if(in_string == "bubble")
			{
				cout<<"Bubblesort"<<endl;
				out_stream<<"Bubblesort"<<endl;
			}

			if(in_string == "selection")
			{
				cout<<"SelectionSort"<<endl;
				out_stream<<"SelectionSort"<<endl;
			}

			if(in_string == "insertion")
			{
				cout<<"InsertionSort"<<endl;
				out_stream<<"InsertionSort"<<endl;
			}

			if(in_string == "merge")
			{
				cout<<"MergeSort"<<endl;
				out_stream<<"MergeSort"<<endl;
			}

			if(in_string == "quick")
			{
				cout<<"QuickSort"<<endl;
				out_stream<<"QuickSort"<<endl;
			}

			if(in_string == "quickWithMedian")
			{
				cout<<"QuickSortWithMedian"<<endl;
				out_stream<<"QuickSortWithMedian"<<endl;
			}

			for(int i=lower_bound; i<=upper_bound; i=i+increment_size)
			{
				int size =i;

				int* intArray = nullptr;
				intArray = new int[size];

				for(int j=0; j<size; j++)
				{
					intArray[j] = rand();
				}

				SortTimer<int> TimerInstanceRandom;

				//BubbleSort Call
				if(in_string == "bubble") //BubbleSort Call
				{
				//	cout<<size<<","<<TimerInstanceRandom.sortTime(Sort<int>::bubbleSort, intArray, size)<<endl;
					out_stream<<size<<","<<TimerInstanceRandom.sortTime(Sort<int>::bubbleSort, intArray, size)<<endl;
				}

				//SelectionSort Call
				if(in_string == "selection") //SelectionSort Call
				{
				//	cout<<size<<","<<TimerInstanceRandom.sortTime(Sort<int>::selectionSort, intArray, size)<<endl;
					out_stream<<size<<","<<TimerInstanceRandom.sortTime(Sort<int>::selectionSort, intArray, size)<<endl;
				}

				//InsertionSort Call
				if(in_string == "insertion") //InsertionSort Call
				{
				//	cout<<size<<","<<TimerInstanceRandom.sortTime(Sort<int>::insertionSort, intArray, size)<<endl;
					out_stream<<size<<","<<TimerInstanceRandom.sortTime(Sort<int>::insertionSort, intArray, size)<<endl;
				}

				//MergeSort Call
				if(in_string == "merge") //MergeSort Call
				{
				//	cout<<size<<","<<TimerInstanceRandom.sortTime(Sort<int>::mergeSort, intArray, size)<<endl;
					out_stream<<size<<","<<TimerInstanceRandom.sortTime(Sort<int>::mergeSort, intArray, size)<<endl;
				}

				//QuickSort Call
				if(in_string == "quick") //QuickSort Call
				{
				//	cout<<size<<","<<TimerInstanceRandom.sortTime(Sort<int>::quickSort, intArray, size)<<endl;
					out_stream<<size<<","<<TimerInstanceRandom.sortTime(Sort<int>::quickSort, intArray, size)<<endl;
				}

				//QuickSortWithMedian Call
				if(in_string == "quickWithMedian") //QuickSortWithMedian Call
				{
				//	cout<<size<<","<<TimerInstanceRandom.sortTime(Sort<int>::quickSortWithMedian, intArray, size)<<endl;
					out_stream<<size<<","<<TimerInstanceRandom.sortTime(Sort<int>::quickSortWithMedian, intArray, size)<<endl;
				}

				/**** Uncomment to see array printed in commandline	*Note it is sorted, does work
				  for(int i=0; i<size; i++)
				  {
				  cout<<intArray[i]<<",";
				  }
				  cout<<endl;
				 // */

				delete [] intArray;
			}

			out_stream.close(); // close file
			cout<<"File: "<< output_filename <<" has been exported.\n";
		}

		catch(std::invalid_argument e)
		{
			cout<< bold_on <<"\nError: bad input arguments."<< bold_off <<endl;
			menu();
		}
	}

	return(0);
}

void menu()
{
	cout<<"\nPlease enter parameters in the following format:"<<endl;
	cout<<"$>./SortCompare SortType LowerBound UpperBound Incremention OutputfileName\n"<<endl;

	cout<< bold_on << "Example:" << bold_off <<endl;
	cout<<"$>./SortCompare bubble 100 1000 50 bubbleTime.txt\n"<<endl;

	cout<< bold_on << "SortType" << bold_off <<endl;
	cout<<"Options:"<<endl;
	cout<<"		bubble"<<endl;
	cout<<"		selection"<<endl;
	cout<<"		insertion"<<endl;
	cout<<"		merge"<<endl;
	cout<<"		quick"<<endl;
	cout<<"		quickWithMedian"<<endl<<endl;
}
