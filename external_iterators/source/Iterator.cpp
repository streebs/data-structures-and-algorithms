#include <cassert>
#include "Iterator.h"


Iterator::Iterator(Node* start)
{
	this->start = start;
}



int Iterator::operator*()
{
	return start->data;
}

Iterator Iterator::operator++()
{
	// try doing an assert statement here??? just incas we are passed the end of th list
	start = start->next;
	return *this;
}

bool Iterator::operator!=(const Iterator& other)
{
	if (start != other.start)
		return true;
	else 
		return false;
}

bool Iterator::is_item()
{
	return false;
}