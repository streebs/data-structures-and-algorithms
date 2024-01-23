#include "HashMap.h"

HashMap::HashMap(int size)
{
	hashArray = new Node * [size];
	for (int i = 0; i < size; i++)
	{
		hashArray[i] = nullptr;
	}
	sizeOfArray = size;
}

HashMap::~HashMap()
{
	Node* tmp;

	for (size_t i = 0; i < sizeOfArray; i++)
	{
		if (hashArray[i] != nullptr)
		{
			while (hashArray[i]->next != nullptr)
			{
				tmp = hashArray[i];
				hashArray[i] = hashArray[i]->next;
				delete tmp;
			}
			delete hashArray[i];
		}
	}
	delete[] hashArray;
}

bool HashMap::IsKeyPresent(string const& key) const
{
	int find = GenerateHash(key);

	if (hashArray[find] != nullptr)
	{
		return true;
	}
	return false;
}

void HashMap::SetKeyValue(string const& key, int value)
{
	Node* tmp;
	int bucket = GenerateHash(key);
	tmp = hashArray[bucket];
	
	if (hashArray[bucket] ==  nullptr)
	{
		hashArray[bucket] = new Node(key, value, nullptr);
	}
	else
	{
		while (tmp != nullptr)
		{
			if (key == tmp->key)
			{
				tmp->value = value;
				return;
			}
			tmp = tmp->next;
		}
		if (tmp == nullptr) // which means we got through the while loop without finding a match
		{
			tmp = hashArray[bucket];
			hashArray[bucket] = new Node(key, value, tmp);
		}
	}
	//	hashArray[168] = new Node();
}

bool HashMap::GetKeyValue(string const& key, int& value)
{
	// if it is in the map what is the count
	// changing value here will change current count in main
	if (IsKeyPresent(key))
	{
		int find = GenerateHash(key);
		Node* tmp = hashArray[find];
		while (tmp != nullptr)
		{
			if (tmp->key == key)
			{
				value = tmp->value;
				return true;
			}
			tmp = tmp->next;
		}
	}
	else
	{
		value = 0;
		return false;
	}

    return false;
}

Iterator HashMap::begin()
{
	return Iterator(0, hashArray, sizeOfArray);
}

Iterator HashMap::end()
{
	return Iterator(sizeOfArray, hashArray, sizeOfArray);
}

int HashMap::GenerateHash(string key) const
{
	const int INITIAL_HASH = 7;
	int hashValue = INITIAL_HASH;

	for (int i = 0; i < key.length(); i++)
	{
		hashValue += (hashValue * 17) + key[i];
	}
	return abs(hashValue % sizeOfArray);
}