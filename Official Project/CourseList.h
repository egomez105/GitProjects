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

#ifndef COURSELIST_H
#define COURSELIST_H

#include "Course.h"

#include <string>
#include <set>

class Node
{
public:
	Node() : course(), next(nullptr) {}
	Node(const Course& newCourse, Node* newNext)
		: course(newCourse), next(newNext) {}
	Course getCourse() const { return course; }
	Node* getNext() const { return next; }
	void setCourse(const Course& newCourse) { course = newCourse; }
	void setNext(Node* newNext) { next = newNext; }
	~Node() {}
private:
	Course course;
	Node* next;
};

class CourseList
{
public:
	// Constructors
	CourseList() : first(nullptr), last(nullptr), count(0) {}
	CourseList(Node* ptrToFirst, Node* ptrToLast, int theCount);
	
	// Functions addCourse
	void addCourse(const Course& aCourse);
	void addCourse(int newNumber, const std::string& newName, int newUnits,
		const std::set<int>& newPrereqs);

	// Accessor functions
	static std::string getPrefix();
	int getNumberOfCourses() const;

	// Boolean functions
	bool isEmpty() const;
	bool searchCourse(int aNumber) const;
	bool searchCourse(int aNumber, std::string& aName) const;
	bool searchCourse(int aNumber, Course& aCourse) const;

	// Function deleteCourse
	void deleteCourse(int aNumber);

	// Function retrieveAllCourses
	void retrieveAllCourses(std::string& courses) const;

	// Function clearList
	void clearList();

	/********************* THE BIG THREE *********************/
	// Copy constructor	
	CourseList(const CourseList& oldCourseList);
	
	// Overloaded assignment operator
	CourseList& operator=(const CourseList& copyObj);

	// Destructor
	~CourseList();

private:
	// Function getCourseLocation
	Node* getCourseLocation(int aNumber) const;

	// Function addInOrder
	void insertInOrder(Node* ptr);
	
	// Helper functions for overloaded assignment operator
	void copyCallingObjIsEmpty(const CourseList& copyObj);
	void copyObjectsSameLength(const CourseList& copyObj);
	void copyCallingObjLonger(const CourseList& copyObj);
	void copyCallingObjShorter(const CourseList& copyObj);

	Node* first;
	Node* last;
	int count;
};

#endif