#include "Interface.h"

#include <iostream>
using namespace std;

// Helper functions
void displayMenu()
{
	cout << "**************************************************************\n"
		<< "                          MAIN MENU\n"
		<< "**************************************************************\n";
	cout << "\nSelect one of the following:\n\n"
		<< "    1: Search course\n"
		<< "    2: Add course\n"
		<< "    3: Delete course\n"
		<< "    4: Display all courses\n"
		<< "    5: Create schedule\n"
		<< "    6: To exit\n";
}

void displaySubMenu(int n)
{
	string title;
	if (n == 1)
		title = "Search Course\n";
	else if (n == 2)
		title = "Add Course\n";
	else if (n == 3)
		title = "Delete Course\n";
	else if (n == 4)
		title = "All Courses\n";
	else if (n == 5)
		title = "Create Schedule\n";
	else if (n == 6)
		title = "Goodbye\n";

	cout << "\n**************************************************************\n"
		<< "                       " << title
		<< "**************************************************************\n";
}

void displayACourseList(const CourseList& list, string& output, string header = "")
{
	list.retrieveAllCourses(output);
	cout << "\n" << header << "---------------------------------\n" 
		<< output << "---------------------------------\n";
}

void continueOrNext(int& step, bool& val)
{
	while (val)
	{
		cout << "\nY - to continue adding courses.\n"
			<< "N - " << (step == 0 ? "begin creating your schedule."
				: "to view summary of schedule.") << "\n" << "(Y/N): ";

		char response;
		cin >> response;

		if (!cin.fail())
		{
			if (response == 'n' || response == 'N')
			{
				++step;
				val = false;
			}
			else if (response == 'y' || response == 'Y')
			{
				val = false;
			}
		}
		else
		{
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
}

void continueOrExit(int& selection, bool& running)
{
	bool validate = true;
	while (validate)
	{

		cout << "\nY - for main menu\n"
			<< "N - to exit the app\n" <<
			"(Y/N): ";

		char response;
		cin >> response;

		if (!cin.fail())
		{
			if (response == 'n' || response == 'N')
			{
				validate = false;
				running = false;
				selection = 0;
			}
			else if (response == 'y' || response == 'Y')
			{
				selection = 0;
				validate = false;
			}
		}
		else
		{
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
}

void processChoice(CourseList& courseList)
{
	if (courseList.isEmpty())
	{
		cerr << "\nWe're sorry, the database is currently empty\n"
			<< "Please try again later.\n";
	}
	else
	{
		// Initial prompt
		cout << "\nTo select, enter a number from 1 to 6: ";
		int initialSelection;
		cin >> initialSelection;

		// #5 - CREATE SCHEDULE variables
		CourseList completedCourses;
		CourseList schedule;
		bool loadSchedule = false;
		int totalUnits = 0;
		int step = 0;

		// re-used throughout
		Course searchedCourse;
		string allCourses;
		bool loadSubMenu = false;

		bool run = true;
		while (run)
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << "Invalid selection, please try again.\n";
			}
			switch (initialSelection)
			{
				case 0: // #0 - MAIN MENU
				
					displayMenu();
					cout << "\nTo select, enter a number from 1 to 6: ";
					cin >> initialSelection;

					if (cin.fail())
					{
						cin.clear();
						cin.ignore();
						cout << "Invalid selection, please try again: ";
						cin >> initialSelection;
					}
					break;

				case 1: // #1 - SEARCH COURSE
				
					if (!loadSubMenu)
					{
						displaySubMenu(initialSelection);
						loadSubMenu = true;
					}
			
					while (initialSelection == 1)
					{
						cout << "\nEnter course number: ";
						int courseNumber;
						cin >> courseNumber;

						// INVALID INPUT 
						if (cin.fail())
						{
							cin.clear();
							cin.ignore(1000, '\n');
							cout << "Invalid selection, please try again\n";
						}
						// COURSE NOT FOUND
						else if (!courseList.searchCourse(courseNumber, searchedCourse))
						{
							cout << "Course not found, please try again.\n";
						}
						else
						{
							// SEARCH RESULTS
							cout << "\nSearch results\n---------------------------------\n"
								<< searchedCourse.getPrefix() << searchedCourse.getCourseNumber()
								<< "\nName: " << searchedCourse.getCourseName()
								<< "\nUnits: " << searchedCourse.getCourseUnits()
								<< "\nPrerequsite courses: ";
							for (const auto& c : searchedCourse.getCoursePrereqs())
								cout << c << " ";
							cout << "\n---------------------------------\n";

							// CONTINUE OR EXIT
							continueOrExit(initialSelection, run);
						}
						loadSubMenu = false;
					}
					break;

				case 2: // #2 - ADD COURSE
				
					if (!loadSubMenu)
					{
						displaySubMenu(initialSelection);
						loadSubMenu = true;
					}
					cout << "To begin the process of adding a course,"
						<< "\nplease contact the Cirriculum Committee.\n";

					// CONTINUE OR EXIT
					continueOrExit(initialSelection, run);
					loadSubMenu = false;
					break;
			
				case 3: // #3 - DELETE COURSE
				
					if (!loadSubMenu)
					{
						displaySubMenu(initialSelection);
						loadSubMenu = true;
					}

					cout << "\nWhich course do you want to delete?\n- Course number: ";
					int num;
					cin >> num;

					while (initialSelection == 3)
					{
						// INVALID INPUT
						if (cin.fail())
						{
							cin.clear();
							cin.ignore();
							cout << "Invalid selection, please try again";
							break;
						}
						// COURSE NOT FOUND
						if (!courseList.searchCourse(num, searchedCourse))
						{
							cout << "\nCourse not found, please try again.\n";
							break;
						}
						else
						{
							// CONFIRM DELETE
							cout << "\nAre you sure you want to delete this course?\n\n" << "- "
								<< searchedCourse.getPrefix() << searchedCourse.getCourseNumber()
								<< " " << searchedCourse.getCourseName() << "\n\n" << "Confirm (Y/N): ";

							string confirm;
							cin >> confirm;

							if (confirm == "y" || confirm == "Y")
							{
								courseList.deleteCourse(searchedCourse.getCourseNumber());
								cout << "\nCourse was successfully deleted.\n";

							}
							// CONTINUE OR EXIT
							continueOrExit(initialSelection, run);
						}
					}
					loadSubMenu = false;
					break;
			
				case 4: // #4 - VIEW ALL COURSES
				
					if (!loadSubMenu)
					{
						displaySubMenu(initialSelection);
						loadSubMenu = true;
					}

					displayACourseList(courseList, allCourses);

					// CONTINUE OR EXIT
					continueOrExit(initialSelection, run);
					loadSubMenu = false;
					break;
			
				case 5: // #5 - CREATE SCHEDULE

					if (!loadSubMenu)
					{
						displaySubMenu(initialSelection);
						loadSubMenu = true;
					}
				
					// Initialize component variables
					if (!loadSchedule)
					{
						completedCourses.clearList();
						schedule.clearList();
						loadSchedule = true;
						totalUnits = 0;
						step = 0;
					}

					// create schedule - step one (add completed courses)
					if (step == 0)
					{
						// prompt & show completed courses list
						cout << "\nEnter the course number for any course(s) that you have completed.\n";
						
						// loop to add completed courses
						while (step == 0)
						{
							cout << "\nYou have " << completedCourses.getNumberOfCourses()
								<< " completed courses.";

							displayACourseList(completedCourses, allCourses);

							cout << "Course number: ";
							int courseNumber;
							cin >> courseNumber;

							// INVALID INPUT
							if (cin.fail())
							{
								cin.clear();
								cin.ignore(1000, '\n');
								cout << "Invalid input, please try again: ";
							}
							// COURSE NOT FOUND
							else if (!courseList.searchCourse(courseNumber, searchedCourse))
							{
								cout << "\nERROR: Course not found, please try again.\n";
								
								// display all courses for reference
								displayACourseList(courseList, allCourses, "Reference: All CS courses\n");
							}
							else
							{
								// ADD COURSE
								completedCourses.addCourse(searchedCourse);

								// DISPLAY COMPLETED COURSES LIST
								cout << "\nSuccess! You added " << searchedCourse.getCourseName()
								<< " to your completed courses.\n";

								// INPUT VALIDATION
								bool validate = true;
								continueOrNext(step, validate);
							}
						}
					}

					// create schedule - step two (add courses to schedule)
					else if (step == 1)
					{
						// add courses to schedule loop
						while (step == 1)
						{
							// create schedule header w/ count
							cout << "\nAdd up to 4 courses to your schedule.\n"
								<< "\nYour schedule: " << schedule.getNumberOfCourses()
								<< "/4";
							
							// display schedule courseList
							displayACourseList(schedule, allCourses);
							
							cout << "Course number: ";
							int courseNumber;
							cin >> courseNumber;

							// INVALID INPUT
							if (cin.fail())
							{
								cin.clear();
								cin.ignore(1000, '\n');
								cout << "Invalid input, please try again: ";
							}
							// COURSE NOT FOUND
							else if (!courseList.searchCourse(courseNumber, searchedCourse))
							{
								cout << "\nERROR: Course not found, please try again.\n";
							
								// display all courses for reference
								displayACourseList(courseList, allCourses, "Reference: All CS courses\n");
							}
							else
							{
								// determine if prereqs have been met
								set<int> tempPrereqs = searchedCourse.getCoursePrereqs();
								bool eligible = true;

								for (const auto& p : tempPrereqs)
								{
									if (!completedCourses.searchCourse(p))
										eligible = false;
								}
								// COURSE ALREADY COMPLETED
								if (completedCourses.searchCourse(searchedCourse.getCourseNumber()))
								{
									cout << "\nYou have already completed this course: "
										<< searchedCourse.getCourseName() << "\n";
								}
								// ALREADY IN SCHEDULE
								else if (schedule.searchCourse(searchedCourse.getCourseNumber()))
								{
									cout << searchedCourse.getCourseName() << " is already in your schedule.\n";
								}
								// UNMET PREREQS
								else if (!eligible)
								{
									cout << "\nCourse: \"" << searchedCourse.getPrefix()
										<< searchedCourse.getCourseNumber()	<< " " << searchedCourse.getCourseName()
										<< "\", has one or more prereqs that you have not completed.\n"
										<< "\nPrerequisite course(s):\n";

									string courseName;
									for (const auto& p : tempPrereqs)
									{
										courseList.searchCourse(p, courseName);
										cout << "   " << searchedCourse.getPrefix() << p << " "
											<< courseName << "\n";
									}
								}
								// ADD COURSE TO SCHEDULE
								else if (eligible)
								{
									schedule.addCourse(searchedCourse);
									totalUnits += searchedCourse.getCourseUnits();

									cout << "\nSuccess! You added " << searchedCourse.getCourseName()
										<< " to your schedule.\n";
								}
								// INPUT VALIDATION
								if (schedule.getNumberOfCourses() != 4)
								{
									bool validate = true;
									continueOrNext(step, validate);
								}
								else
									step = 2;

								// schedule summary
								if (step == 2)
								{
									// schedule summary output
									cout << "\n**************************************************************\n"
										<< "\nYour schedule " << schedule.getNumberOfCourses() << "/4";
									
									displayACourseList(schedule, allCourses);		
									cout << "\nTotal units: " << totalUnits << "\n";

									// INPUT VALIDATION
									bool validate = true;
									continueOrExit(initialSelection, run);
								
									// reset control variables
									loadSchedule = false;
									loadSubMenu = false;
								}
							}
						}
					}
					break;
			
				case 6: // #6 - EXIT
					run = false;
					break;
			
				default: // DEFAULT - Menu selection prompt
					cout << "\nTo select, enter a number from 1 to 6: ";
					cin >> initialSelection;
					break;
			}
		}
		displaySubMenu(6);
		cout << "\nThank you for visiting the CS course application.\n"
			<< "Come back soon!\n\n";
	}
}