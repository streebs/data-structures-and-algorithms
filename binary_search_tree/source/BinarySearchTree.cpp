#include "BinarySearchTree.h"
#include "Observer.h"


BinarySearchTree::BinarySearchTree()
{
	root = nullptr;
}

void DestructorHelper(Node* cursor)
{
	//RecursionCounter neededForUnitTest;

	if (cursor == nullptr)
	{
		return;	
	}
	DestructorHelper(cursor->leftChild);
	DestructorHelper(cursor->rightChild);
	delete cursor;
}

BinarySearchTree::~BinarySearchTree()
{
	DestructorHelper(root);
}

void BinarySearchTree::Insert(int data)
{
	root = InsertHelper(root, data);
}
Node* BinarySearchTree::InsertHelper(Node* cursor, int data)
{
	RecursionCounter neededForUnitTest;

	// base case
	if (cursor == nullptr)
		return new Node(data);

	else if (data <= cursor->data)
		cursor->leftChild = InsertHelper(cursor->leftChild, data);
	else
		cursor->rightChild = InsertHelper(cursor->rightChild, data);

	cursor->UpdateHeight(); // here it will recursively update the height
	return cursor;
}


Node* BinarySearchTree::Search(int data)
{
	return SearchHelper(root, data);
}
Node* BinarySearchTree::SearchHelper(Node* cursor, int data)
{
	RecursionCounter neededForUnitTest;
   if(cursor == nullptr)
   {
      return cursor;
   }
      
	if (data == cursor->data)
		return cursor;
	else if (data <= cursor->data)
		return SearchHelper(cursor->leftChild, data);
	else
		return SearchHelper(cursor->rightChild, data);
	return cursor; // i might need to return nullptr for numbers not in the tree
}

void BinarySearchTree::Remove(int data)
{
	root = RemoveHelper(root, data);
}
Node* BinarySearchTree::RemoveHelper(Node* cursor, int data)
{
	RecursionCounter neededForUnitTest;
	
	if(cursor == nullptr)
	{
	   return cursor;
	}
	if (data == cursor->data)
	{
		if (cursor->IsLeaf())
		{
			delete cursor;
			return nullptr;
		}

		if (cursor->leftChild == nullptr && cursor->rightChild != nullptr) // has a right child
		{
			Node* tmp = cursor;
			cursor = cursor->rightChild;
			delete tmp;
			return cursor;
		}

		if (cursor->rightChild == nullptr && cursor->leftChild != nullptr) // has a left child
		{
			Node* tmp = cursor;
			cursor = cursor->leftChild;
			delete tmp;
			return cursor;
		}
		
		// next part is two child condition
		if (cursor->leftChild != nullptr && cursor->rightChild != nullptr)
		{
			Node* successor = cursor->rightChild;
			while (successor->leftChild != nullptr)
			{
				successor = successor->leftChild;
			}
			cursor->data = successor->data;
			// now remove the successor
			cursor->rightChild = RemoveHelper(cursor->rightChild, successor->data);
			return cursor;
		}
	}
	else if (data <= cursor->data) 
	{
		cursor->leftChild = RemoveHelper(cursor->leftChild, data);
		cursor->UpdateHeight();
		return cursor;
	}
	else if (data > cursor->data)
	{
		cursor->rightChild = RemoveHelper(cursor->rightChild, data);
		cursor->UpdateHeight();
		return cursor;
	}
	else
	{
		return cursor; // nullptr
	}
	return cursor; // cursor
}


void BinarySearchTree::InOrderTraversal()
{
	InOrderHelper(root);
}
void BinarySearchTree::InOrderHelper(Node* cursor)
{
	RecursionCounter neededForUnitTest;

	if (cursor == nullptr)
	{
		return;
	}

	InOrderHelper(cursor->leftChild);

	std::cout << cursor->data << ", ";

	InOrderHelper(cursor->rightChild);
	/*
	preorder me, left, right
	inorder left, me, right
	postorder left, right, me <--- destructor!!!!!!!!!!!!
	*/
}


void BinarySearchTree::Print()
{
	std::string offset = "";
	PrintHelper(offset, root);
}
void BinarySearchTree::PrintHelper(std::string& offset, Node* cursor)
{
	RecursionCounter neededForUnitTest;

	//base case
	if (cursor == nullptr)
	{
		std::cout << offset << "[Empty]" << std::endl;
		return;
	}

	// me
	if (cursor->IsLeaf())
	{
		std::cout << offset << cursor->data << " (0) [leaf]" << std::endl;
		return;
	}
	else
		std::cout << offset << cursor->data << " (" << cursor->height << ") " << std::endl;
	//leftchild
	std::string tmp = offset + "   ";
	PrintHelper(tmp, cursor->leftChild);
	//right child
	PrintHelper(tmp, cursor->rightChild);
}


int BinarySearchTree::Size()
{
	return SizeHelper(root) / 2;
}
int BinarySearchTree::SizeHelper(Node* cursor)
{
	RecursionCounter neededForUnitTest;

	int leftSize = 0;
	int rightSize = 0;
	if (cursor == nullptr)
	{
		return 0;
	}
	leftSize = 1 + SizeHelper(cursor->leftChild);
	rightSize = 1 + SizeHelper(cursor->rightChild);

	return (leftSize + rightSize);
}