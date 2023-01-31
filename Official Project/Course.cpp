/*
    Crocsociety

	Cooke, Jared
    Gomez, Erick
    Schuenman, Greyson
    Nguyen, Brandy

	Fall 2022
	CS A250 - C++ 2
	Project: CS Courses
*/

#include "Course.h"

#include <iostream>
#include <iomanip>
using namespace std;

const string Course::PREFIX = "CS A";

// ------ Constructor ------
Course::Course(int newCourseNumber, const std::string& newCourseName,
	int newCourseUnits, const std::set<int>& newPrereqs)
	{
		courseNumber = newCourseNumber;
		courseName = newCourseName;
		courseUnits = newCourseUnits;
		prereqs = newPrereqs;
	}

// ------ Accessor functions ------
// Definition function getCourseName
const string& Course::getCourseName() const
{
	return courseName;
}

// Definition function getCourseNumber
int Course::getCourseNumber() const
{
	return courseNumber;
}

// Definition function getCourseUnits
int Course::getCourseUnits() const
{
	return courseUnits;
}

// Definition function getPrereqs
const set<int>& Course::getCoursePrereqs() const
{
	return prereqs;
}

// Definition function getCourse
const Course& Course::getCourse() const
{
	return *this;
}

// Definition function getPrefix
string Course::getPrefix()
{
	return PREFIX;
}

// ------ Mutator functions ------
// Definition function setCourseName
void Course::setCourseName(const string& newName)
{
	courseName = newName;
}

// Definition function setCourseNumber
void Course::setCourseNumber(int newNumber)
{
	courseNumber = newNumber;
}

// Definition function setCourseUnits
void Course::setCourseUnits(int newUnits)
{
	courseUnits = newUnits;
}

// Definition function setPrereqs
void Course::setPrereqs(const int arr[], int length)
{
	if (!prereqs.empty()) prereqs.clear();

	for (int i = 0; i < length; ++i)
		prereqs.insert(arr[i]);
}