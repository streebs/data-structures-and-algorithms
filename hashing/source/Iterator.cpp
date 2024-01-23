#include "HashMap.h"

Iterator::Iterator(int index, Node** hashArray, int sizeOfArray)
{

	this->index = index;
	this->hashArray = hashArray;
	this->sizeOfArray = sizeOfArray;
	
	if (index >= sizeOfArray) // && current->next == nullptr)
	{
		current = nullptr;
	}
	else if(index < sizeOfArray)
	{
		while (hashArray[index] == nullptr && index < sizeOfArray - 1)
		{
			index++;
		}
		current = hashArray[index];
	}
}

Iterator::Iterator()
{
	index = 0;
	sizeOfArray = 0;
	hashArray = nullptr;
	current = nullptr;

}

string Iterator::operator*()
{
	return current->key;
}

void Iterator::operator++()
{
	if (current != nullptr) // is there a node at current index?
	{
		if (current->next == nullptr) // does this node have another node attatched to it?
		{
			if (index == sizeOfArray - 1)
			{
				current = nullptr;
			}
			else
			{
				index++;
				current = hashArray[index];
				while (current == nullptr)
				{
					index++;
					current = hashArray[index];
				}
			}
			
		}
		else
		{
			current = current->next;
		}
	}
}

bool Iterator::operator!=(Iterator& other)
{
	if (current != other.current)
		return true;
	else
		return false;
}

bool Iterator::is_item()
{
	return false;
}
