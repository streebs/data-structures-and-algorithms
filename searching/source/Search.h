
#ifndef __SEARCH__
#define __SEARCH__
#include "RecursionCounter.h"

class Search
{
public:
	//Constructor(int size) // initializes a Search Object with an internal integer array of the specified size
	int* data;
	int size;


	Search(int size);
	~Search();

	bool SequentialSearch(int target); // returns true if target is found in the object's data array

	bool IterativeBinarySearch(int target); // returns true if target is found in the object's data array
	
	bool RecursiveBinarySearch(int target); // returns true if target is found in the object's data array (recursive)

	void InitSortedArray();

	int* GetDataArray() { return data; }; // returns a pointer to the array of integers


private:
	
	bool RecursiveBinarySearchHelper(int lowIndex, int highIndex, int target) const;
};


#endif