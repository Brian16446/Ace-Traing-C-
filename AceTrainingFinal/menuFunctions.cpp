#include <iostream>
#include <vector>
#include "Course.h"
#include "Student.h"
#include <string.h>
#include <string>

#ifndef SCLINKEDLIST_H
#define SCLINKEDLIST_H
#include "SCLinkedList.h"
#endif

using namespace std;

void loadCoursesFromFile(vector<Course> &c);
void displayCourses(vector<Course> &c);

int searchCourses(vector<Course> &c, string courseInput);

void loadStudentsFromFile(vector<student> &s);
void displayStudents(vector<student> &s);
char convertToGrade(int mark);

//int searchStudents(vector<student> &s, string studentInput);

void displayStudentMenu();
void displayCourseMenu();

vector <student*> student::studentReferences;
vector <Course*> Course::courseReferences;

int studentID;
string stringID;
string studentName;
string stuSurname;
string courseIDstring;
int courseID;
string courseName;
string removestudentID;
int removestudentIDint;
int nodenumber;
SCLinkedList * studentoncourse = new SCLinkedList;

void displayMainMenu() {
	
	int choice = 0;

	while (choice == 0) {
		cout << "\n" << endl;
		cout << "=======================================" << endl;
		cout << "=            Main Menu                =" << endl;
		cout << "=          ------------               =" << endl;
		cout << "=       1. Student Options            =" << endl;
		cout << "=       2. Course Options             =" << endl;
		cout << "=       3. Enrol Student onto Course  =" << endl;
		cout << "=       4. Exit                       =" << endl;
		cout << "=======================================" << endl;
		// Might need to add a assessments option to this. 

		cout << "Menu Choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			displayStudentMenu();
			break;
		case 2:
			displayCourseMenu();
			break;
		case 3:
			cout << "Please enter the student ID of the student you wish to enrol: " << endl;
			cin.ignore();
			getline(cin, stringID);
			studentID = stoi(stringID);
			cout << "Please enter the students forename: " << endl;
			getline(cin, studentName);
			cout << "Please enter the students surname: " << endl;
			getline(cin, stuSurname);

			cout << "Please enter the course ID you wish to enrol them onto" << endl;
			getline(cin, courseIDstring);
			courseID = stoi(courseIDstring);
			
			studentoncourse->createNode(studentID, studentName, stuSurname, courseID);
			cout << "Student enrolled onto course below: " << endl;
			studentoncourse->display();

			displayMainMenu();
			break;
		case 4:
			exit(EXIT_SUCCESS);
		default:
			cout << "Please select an option 1-4" << endl;
			choice = 0;
		}
	}
}

void displayBasicMenu() {
	cout << std::string(41, '=') << endl;
	cout << "=         1. Return to Student Menu     =" << endl;
	cout << "=         2. Return to Main Menu        =" << endl;
	cout << "=         3. Exit                       = " << endl;
	cout << std::string(41, '=') << endl;
	int choice2;

	cin >> choice2;

	switch (choice2) {
	case 1:
		displayCourseMenu();
	case 2:
		displayMainMenu();
	case 3:
		exit(EXIT_SUCCESS);
	}
}

void displayBasicCourseMenu() {
	cout << std::string(41, '=') << endl;
	cout << "=         1. Return to Course Menu     =" << endl;
	cout << "=         2. Return to Main Menu        =" << endl;
	cout << "=         3. Exit                       = " << endl;
	cout << std::string(41, '=') << endl;
	int choice2;

	cin >> choice2;

	switch (choice2) {
	case 1:
		displayCourseMenu();
	case 2:
		displayMainMenu();
	case 3:
		exit(EXIT_SUCCESS);
	}
}


void displayStudentMenu() {
	int choice = 0;
	int studentID;

	while (choice == 0) {
		cout << "\n" << endl;
		cout << "=======================================" << endl;
		cout << "=            Student Menu             =" << endl;
		cout << "=          ----------------           =" << endl;
		cout << "=  1. Display students                =" << endl;
		cout << "=  2. Search for a student            =" << endl;
		cout << "=  3. Create new student              =" << endl;
		cout << "=  4. Delete a student                =" << endl;
		cout << "=  5. Withdraw student from course    =" << endl;
		cout << "=  6. Create Transcript for Student   =" << endl;
		cout << "=  7. Edit Student                    =" << endl;
		cout << "=  8. Return to Main Menu             =" << endl;
		cout << "=  9. Exit                            =" << endl;
		cout << "=======================================" << endl;

		cout << "Menu Choice ";
		cin >> choice;
		switch (choice) {
		case 1: {
			vector<student> s;
			loadStudentsFromFile(s);
			displayStudents(s);

			displayBasicMenu();
		}
			break;
		case 2: {
			vector<student> s;
			loadStudentsFromFile(s);
			student::searchStudents();

			displayBasicMenu();

		}
			break;
		case 3: {
			vector<student> stu;
			loadStudentsFromFile(stu);
			student *s = new student();
			s->createStudent();
			displayBasicMenu();
		}
			break;
		case 4: {
			cout << "Enter the ID of the student you wish to delete: " << endl;
			int idToDelete;
			cin >> idToDelete;

			vector<student> s;
			loadStudentsFromFile(s);
			s[idToDelete].deleteStudent(idToDelete);
			displayBasicMenu();

		}
			break;
		case 5: {
			vector<student> s;
			loadStudentsFromFile(s);
			cout << "Please enter the studentID of the student you wish to remove from their course: " << endl;
			cin.ignore();
			getline(cin, removestudentID);
			removestudentIDint = stoi(removestudentID);
			nodenumber = studentoncourse->searchNodeNumber(studentoncourse->head, removestudentIDint);
			cout << nodenumber;
			studentoncourse->deleteNodeAt(nodenumber);
			cout << "Student Removed from course." << endl;
			studentoncourse->display();
		}
			break;
		case 6: {
			vector<student> s;
			loadStudentsFromFile(s);
			vector<Course> c;
			loadCoursesFromFile(c);

			int searchStudent = student::searchStudents();
			//cout << "studentID = " << searchStudent;
			searchStudent--;
			int cID = s[searchStudent].getCourseID();
			cID--;
			//cout << "courseID = " << cID;	
			c[cID].displayCourse();
			
	

			cID++;
			Course * ca = new Course();
			vector<string> assessments;
			assessments = ca->storeCourseAssessments(cID);

			vector<string> weightings;
			vector<string> assessmentNames;
			char grade;

			for (size_t i = 1; i <= assessments.size()-1; i+=2) {
				weightings.push_back(assessments[i]);
			}

			for (size_t i = 0; i <= assessments.size() - 2; i += 2) {
				assessmentNames.push_back(assessments[i]);
			}

			for (size_t i = 0; i < assessments.size()/2; i++) {
				cout << std::string(110, '=') << endl;
				cout << "Assessment " << i+1 << ":";
				cout << assessmentNames[i] << endl;
				cout << "Weighting:   ";
				cout << weightings[i] << endl;
				int marks = s[searchStudent].assessmentMarks[i];
				cout << "Marks:        " << marks << endl;
				grade = convertToGrade(marks);
				cout << "Grade:        " << grade;
				cout << endl;
			}
			cout << std::string(110, '=') << endl;


		}
			break;
		case 7: {
			vector<student> s;
			loadStudentsFromFile(s);
			// edit grade function call
			student::editStudent();
			displayBasicMenu();
		}
			break;
		case 8:
			displayMainMenu();
			break;
		case 9:
			exit(EXIT_SUCCESS);
		default:
			cout << "Please select an option 1-9" << endl;
			choice = 0;
		}
	}

	// THE STUDENT ID WILL NOW BE WITHIN THIS FUNCTION.. THEN NEED TO RUN DESIRED FUNCTION CALL WITHIN SWITCH. 


}

void displayCourseMenu() {

	int choice = 0;
	while (choice == 0) {
		cout << "\n" << endl;
		cout << "=========================================" << endl;
		cout << "=            Course Menu                =" << endl;
		cout << "=          ---------------              =" << endl;
		cout << "=       1. View all Courses             =" << endl;
		cout << "=       2. Search for Course            =" << endl;
		cout << "=       3. Create New Course            =" << endl;
		cout << "=       4. View weighting for a course  =" << endl;
		cout << "=       5. Ammend a course              =" << endl;
		cout << "=       6. Delete a course              =" << endl;
		cout << "=       7. Return to Main Menu          =" << endl;
		cout << "=       8. Exit                         =" << endl;
		cout << "=========================================" << endl;


		cout << "Menu Choice \n";
		cin >> choice;
		switch (choice) {
		case 1: {
			//displayCourses();
			vector<Course> c;
			loadCoursesFromFile(c);
			displayCourses(c);
			displayBasicCourseMenu();
		}
			break;
		case 2: {
			string courseInput;
			cout << "Enter the name of the course you want to search for (case sensitive)" << endl;
			cin.ignore();
			getline(cin, courseInput);

			vector<Course> c;
			loadCoursesFromFile(c);
			searchCourses(c, courseInput);
			displayBasicCourseMenu();

		}
			break;
		case 3: {
			//askForCourse();
			Course * c = new Course();
			c->createNewCourse();
			//c->displayCourseName();
			//write the c object to a file
			displayBasicCourseMenu();
		}
			break;
		case 4: {
			vector<Course> c;
			loadCoursesFromFile(c);
			string courseIDstring;
			int courseID;
			Course * ca = new Course();
			cout << "Please Enter the ID of the course you wish to view the weightings for: " << endl;
			cin.ignore();
			getline(cin, courseIDstring);
			courseID = stoi(courseIDstring);
			ca->displayCourseAssessments(courseID);
			displayBasicCourseMenu();
		}
			break;
		case 5: {
			vector<Course> c;
			loadCoursesFromFile(c);
			Course::editCourse();
			displayBasicCourseMenu();
		}
			break;
		case 6: {
			cout << "Enter the ID of the course you wish to delete: " << endl;
			int idToDelete;
			cin >> idToDelete;
			vector<Course> c;
			loadCoursesFromFile(c);
			c[idToDelete].deleteCourse(idToDelete);
			displayBasicCourseMenu();

		}
			break;
		case 7:
			displayMainMenu();
			break;
		case 8:
			exit(EXIT_SUCCESS);
		default:
			cout << "Please select an option 1-8" << endl;
			choice = 0;
		}
	}
}