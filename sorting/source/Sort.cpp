#include <random>
#include <algorithm>
#include "Sort.h"
#include<iostream>

Sort::Sort(int size)
{
	this->size = size;
	data = new int[size];
}

Sort::~Sort()
{
	delete[] data;
}

void Sort::InitArray()
{
	srand(0);
	for (int i = 0; i < size; i++)
	{
		data[i] = rand(); // % 100
	}
}

void Sort::SelectionSort()  ///// the following will put the list in decending order
{
	int low;
	int tmp;
	for (int i = 0; i < size - 1; i++)
	{
		low = i;
		for (int j = i + 1; j < size; j++)
		{
			if (data[j] < data[low])
			{
				low = j;
			}
		}
		tmp = data[i];
		data[i] = data[low];
		data[low] = tmp;
	}
}

void Sort::InsertionSort()
{
	for (int i = 1; i < size; i++)
	{
		int tmp;
		int j = i;
		if (data[i] < data[i - 1])
		{
			while (data[j] < data[j - 1] && j >= 0)
			{
				tmp = data[j];
				data[j] = data[j - 1];
				data[j - 1] = tmp;
				j--;
			}
		}
	}
}

void Sort::AlgorithmSort()
{
	std::sort(data, data + size);
}

void Sort::MergeSort()
{
	MergeSortRecursionHelper(0, size - 1);
}
void Sort::Merge(int low, int middle, int high)
{
	// create a dynamic array
	// compare left and right array
	//if lefts is less copy and increment left side
	// if right is less copy and increment right side
	// if the left or right is the at the end dump the other side

	//left goes from beginning to middle 
	// right goes from middle + 1 to high
	int* tmp;
	int length = (high - low) + 1;
	tmp = new int[length];

	middle = ((high + low) / 2);
	int left = low;
	int right = middle + 1;
	int tmpIn;
	int cursor = 0;


	for ( int i = left; i < length; i++)
	{
		tmp[i] = data[i];
	}

	while (left <= middle && right <= high)
	{
		if (data[left] <= data[right])
		{
			tmp[cursor] = data[left];
			left++;
		}
		else
		{
			tmp[cursor] = data[right];
			right++;
		}
		cursor++;
	}
	while (left <= middle)
	{
		tmp[cursor] = data[left];
		cursor++;
		left++;
	}
	while (right <= high)
	{
		tmp[cursor] = data[right];
		cursor++;
		right++;
	}

	for (int cursor = 0; cursor < length; cursor++)
	{
		data[low + cursor] = tmp[cursor];
	}

	delete[] tmp;
}
void Sort::MergeSortRecursionHelper(int low, int high)
{
	RecursionCounter rcTmp;	// used for Unit Testing. DO NOT REMOVE
	// i = middle index or the end of the left array
	// k = is the end index or the end of the right array
	//base case
	if (low >= high)
	{
		return;
	}

	int middle = (low + high) / 2;

	MergeSortRecursionHelper(low, middle);
	MergeSortRecursionHelper(middle + 1, high);
	Merge(low, middle, high);
}

void Sort::QuickSort()
{
	QuickSortRecursionHelper(0, size - 1);
}

void Sort::QuickSortRecursionHelper(int initialLowIndex, int initialHighIndex)
{
	RecursionCounter rcTmp;	// used for Unit Testing. DO NOT REMOVE

	if (initialLowIndex >= initialHighIndex)
	{
		return;
	}

	int pivotIndex = Partition(initialLowIndex, initialHighIndex);

	QuickSortRecursionHelper(initialLowIndex, pivotIndex);
	QuickSortRecursionHelper(pivotIndex + 1, initialHighIndex);

}

int Sort::Partition(int low, int high)
{
	bool done = false;
	int middle = (high + low) / 2;

	int pivot = data[middle];

	
	while (!done)
	{
		// if the element is les than the pivot the element will stay
		while (data[low] < pivot)
		{
			low++;
		}
		// if the element is larger that the pivot then the element will stay
		while (data[high] > pivot)
		{
			high--;
		}
		if (low >= high)
		{
			done = true;
		}
		else
		{
			int tmp = data[low];
			data[low] = data[high];
			data[high] = tmp;
			low++;
			high--;
		}
	}
	return high;
}