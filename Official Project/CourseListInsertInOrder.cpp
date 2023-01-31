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

// Definition function insertInOrder
void CourseList::insertInOrder(Node* ptr)
{
    int key = ptr->getCourse().getCourseNumber();

    if (first == nullptr || key < first->getCourse().getCourseNumber())
    {
        ptr->setNext(first);
        first = ptr;
        if (last == nullptr) last = first;
    }
    else
    {
        Node * current = first;
        
        while (current->getNext() != nullptr && 
            current->getNext()->getCourse().getCourseNumber() < key)
            {
                current = current->getNext();
            }
        
        ptr->setNext(current->getNext());
        current->setNext(ptr);       

        if (last == current) last = ptr;
    }
    ++count;
}