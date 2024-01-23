#include "Node.h"
#include<algorithm>

Node::Node(int data, int height, Node* leftChild, Node* rightChild) // hmmmmm?
{
	this->data = data;
	this->height = height;
	this->leftChild = leftChild;
	this->rightChild = rightChild;
}

Node::~Node()
{
}

bool Node::IsLeaf()
{
	if (leftChild == nullptr && rightChild == nullptr)
		return true;
	else
		return false;
}

void Node::UpdateHeight()
{

	if (leftChild == nullptr && rightChild == nullptr)
	{
		height = -1;
	}
	else if (leftChild == nullptr && rightChild != nullptr)
	{
		height = rightChild->height + 1;
	}
	else if (leftChild != nullptr && rightChild == nullptr)
	{
		height = leftChild->height + 1;
	}
	else 
	{
		int Max = std::max(leftChild->height, rightChild->height);

		height = Max + 1;
	}
	return;
}
