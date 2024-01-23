#ifndef __NODE__
#define __NODE__

#include "Observer.h"

class Node
{
public:
	Node(int value = 0, int height = 0, Node* left = nullptr, Node* right = nullptr);
	~Node() = default;
	bool IsLeaf();
	void UpdateHeight();

	int value;
	int height;
	Node* left;
	Node* right;
	Observer observer;	// needed for Unit Testing. Do Not Remove
};

#endif // __NODE__