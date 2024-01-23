/********************************************************************************************
**	Project: Sort
**  Programmer: Sheldon Strebe
**  Course:		cs2420
**	Data:		Sept 12, 2019
**
**	I certify that I wrote all code in this project except that which was
**	provided by the instructor.
**
***********************************************************************************************/

#include <iostream>
#include "Sort.h"
#include "Timer.h"

using namespace std;

// used for Unit Testing. DO NOT REMOVE
int RecursionCounter::currentDepth = 0;
int RecursionCounter::maxDepth = 0;

int main()
{
	Timer T;
	Sort list(100000);
	list.InitArray();

	/*for (int i = 0; i < 10; i++)
	{
		cout << list.GetDataArray()[i] << ", ";
	}*/

	//cout << "\n\n\n\n";
	
   cout << "starting SelectionSort" << endl;
	T.Start();
	list.SelectionSort();
	T.End();

	cout << "Selection Sort duration: " << T.DurationInMilliSeconds() << "ms." << endl;
   
   cout << "starting InsertionSort" << endl;

	T.Start();
	list.InsertionSort();
	T.End();

	cout << "Insertion Sort Duration: " << T.DurationInMilliSeconds() << "ms." << endl;
	
	cout << "starting MergeSort" << endl;

	T.Start();
	list.MergeSort();
	T.End();

	cout << "Merge Sort duration: " << T.DurationInMilliSeconds() << "ms." << endl;
	
	cout << "starting QuickSort" << endl;

	T.Start();
	list.QuickSort();
	T.End();

	cout << "Quick Sort duration: " << T.DurationInMilliSeconds() << "ms." << endl;
	
	cout << "strating std::sort()" << endl;
	
	T.Start();
	list.AlgorithmSort();
	T.End();

	cout << "std::sort() duration of: " << T.DurationInMilliSeconds() << "ms." << endl;

	/*for (int i = 0; i < 10; i++)
	{
		cout << list.GetDataArray()[i] << ", ";
	}*/


	return 0;
}