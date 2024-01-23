#ifndef __Node__
#define __Node__

#include"Observer.h"
#include<iostream>

class Node
{
public:
	Node(int data = 0, int height = 0, Node* leftChild = nullptr, Node* rightChild = nullptr); // we can declare the values in here to create a semi-default constructor // -1
	~Node();
	bool IsLeaf();
	void UpdateHeight();

	int data; 
	Node* leftChild;
	Node* rightChild;
	int height;
private:
	Observer neededForUnitTest;
};

#endif