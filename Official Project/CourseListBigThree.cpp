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

// Copy constructor
CourseList::CourseList(const CourseList& oldCourseList)
{
   first = last = nullptr;
   count = 0;

   if (oldCourseList.first != nullptr)
   {
        first = new Node(oldCourseList.first->getCourse(), nullptr);

        Node * temp = oldCourseList.first->getNext();
        Node *callingNode = first;

        while (temp->getNext() != nullptr)
        {
            Node *newCourse = new Node(temp->getCourse(), temp->getNext());
            callingNode->setNext(newCourse);

            callingNode = callingNode->getNext();
            temp = temp->getNext();
        }

        last = new Node(temp->getCourse(), nullptr);
        callingNode->setNext(last);

        count = oldCourseList.count;
   }
}

// Definition overloaded assignment operator
CourseList& CourseList::operator=(const CourseList& copyObj)
{
    if (&copyObj == this)
    {
        cerr << "Attempted assignment to itself.\n";
    }
    else
    {
        if (copyObj.count == 0)
        {
            clearList();
        }
        else if (count == 0)
        {
            copyCallingObjIsEmpty(copyObj);
        }
        else if (count == copyObj.count)
        {
            copyObjectsSameLength(copyObj);
        }
        else if (count  > copyObj.count)
        {
            copyCallingObjLonger(copyObj);
        }
        else
        {
            copyCallingObjShorter(copyObj);
        }
    }
    return *this;
}

// Definition function copyCallingObjIsEmpty
void CourseList::copyCallingObjIsEmpty(const CourseList& copyObj)
{
    Node *paramCurrentNode = copyObj.first->getNext();
    first = new Node(copyObj.first->getCourse(), paramCurrentNode);

    Node *callingCurrent = first->getNext();

    while (paramCurrentNode->getNext() != nullptr)
    {
        callingCurrent->setCourse(paramCurrentNode->getCourse());

        paramCurrentNode = paramCurrentNode->getNext();
        callingCurrent = callingCurrent->getNext();
    }
    last = paramCurrentNode;
    count = copyObj.count;   
}

// Definition function copyObjectsSameLength
void CourseList::copyObjectsSameLength(const CourseList& copyObj)
{
    Node *paramCurrentNode = copyObj.first;
    Node *callingCurrent = first;
    
    while (paramCurrentNode != nullptr)
    {
        callingCurrent->setCourse(paramCurrentNode->getCourse());

        callingCurrent = callingCurrent->getNext();
        paramCurrentNode = paramCurrentNode->getNext();
    }
    count = copyObj.count;
}

// Definition function copyCallingObjLonger
void CourseList::copyCallingObjLonger(const CourseList& copyObj)
{
    Node* callingCurrent = first;
    Node* paramCurrentNode = copyObj.first;

    while(paramCurrentNode->getNext() != nullptr)
    {
        callingCurrent->setCourse(paramCurrentNode->getCourse());

        callingCurrent = callingCurrent->getNext();
        paramCurrentNode = paramCurrentNode->getNext();
    }
    callingCurrent->setCourse(paramCurrentNode->getCourse());
    last = callingCurrent;
    
    callingCurrent = callingCurrent->getNext();
    while (callingCurrent != nullptr)
    {
       // re-using ptr paramCurrentNode instead of creating a new variable
       paramCurrentNode = callingCurrent->getNext();
       deleteCourse(callingCurrent->getCourse().getCourseNumber());
       callingCurrent = paramCurrentNode;
    }
    count = copyObj.count;
}

// Definition function copyCallingObjShorter
void CourseList::copyCallingObjShorter(const CourseList& copyObj)
{
    Node* callingCurrent = first;
    Node* paramCurrentNode = copyObj.first;

    while (paramCurrentNode != nullptr)
    {
        if(callingCurrent == nullptr)
        {
            addCourse(paramCurrentNode->getCourse());
        }
        else
        {
            callingCurrent->setCourse(paramCurrentNode->getCourse());
            callingCurrent = callingCurrent->getNext();
        }
        paramCurrentNode = paramCurrentNode->getNext();
    }
    count = copyObj.count;
}

// Destructor
CourseList::~CourseList()
{
    if (count > 0) clearList();
}