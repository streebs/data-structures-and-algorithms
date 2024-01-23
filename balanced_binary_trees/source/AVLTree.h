#ifndef __AVLTree__
#define __AVLTree__
#include"Node.h"
#include"Observer.h"


class AVLTree
{
public:
	AVLTree();
	~AVLTree();
	void Insert(int value);
	void Print();
	void PreOrderTraversal();
	Node* GetRoot() { return root; }

	Node* InsertHelper(Node* cursor, int data);
	void PrintHelper(std::string& offset, Node* cursor);
	void PreOrderTraversalHelper(Node* cursor);

	Node* root;
};

#endif

