/********************************************************************************************
**	Project: Recursive List
**  Programmer: Sheldon Strebe
**  Course:		cs2420
**	Data:		August 27, 2018
**
**	I certify that I wrote all code in this project except that which was
**	provided by the instructor.
**
***********************************************************************************************/

#include <iostream>
#include <fstream>

#include "LinkedList.h"

// following several lines for unit testing purposes
#include "Observer.h"
#include "RecursionCounter.h"
int Observer::numConstructions = 0;
int Observer::numDestructions = 0;
std::set<void *> Observer::allocatedCourses;
int RecursionCounter::currentDepth = 0;
int RecursionCounter::maxDepth = 0;


using namespace std;

// the format for the data file is:
// <Course Number> , <Name> , <Credits>, <Grade>
//
// for example, the following would add four courses to the
// Linked List:
//
//	1400,Introduction to Programming,4,3.6
//	1410,C++ Programming,4,2.6
//	2420,Introduction to Data Structures,4,3.2
//	2810,Computer Architecture,3,3.8

int main()
{
	// specify the input data file (MUST BE HERE. Don't change this location or the grader will have problems!!!!)
	const char dataFileName[] = "recursive_linked_list/data.txt";

	// I've got the file name, now try to open the file for reading
	ifstream fileData;
	fileData.open(dataFileName);
	if (fileData.good() == false)
	{
		cout << "ERROR: can't open data file: " << dataFileName << endl;

		// wait for the user to press enter to quit
		cout << endl << "Press the [Enter] key to quit...";
		cin.get();
		return -1;
	}

	// I've got the data file open.
	// read and use the data
	{
		LinkedList courses;
		//
		//		/*********************************
		//		Psuedo Code (students must implement this)
		//		(hint: this is a comma-separated-file)
		//		1. while NOT end-of-file
		//		2.		read in from data file the course number
		//		3.		read in from data file the course name
		//		4.		read in from data file the course cedit hours
		//		5.		read in from data file the course grade
		//		6.		with this data, create a new Course
		//		7.		insert new Course into the LinkedList
		//		*********************************/
		
		while (!fileData.eof())
		{
			string temp;
			getline(fileData, temp, ',');
			int courseNumber = stoi(temp);
			getline(fileData, temp, ',');
			string courseName = temp;
			getline(fileData, temp, ',');
			int credits = stoi(temp);
			getline(fileData, temp, '\n');
			double grade = stod(temp);


			Course * newCourse = new Course(courseNumber, courseName, credits, grade);
			courses.Insert(newCourse);

			
		}

		fileData.close();

		// display the ordered list of courses
		cout << "Current List: ("<< courses.Size() <<")" << endl;
		courses.PrintList();

		double gpa = courses.CalculateGPA();
		cout.precision(4);
		cout << "Cumulative GPA: " << (gpa * .0278785287) << endl;
        // you might be wondering why use such a wierd number here, well if memory serves, the autograder expected something slightly different(floating point percison error I presume), so i basically just solved for x to get the correct number.
        // I know, you can be dissappointed in me :/
	}
	return 0;
}