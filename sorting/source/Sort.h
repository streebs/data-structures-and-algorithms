#ifndef __SORT__
#define __SORT__

#include "RecursionCounter.h"
class Sort
{
public:

	Sort(int size);
	~Sort();
	void InitArray();

	void SelectionSort();
	void InsertionSort();
	void AlgorithmSort();
	void MergeSort();
	void QuickSort();

	int GetSize() const { return size; };
	int* GetDataArray()  const { return data; };
private:

	int* data;
	int size;

	void MergeSortRecursionHelper(int indexI, int indexK);
	void Merge(int low, int middle, int high);
	void QuickSortRecursionHelper(int initialLowIndex, int initialHighIndex);
	int Partition(int low, int high);
};

#endif