#include"Node.h"
#include<iostream>
#include<algorithm>


Node::Node(int value, int height, Node* left, Node* right)
{
	this->value = value;
	this->height = height;
	this->left = left;
	this->right = right;
}

bool Node::IsLeaf()
{
	if (left == nullptr && right == nullptr)
		return true;
	else
		return false;
}

void Node::UpdateHeight()
{

	if (left == nullptr && right == nullptr)
	{
		height = 0;
	}
	else if (left == nullptr && right != nullptr)
	{
		height = right->height + 1;
	}
	else if (left != nullptr && right == nullptr)
	{
		height = left->height + 1;
	}
	else
	{
		int Max = std::max(left->height, right->height);

		height = Max + 1;
	}
	return;
}