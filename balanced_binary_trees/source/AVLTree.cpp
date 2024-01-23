#include"AVLTree.h"
#include<iostream>


#include "AVLTree.h"

AVLTree::AVLTree()
{
	root = nullptr;
}

void DestructorHelper(Node* cursor)
{

	if (cursor == nullptr)
	{
		return;
	}
	DestructorHelper(cursor->left);
	DestructorHelper(cursor->right);
	delete cursor;
}

AVLTree::~AVLTree()
{
	DestructorHelper(root);
}

//Node* Rebalance(Node* cursor, int balance)
//{
//	enum Bal{left = -2, right = 2, r = 1, l = -1};
//	Node* tmp;
//	switch (balance)
//	{
//	case left: // rotate left
//		tmp = cursor->right;
//		cursor->right = tmp->left;
//		tmp->left = cursor;
//		cursor->UpdateHeight();
//		tmp->UpdateHeight();
//		return tmp;
//	case right:
//		tmp = cursor->left;
//		cursor->left = tmp->right;
//		tmp->right = cursor;
//		cursor->UpdateHeight();
//		tmp->UpdateHeight();
//		return tmp;
//	case l:
//		tmp = cursor->right;
//		cursor->right = tmp->left;
//		tmp->left = cursor;
//		cursor->UpdateHeight();
//		tmp->UpdateHeight();
//		return tmp;
//	case r:
//		tmp = cursor->left;
//		cursor->left = tmp->right;
//		tmp->right = cursor;
//		cursor->UpdateHeight();
//		tmp->UpdateHeight();
//		return tmp;
//	}
//}

Node* RightRotate(Node* cursor)
{
	Node* tmp = cursor->left;
	cursor->left = tmp->right;
	tmp->right = cursor;
	cursor->UpdateHeight();
	tmp->UpdateHeight();
	return tmp;
}

Node* LeftRotate(Node* cursor)
{
	Node* tmp = cursor->right;
	cursor->right = tmp->left;
	tmp->left = cursor;
	cursor->UpdateHeight();
	tmp->UpdateHeight();
	return tmp;
}

int GetBalanceFactor(Node* cursor)
{
	if (cursor->IsLeaf()) // is a leaf
	{
		return 0;
	}
	if (cursor->left == nullptr) // has only right child
	{
		return (-1 - cursor->right->height);
	}
	if (cursor->right == nullptr) // has only left child
	{
		return (cursor->left->height - -1);
	}
	else // two children
	{
		return (cursor->left->height - cursor->right->height);
	}
}



void AVLTree::Insert(int value)
{
	root = InsertHelper(root, value);
}
Node* AVLTree::InsertHelper(Node* cursor, int value)
{

	// base case
	if (cursor == nullptr)
	{
		return new Node(value);
	}
	else if (value <= cursor->value)
	{
		cursor->left = InsertHelper(cursor->left, value);
	}
	else if (value > cursor->value)
	{
		cursor->right = InsertHelper(cursor->right, value);
	}

	cursor->UpdateHeight();

	if (GetBalanceFactor(cursor) == -2) //left rotate
	{
		if (GetBalanceFactor(cursor->right) > 0)
		{
			cursor->right = RightRotate(cursor->right);
		}
		cursor = LeftRotate(cursor);
	}
	else if (GetBalanceFactor(cursor) == 2) // right rotate
	{
		if (GetBalanceFactor(cursor->left) < 0)
		{
			cursor->left = LeftRotate(cursor->left);
		}
		cursor = RightRotate(cursor);
	}
	
	return cursor;
}


void AVLTree::Print()
{
	std::string offset = "";
	PrintHelper(offset, root);
	std::cout << std::endl << std::endl;
}
void AVLTree::PrintHelper(std::string& offset, Node* cursor)
{

	//base case
	if (cursor == nullptr)
	{
		std::cout << offset << "[Empty]" << std::endl;
		return;
	}

	// me
	if (cursor->IsLeaf())
	{
		std::cout << offset << cursor->value << " (0) [leaf]" << std::endl;
		return;
	}
	else
		std::cout << offset << cursor->value << " (" << cursor->height << ") " << std::endl;
	//left
	std::string tmp = offset + "   ";
	PrintHelper(tmp, cursor->left);
	//right child
	PrintHelper(tmp, cursor->right);
}

/// balance factor is left height - right height

void AVLTree::PreOrderTraversal()
{
	PreOrderTraversalHelper(root);
	std::cout << std::endl;
}

void AVLTree::PreOrderTraversalHelper(Node* cursor)
{
	if (cursor == nullptr)
		return;
	std::cout << cursor->value << ", ";
	PreOrderTraversalHelper(cursor->left);
	PreOrderTraversalHelper(cursor->right);
}