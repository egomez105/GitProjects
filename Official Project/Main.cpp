#include "CourseList.h"
#include "TestingCases.h"
#include "Interface.h"

#include <iostream>
#include <string>
using namespace std;

int main()
{
	/********************************************************
	*	TESTING database
	********************************************************/
	CourseList courseList;
	createCourseList(courseList);
	displayMenu();
	processChoice(courseList);

	cout << "\n";
	return 0;

}