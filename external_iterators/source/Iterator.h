#ifndef __ITERATOR__
#define __ITERATOR__
#include "Node.h"

class Iterator
{
public:
	Iterator(Node* start); // the iterator initially points to start
	~Iterator() = default;
	int operator*(); // dereference the iterator
	Iterator operator++(); // advance the iterator
	bool operator!=(const Iterator& other); //returns true if an only if other iterator does not equal this iterator 
	bool is_item(); // returns true if iteratior points tia valid Node (if nullptr return false)

	//Iterator(int* data = nullptr, int index = 0);


	Node* start; 

};

#endif