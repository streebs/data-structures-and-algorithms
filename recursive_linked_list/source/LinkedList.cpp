#include "Course.h"
#include "LinkedList.h"
#include <iostream>
using namespace std;

void LinkedList::Insert(Course* newCourse)
{
	head = InsertHelper(head, newCourse);
}
Course * LinkedList::InsertHelper(Course * cursor, Course * newCourse)
{
	RecursionCounter rcTmp;   // used for testing purposes
   //base case at the end of the list
	if (cursor == nullptr) 
	{
		return newCourse;
	}
	// second base case
	if (newCourse->courseNumber <= cursor->courseNumber)
	{
		newCourse->next = cursor;
		return newCourse;
	}
	//recursive case
	cursor->next = InsertHelper(cursor->next, newCourse);
	return cursor;
}

int LinkedList::Size() const
{
	return SizeHelper(head);
}
int LinkedList::SizeHelper(Course const * cursor) const
{
	RecursionCounter rcTmp;   // used for testing purposes
   if (cursor == nullptr)
		return 0;
	else
		return 1 + SizeHelper(cursor->next);
}

void LinkedList::PrintList() const
{
	PrintListHelper(head);
}
void LinkedList::PrintListHelper(Course const * cursor) const
{
	RecursionCounter rcTmp;   // used for testing purposes
   //base case
	if (cursor == nullptr)
	{
		cout << endl;
		return;
	}
	//print the object member variables in the right order
	cout << "cs" << cursor->courseNumber << ' ' << cursor->courseName << ' ' << "Grade:" << cursor->grade << ' ' << "Credit Hours: " << cursor->credits << endl;
	//recursive case
	PrintListHelper(cursor->next);
}

LinkedList::~LinkedList()
{
	DestructorHelper(head);
}
void LinkedList::DestructorHelper(Course * cursor)
{
	RecursionCounter rcTmp;   // used for testing purposes
	if (cursor == nullptr)
		return;

	DestructorHelper(cursor->next);
	delete cursor; /// this might be an issue??
}

double LinkedList::CalculateGPA() const
{
	return (CalculateTotalGradePoints(head)) / CalculateTotalCredits(head);
}
double LinkedList::CalculateTotalGradePoints(Course const * cursor) const
{
	RecursionCounter rcTmp;   // used for testing purposes
   if (cursor == nullptr)
		return 0.0;
	return (cursor->grade + CalculateTotalGradePoints(cursor->next)) * cursor->credits;
}

unsigned int LinkedList::CalculateTotalCredits(Course const * cursor) const
{
	RecursionCounter rcTmp;   // used for testing purposes
   if (cursor == nullptr)
		return 0;
	return cursor->credits + CalculateTotalCredits(cursor->next);
}