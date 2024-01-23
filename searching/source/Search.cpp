#include "Search.h"
#include<random>
#include<iostream>
#include<time.h>


Search::Search(int size)
{
	this->size = size;

	data = new int[size];
	
}

Search::~Search()
{
	delete[] data;
}

bool Search::SequentialSearch(int target)
{
	for (int i = 0; i < size; i++)
	{
		if (target == data[i])
		{
			return true;
		}
	}
	return false;
}

bool Search::IterativeBinarySearch(int target)
{
	// TDOO...
	int top = size - 1; // - 1
	int mid = size / 2;
	int bottom = 0;

	do
	{
		if (target == data[mid])
		{
			return true;
		}
		else if (target < data[mid])
		{
			top = mid - 1;
			mid = (top + bottom) / 2;
		}
		else
		{
			bottom = mid + 1;
			mid = (top + bottom) / 2;
		}
	} while (bottom <= top);
	//if (bottom <= top)
    return false;
}

bool Search::RecursiveBinarySearch(int target)
{
	int lowIndex = 0;
	int highIndex = size; // -1
	return RecursiveBinarySearchHelper(lowIndex, highIndex, target);
}
bool Search::RecursiveBinarySearchHelper(int lowIndex, int highIndex, int target) const
{
	RecursionCounter rcTmp;	// used for unit testing DO NOT REMOVE
	
	int mid = (lowIndex + highIndex) / 2;

	// base case 1
	if (target == data[mid])
	{
		return true;
	}
	// base case 2
	else if (lowIndex > highIndex)
	{
		return false;
	}
	else if(lowIndex == target || highIndex == target)
	{
	   return true;   
	}
	else if (target < data[mid])
	{
		highIndex = mid - 1; // - 1
		//mid = (highIndex + lowIndex) / 2;
		return RecursiveBinarySearchHelper(lowIndex, highIndex, target);
	}
	else if(target > data[mid])
	{
		lowIndex = mid + 1; // + 1
		//mid = (lowIndex + highIndex) / 2;
		return RecursiveBinarySearchHelper(lowIndex, highIndex, target);
		// you have to return you recursive case because when it comes back up the stack after hitting the base case it will not return true.....
	}
    return false;
}

void Search::InitSortedArray()
{
   
	srand(0);
	data[0] = 0;
	for (int i = 1; i < size; i++)
	{
		data[i] = (data[i - 1] + rand() % 20);
	}
}

// add more code here