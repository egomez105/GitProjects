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

#include "CourseList.h"

#include <iostream>
using namespace std;

// Overloaded constructor
CourseList::CourseList(Node* ptrToFirst, Node* ptrToLast, int theCount)
{
    first = ptrToFirst;
    last = ptrToLast;
    count = theCount;
}

// Definition function addCourse
void CourseList::addCourse(const Course& aCourse)
{
    insertInOrder(new Node(aCourse, nullptr));
}

// Definition function addCourse
void CourseList::addCourse(int newNumber, const std::string& newName,
    int newUnits, const std::set<int>& newPrereqs)
    {
        insertInOrder(new Node(
            {newNumber, newName, newUnits, newPrereqs}, nullptr));
    }

// Definition function getPrefix
static string getPrefix()
{
    return Course::getPrefix();
}

// Definition function getNumberOfCourses
int CourseList::getNumberOfCourses() const
{
    return count;
}

// Definition function isEmpty
bool CourseList::isEmpty() const
{
    return (count == 0);
}

// Definition function searchCourse (courseNumber)
bool CourseList::searchCourse(int aNumber) const
{
    return getCourseLocation(aNumber) != nullptr;
}

// Definition function searchCourse (courseNumber, courseName)
bool CourseList::searchCourse(int aNumber, std::string& aName) const
{
    Node * ptr = getCourseLocation(aNumber);

    if (ptr != nullptr)
    {
        aName = ptr->getCourse().getCourseName();
        return true;
    }
    return false;
}

// Definition function searchCourse (courseNumber, Course&)
bool CourseList::searchCourse(int aNumber, Course& aCourse) const
{
    Node * ptr = getCourseLocation(aNumber);

    if (ptr != nullptr)
    {
        aCourse = ptr->getCourse();
        return true;
    }
    return false;
}

// Definitiion deleteCourse
void CourseList::deleteCourse(int aNumber)
{
    Node * trailCurrent = first;
    
    if (trailCurrent->getCourse().getCourseNumber() == aNumber)
    {
        first = first->getNext();
        delete trailCurrent;
        trailCurrent = nullptr;
    }
    else
    {
        Node * current = trailCurrent->getNext();

        while (current != nullptr)
        {
            if (current->getCourse().getCourseNumber() == aNumber)
            {
                trailCurrent->setNext(current->getNext());
                delete current;
                
                current = nullptr;
                trailCurrent = nullptr;
            }
            else
            {
                trailCurrent = current;
                current = current->getNext();
            }
        }
    }
    --count;
}

// Definition retrieveAllCourses
void CourseList::retrieveAllCourses(std::string& courses) const
{
    courses = "";
    Node * current = first;

    while (current != nullptr)
    {
        Course tempCourse = current->getCourse();

        courses += tempCourse.getPrefix()
            + to_string(tempCourse.getCourseNumber())
            + " - " + tempCourse.getCourseName() + "\n";

        current = current->getNext();
    }
}

// Definition clearList
void CourseList::clearList()
{
    Node * current = first;

    while (first != nullptr)
    {
        first = first->getNext();
        delete current;
        current = first;
    }
    count = 0;
}

// Definition function getCourseLocation
Node* CourseList::getCourseLocation(int aNumber) const
{
    Node * current = first;

    while (current != nullptr)
    {
        if (current->getCourse().getCourseNumber() == aNumber)
            return current;
    
        current = current->getNext();
    }
    return current;
}