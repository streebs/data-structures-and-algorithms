#include "DynamicArray.h"

DynamicArray::DynamicArray()
{
	capacity = INITIAL_CAPACITY;
	used = 0;
	transactions = new Transaction[capacity];
}

DynamicArray::~DynamicArray()
{
	delete[] transactions;
}

void DynamicArray::push_back(const Transaction& newTransaction)
{
	if (capacity == used) {
		Transaction* temp = new Transaction[capacity * 2];
		for (int i = 0; i < used; i++)
		{
			temp[i] = transactions[i];
		}
		delete[] transactions;
		transactions = temp;

		capacity *= 2;
		
	}
	transactions[used] = newTransaction;
	used++;
}

int DynamicArray::size() const
{
	return used;
}

int DynamicArray::currentCapacity() const
{
	return capacity;
}

Transaction& DynamicArray::at(int index)
{
	return transactions[index];
}

void DynamicArray::Realloc()
{
	Transaction* temp = new Transaction[capacity * 2];
	for (int i = 0; i < used; i++)
	{
		temp[i] = transactions[i];
	}
	delete[] transactions;
	transactions = temp;

	capacity *= 2;
}