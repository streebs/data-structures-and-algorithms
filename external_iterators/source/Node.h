#ifndef __NODE__
#define __NODE__
#include "Observer.h"

class Node
{
public:
	Node();
	int data;
	Node* next;
private:
	Observer tmp;  // for testing purposes only. DO NOT REMOVE
};

#endif