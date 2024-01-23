#ifndef __LIST__
#define __LIST__
#include "Node.h"
#include "Iterator.h"

class List
{
public:
	List(); // default constructor
	~List(); // destructor
	void push_front(const int& value); // adds ne node to the front of the list
	void push_back(const int& value); // add new node to the back of the list
	void remove(const int& value); // removes ALL nodes in list with this value

	Iterator begin(); // iterator to the begginning of the list
	Iterator end(); // iterator to the end of the list
	int size(); // returns the number of elements in the list
	void PrintList(); // for debugging purposes
	bool isIndex(Node* node, int value);
private:
	int theSize = 0;
	Node* head;
	Node* tail;
	// TODO maybe?????
};

#endif