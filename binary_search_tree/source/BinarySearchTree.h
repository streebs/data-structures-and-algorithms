#ifndef __BinarySearchTree__
#define __BinarySearchTree__


#include"Node.h"
#include"Observer.h"
#include"RecursionCounter.h"
#include<iostream>
#include<string>


class BinarySearchTree
{
public:
	Node* root;

	BinarySearchTree();
	~BinarySearchTree();
	
	void Insert(int data);
	Node* Search(int data);
	void Remove(int data);
	void InOrderTraversal();
	void Print();
	int Size();

private:


	Node* InsertHelper(Node* cursor, int data);
	Node* SearchHelper(Node* cursor, int data);
	Node* RemoveHelper(Node* cursor, int data);
	void InOrderHelper(Node* cursor);
	void PrintHelper(std::string& offset, Node* cursor);
	int SizeHelper(Node* cursor);
	// to find my hieght i juse need to take the highes height of my childeren and add 1; 
	
   RecursionCounter neededForUnitTest;

};

#endif