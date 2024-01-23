/********************************************************************************************
**	Project: Search Project
**  Programmer: Sheldon Strebe
**  Course:		cs2420
**	Data:		Sept 6, 2019
**
**	I certify that I wrote all code in this project except that which was
**	provided by the instructor.
**
***********************************************************************************************/

#include <iostream>
#include <random>
#include "Timer.h"
#include "Search.h"

using namespace std;

// used for Recursion Unit Testing. DO NOT REMOVE
int RecursionCounter::currentDepth = 0;
int RecursionCounter::maxDepth = 0;

// add code here

int main()
{
	Timer T;
	
	// this will populate ourt search obj with random numbers according to the size specified. (sorted
	
	cout << "Creating an Array of 10000000" << endl;

	Search driver(10000000);
	driver.InitSortedArray();

	cout << "Finished Creating a sorted array of 10000000" << endl << endl;

	int beginning;
	int middle;
	int last;

	beginning = driver.data[0];
	middle = driver.data[driver.size / 2];
	last = driver.data[driver.size - 1];


	// for (int i = 0; i < driver.size; i++)
	// {
	// 	cout << driver.data[i] << ", ";
	// }
	//driver.SequentialSearch(end);
	
	T.Start();
	driver.SequentialSearch(beginning);
	T.End();
	cout << "sequential search(beginning): " << T.DurationInNanoSeconds() << "ns" << endl;

	T.Start();
	driver.IterativeBinarySearch(beginning);
	T.End();
	cout << "iterative binary search(beginning): " << T.DurationInNanoSeconds() << "ns" << endl;

	T.Start();
	driver.RecursiveBinarySearch(beginning);
	T.End();
	cout << "recursive binary search(beginning): " << T.DurationInNanoSeconds() << "ns" << endl;

    cout << "--------------------------------------------" << endl;

	T.Start();
	driver.SequentialSearch(middle);
	T.End();
	cout << "sequential search(middle): " << T.DurationInNanoSeconds() << "ns" << endl;

	T.Start();
	driver.IterativeBinarySearch(middle);
	T.End();
	cout << "iterative binary search(middle): " << T.DurationInNanoSeconds() << "ns" << endl;

	T.Start();
	driver.RecursiveBinarySearch(middle);
	T.End();
	cout << "recursive binary search(middle): " << T.DurationInNanoSeconds() << "ns" << endl;

    cout << "--------------------------------------------" << endl;

	T.Start();
	driver.SequentialSearch(last);
	T.End();
	cout << "sequential search(end): " << T.DurationInNanoSeconds() << "ns" << endl;

	T.Start();
	driver.IterativeBinarySearch(last);
	T.End();
	cout << "iterative binary search(end): " << T.DurationInNanoSeconds() << "ns" << endl;

	T.Start();
	driver.RecursiveBinarySearch(last);
	T.End();
	cout << "recursive binary search(end): " << T.DurationInNanoSeconds() << "ns" << endl;

    cout << "--------------------------------------------" << endl;

	T.Start();
	driver.SequentialSearch(-1);
	T.End();
	cout << "sequential search(not in array): " << T.DurationInNanoSeconds() << "ns" << endl;

	T.Start();
	driver.IterativeBinarySearch(-1);
	T.End();
	cout << "iterative binary search(not in array): " << T.DurationInNanoSeconds() << "ns" << endl;

	T.Start();
	driver.RecursiveBinarySearch(-1);
	T.End();
	cout << "recursive binary search(not in array): " << T.DurationInNanoSeconds() << "ns" << endl;
	return 0;
}