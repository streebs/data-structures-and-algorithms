#include "List.h"

List::List()
{
	head = nullptr; 
	tail = head;
}

List::~List()
{
	Node* cursor = head;
	Node* tmp;
	while (cursor != nullptr)
	{
		tmp = cursor;
		cursor = cursor->next;
		delete tmp;
	}

}

void List::push_front(const int& value)
{
	
	if (head == nullptr) // if there is nothing in the list
	{
		head = new Node; // create a new node and assign it to the head
		head->data = value; // assign the passed in value to the data member of the node obj
		theSize++; // incrememnt the size of the list
	}
	else // if there is one or more nodes in the list
	{
		Node* cursor = new Node; // create a new node that will be added to the front of the list
		Node* tmp; // tmp node for later

		cursor->data = value;  // assign passed in value to the data member of the node obj
		tmp = head; // assign the obj that head points to to tmp
		head = cursor; // lew our new node with the correct data be assigned to head
		cursor->next = tmp; // let the new head point to the old head
		
		theSize++; // incrament the size of the list
	}
}

void List::push_back(const int& value)
{
	Node* tmp;
	// if nothing is in the list the head becomes the new node
	if (head == nullptr)
	{
		head = new Node;
		head->data = value;
		theSize++;
		tail = head; // because there is only one thing in the list the tail and the head are the same node
	}
	else // if there is at least one node in the linked list
	{
		if (tail == head) // if there is only one node in the list
		{
			tail = new Node; // create a new node to become the new tail
			head->next = tail; // attatch the tail to the head (remember there is only one item in the list so it must be attatched to the head)
			tail->data = value; // assign the passed in value to the data member of the node obj
			theSize++; // increment the size of the array;
		}
		else // if there is more than one element in the list
		{
			tmp = tail; // put the current tail in a tmp pointer
			tail = new Node; // create a new node and assign it to tail
			tmp->next = tail; // point the tmp value to the new tail
			tail->data = value; // assign the passed in value to the data member of the node obj
		}
	}
}

void List::remove(const int& value)
{
	Node* cursor;
	Node* tmp;
	cursor = head;

	while (cursor->next != nullptr)
	{
		if (cursor->data == value)
		{
			tmp = cursor;
			head = cursor->next;
			delete tmp;
			cursor = head;
			theSize--;
		}
		else if (cursor->next->data == value)
		{
			tmp = cursor->next;
			cursor->next = cursor->next->next;
			delete tmp;
			cursor = head;
			theSize--;
		}
		cursor = cursor->next;
	}

}

Iterator List::begin()
{
	
	return Iterator(head);
}

Iterator List::end()
{
	return Iterator(nullptr);
}

int List::size()
{
	return theSize;
}

void List::PrintList()
{
	Node* cursor;
	cursor = head; // let cursor be a place holde for the head so we dont have to change the actual value of head
	while (cursor->next != nullptr)
	{
		std::cout << cursor->data << " ";
		cursor = cursor->next; // this is what we use to incrament the pointer to the nodes in the linked list see explanation below

		/* originally i tried to incrament the nodes by using cursor++. however, this did not work. pointer additon works for arrays because each index is 
			is in fact located next to each other in memory. in the case of this linked list pointer addition does not work because each time we add a new node
			a completely new place in memory is allocated by the compiler. because i did not instruct the compiler to alocate memory next to the previous node.
		*/
	}
	std::cout << cursor->data << " " << std::endl; // because the while loop looks at the next element before starting the last element does not get printed in the loop//
}
