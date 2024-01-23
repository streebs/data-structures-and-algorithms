#include <iostream>
#include "BinarySearchTree.h"
#include "Observer.h"
#include "RecursionCounter.h"


using namespace std;

// needed for Unit Testing. DO NOT REMOVE
int Observer::numConstructions = 0;
int Observer::numDestructions = 0;
int RecursionCounter::currentDepth = 0;
int RecursionCounter::maxDepth = 0;

int main()
{

	int data[] = { 21,26,30,9,4,14,28,18,15,10,2,3,7 };

   BinarySearchTree bst;

	int length = sizeof(data) / sizeof(data[0]);

	for (size_t i = 0; i < length ; i++)
	{
		bst.Insert(data[i]);
	}

	bst.InOrderTraversal();
	cout << endl;
	bst.Print();
	cout << endl << endl;

	bst.Remove(21);
	bst.Remove(9);
	bst.Remove(4);
	bst.Remove(18);
	bst.Remove(15);
	bst.Remove(7);

	bst.Print();
	
	cout << endl;
	cout << endl;
	bst.InOrderTraversal();
	cout << endl;
}