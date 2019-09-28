#include "Course.h"
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <stdio.h>
#include <locale>

#ifndef DATE_CPP
#define DATE_CPP
#include "date.cpp"
#endif // !DATE_CPP
#ifndef ASSESSMENT_H
#define ASSESSMENT_H
#include "Assessment.h"
#endif
#ifndef COURSEASSESSMENTLIST_H
#define COURSEASSESSMENTLIST_H
#include "CourseAssessmentList.h"
#endif
#ifndef CALINKEDLIST_CPP
#define CALINKED_CPP
#include "CourseAssessmentLinkedList.cpp"
#endif

using namespace std;

Assessment* assessment = new Assessment();
CourseAssessmentList* CAList = new CourseAssessmentList();

Course::Course()
{
	numCourses++;
}


Course::~Course()
{
}

void Course::createNewCourse() {
	courseID = numCourses;
	courseName = setCourseName();
	courseType = setCourseType();
	cout << "Enter the course start date: " << endl;
	courseStartDate = setCourseDate();
	cout << "Enter the course end date: " << endl;
	courseEndDate = setCourseDate();
	modules = setCourseModules();

	Assessment* assessment = new Assessment();
	assessment->linkedList();
	CourseAssessmentList* CAList = new CourseAssessmentList(); //NEED TO FIGURE OUT A WAY TO GET THE INFORMATION FROM THE ASSESS LL TO MAKE A NEW LL
	CANode * CAhead = new CANode;
	Node * Ahead = new Node;
	Ahead = assessment->temphead;
	Node * Atemp = new Node;
	Atemp = Ahead;
	while (Atemp != NULL)
	{
		CAList->createNode(courseID, courseName, Atemp->assessmentName, Atemp->assessmentWeight, Atemp->deadlineDate);
		Atemp = Atemp->link;

	}

	CAList->display();

	addToFile();
}

string Course::setCourseName() {

	cout << "Please enter the name of your course: ";
	cin >> courseName;
	return courseName;
}

string Course::setProgrammeName() {

	cout << "Please enter the name of your course: ";
	cin >> programmeName;
	return programmeName;
}


string Course::setCourseType() {
	cout << "Enter the level of the course C/H/I: ";
	string level = "";
	// need to ensure input is clean
	cin >> level;

	for (size_t i = 0; i < level.length(); i++) {
		level[0] = tolower(level[i]);
	}

	bool inputInvalid = 1;

	while (inputInvalid == 1) {
		cout << level;
		if (level != "c") {
			if (level != "h") {
				if (level != "i") {
					cout << "Please enter a valid level: C/H/I" << endl;
					level = "";
					cin >> level;

				}
				else {
					inputInvalid = 0;
				}
			}
			else {
				inputInvalid = 0;
			}
		}
		else {
			inputInvalid = 0;
		}
	}
	
	courseType = " Level " + level;
	cout << courseType << endl;
	return courseType;


}

Date Course::setCourseDate() {
	Date courseDate;

	string line;
	cin >> line;

	stringstream ss(line);
	string token;
	char delim = '/';
	vector<string> arr;
	vector<int> nums;


	while (std::getline(ss, token, delim)) {
		arr.push_back(token);
	}

	for (int i = 0; i < 3; i++) {
		int num = atoi(arr[i].c_str());
		nums.push_back(num);
	}

	courseDate.dd = nums[0];
	courseDate.mm = nums[1];
	courseDate.yyyy = nums[2];

	return courseDate;
}

Date Course::setCourseStartDate() {
	cout << "Enter the Course Start Date: " << endl;
	courseStartDate = setCourseDate();
	return courseStartDate;
}

Date Course::setCourseEndDate() {
	cout << "Enter the Course End Date: " << endl;
	courseEndDate = setCourseDate();
	return courseEndDate;
}

vector<string> Course::setCourseModules() {
	
	vector<string> arr;
	string module; 
	for (int i = 0; i < 4; i++) {
		cout << "Enter the name of module 1: " << endl;
		cin >> module;
		arr.push_back(module);
	}

	return arr;
}

void Course::ammendCourse() {
	std::ifstream file;
	file.open("Courses.txt");

	// maybe create new temp file here or at the end
	std::ofstream newFile("temp.txt");

	char c;
	int lineNum = 1;

	//string coursename = getProgrammeName();

	int n = 0;
	while (file.get(c)) {
		if (c == '\n') {
			lineNum++;
		}
		if (lineNum != courseID) {
			newFile << c;
		}
		else {
			if (n == 0) {
				if (courseID != 1) {
					newFile << endl;
				}
				newFile << courseID << ", ";
				newFile << programmeName << ", ";
				newFile << courseType << ", ";
				int d = courseStartDate.dd;
				int m = courseStartDate.mm;
				int y = courseStartDate.yyyy;
				newFile << d << "/" << m << "/" << y << ", ";
				d = courseEndDate.dd;
				m = courseEndDate.mm;
				y = courseEndDate.yyyy;
				newFile << d << "/" << m << "/" << y << ", ";
				for (size_t i = 0; i < modules.size(); i++) {
					newFile << modules[i];
					if (i != modules.size()-1) {
						newFile << " - ";
					}
					else {
						newFile << ", ";
					}
				}
				newFile << assessment1;
				// DONT FORGET TO ADD THE REST OF THESE
			}
			n++;

			//call add to file
		}
	}


	// now write this file 
	int result;
	file.close();
	newFile.close();

	if (remove("Courses.txt") != 0) {
		cout << "error deleting file" << endl;
	}
	else {
		cout << "Record Updated" << endl;
	}


	result = std::rename("temp.txt", "Courses.txt");

}

void Course::deleteCourse(int courseID){
	std::ifstream file;
	file.open("Courses.txt");

	// maybe create new temp file here or at the end
	std::ofstream newFile("temp.txt");
	
	char c;
	int lineNum = 1;
	int n = 0;

	while (file.get(c)) {
		if (c == '\n') {
			lineNum++;
		}
		if (lineNum != courseID) {
			newFile << c;
		}
		else {
			if (n == 0) {
				newFile << endl;
				newFile << lineNum;
				n++;
			}
		}
	}
	// now write this file 
	int result;	
	file.close();
	newFile.close();

	if (remove("Courses.txt") != 0) {
		cout << "error deleting file";
	}
	else {
		cout << "Record Deleted" << endl;
	}

	
	result = std::rename("temp.txt", "Courses.txt");

	
}

//Date Course::setCourseStartDate() {
	
//}

void Course::createNewCourseFromFile(vector<string> section) {
	string tempCourseID = section[0];
	courseID = stoi(tempCourseID);
	programmeName = section[1];
	courseType = section[2];
	courseStartDate = setCourseDate(section[3]);
	courseEndDate = setCourseDate(section[4]);
	modules = setCourseModules(section[5]);
	assessment1 = section[6];
	weight1 = section[7];
	deadline1 = setCourseDate(section[8]);
	assessment2 = section[9];
	weight2 = section[10];
	deadline2 = setCourseDate(section[11]);
	assessment3 = section[12];
	weight3 = section[13];
	deadline3 = setCourseDate(section[14]);
	assessment4 = section[15];
	weight4 = section[16];
	deadline4 = setCourseDate(section[17]);
	CAList->createNode(courseID, programmeName, assessment1, weight1, deadline1);
	CAList->createNode(courseID, programmeName, assessment2, weight2, deadline2);
	CAList->createNode(courseID, programmeName, assessment3, weight3, deadline3);
	CAList->createNode(courseID, programmeName, assessment4, weight4, deadline4);
}

void Course::addToFile() {
	std::ofstream file;
	file.open("Courses.txt", std::ios::app);
	
	file << courseID << ',';
	file << courseName << ',';
	file << courseType << ',';
	file << ' ' << courseStartDate.dd << '/' << courseStartDate.mm << '/' << courseStartDate.yyyy << ',';
	file << ' ' << courseEndDate.dd << '/' << courseEndDate.mm << '/' << courseEndDate.yyyy << ',';
	file << ' ';
	for (size_t i = 0; i < modules.size(); i++) {
		if (i == modules.size() - 1) {
			file << modules[i] << ',' << endl;
		}
		else {
			file << modules[i] << ' ' << '-' << ' ';
		}
	}

	Course * cl = new Course();
	vector<string> assessments;
	assessments = cl->storeCourseAssessments(courseID);

	for (size_t i = 0; i < assessments.size(); i += 2) {
		file << assessments[i] << "," << assessments[i + 1];
	}


}

// creating course from file functions (will be different from the create course function as wont ask for inputs
// This one has been overloaded
Date Course::setCourseDate(string line) {

	Date courseDate;

	stringstream ss(line);
	string token;
	char delim = '/';
	vector<string> arr;
	vector<int> nums;


	while (std::getline(ss, token, delim)) {
		arr.push_back(token);
	}

	for (int i = 0; i < 3; i++) {
		int num = atoi(arr[i].c_str());
		nums.push_back(num);
	}

	courseDate.dd = nums[0];
	courseDate.mm = nums[1];
	courseDate.yyyy = nums[2];

	return courseDate;
}

vector<string> Course::setCourseModules(string line) {
	stringstream ss(line);
	string token;
	char delim = '-';
	vector<string> arr;

	while (std::getline(ss, token, delim)) {
		arr.push_back(token);
	}

	return arr;
}

// PUBLIC DISPLAY FUNCTIONS MIGHT NOT NEED THESE AS CAN USE GETTERS INSTEAD

void Course::displayCourse() {
	cout << std::string(110, '=') << endl;
	displayCourseID();
	cout << " || ";
	displayProgrammeName();
	cout << " || ";
	displayCourseType();
	cout << " || ";
	displayCourseStartDate();
	cout << " || ";
	displayCourseEndDate();
	cout << " || ";
	displayModules();
	cout << endl;
	cout << std::string(110, '=') << endl;
}

void Course::displayCourseID() {
	cout << courseID;
}
void Course::displayProgrammeName() {
	cout << programmeName;
}

void Course::displayCourseName() {
	cout << courseName;
}

void Course::displayCourseType() {
	cout << courseType;
}

void Course::displayCourseStartDate() {
	cout << courseStartDate.dd;
	cout << "/";
	cout << courseStartDate.mm;
	cout << "/";
	cout << courseStartDate.yyyy;
}

void Course::displayCourseEndDate() {
	cout << courseEndDate.dd;
	cout << "/";
	cout << courseEndDate.mm;
	cout << "/";
	cout << courseEndDate.yyyy;
}

void Course::displayModules() {
	for (size_t i = 0; i < modules.size(); i++) {
		cout << modules[i] << "-";
	}
}

void Course::displayCourseAssessments(int courseID)
{
	int noOfInstances;
	int startPoint;

	noOfInstances = CAList->searchNumberOfInstances(CAList->head, courseID);
	startPoint = CAList->searchNodeNumber(CAList->head, courseID);
	CAList->iteratingDisplay(noOfInstances, startPoint);
}

vector<string> Course::storeCourseAssessments(int courseID)
{
	int noOfInstances;
	int startPoint;

	vector<string> ass;
	noOfInstances = CAList->searchNumberOfInstances(CAList->head, courseID);
	startPoint = CAList->searchNodeNumber(CAList->head, courseID);
	ass = CAList->storeAssessments(noOfInstances, startPoint);
	return ass;
}


// PUBLIC GETTERS
string Course::getProgrammeName() {
	return programmeName;
}

string Course::getCourseType() {
	return courseType;
}

int Course::getCourseID() {
	return courseID;
}


void Course::editCourse()
{
	locale loc; //Include locale
	int choiceCourse;
	Course* chosenCourse;
	string initChoice;
	string splitChoice[50];
	int choice;
	string choiceEnd;
	bool choiceCheck = 0;

	cout << "Enter the ID of course would you like to edit " << endl;
	cin.ignore(); //This must be called if setMark is called as it uses cin not getline
	cin >> choiceCourse;

	while (choiceCheck == 0)
	{
		for (int i = 0; i < numCourses; i++)
		{
			if (choiceCourse == courseReferences[i]->courseID)
			{
				cout << choiceCourse << endl;
				cout << "You are editing: ";
				chosenCourse = courseReferences[i];
				chosenCourse->displayProgrammeName();
				cout << endl;
				choiceCheck = 1;
			}
		}
		if (choiceCheck == 0)
		{

			cout << choiceCourse << endl;
			cout << "No Match" << endl;
			cout << "Please enter a valid Course ID:" << endl;
			cin >> choiceCourse;
		}
	}

	cin.ignore();
	choiceCheck = 0;
	while (choiceCheck == 0)
	{
		cout << std::string(41, '=') << endl;
		cout << "=       What do you want to edit?       =" << endl;
		cout << "=       1: Course Name                  =" << endl;
		cout << "=       2: Course Level                 =" << endl;
		cout << "=       3: Course Start Date            =" << endl;
		cout << "=       4: Course End Date              =" << endl;
		cout << "=       5: Exit                         =" << endl;
		cout << std::string(41, '=') << endl;
		cin >> initChoice;
		choice = stoi(initChoice);

		if (choice == 1)
		{
			chosenCourse->setProgrammeName();
			choiceCheck = 1;
		}
		else if (choice == 2) {
			chosenCourse->setCourseType();
			choiceCheck = 1;
		}
		else if (choice == 3) {
			chosenCourse->setCourseStartDate();
			choiceCheck = 1;
		}
		else if (choice == 4) {
			chosenCourse->setCourseEndDate();
			choiceCheck = 1;
		}
		else if (choice == 5) {
			exit(EXIT_SUCCESS);
		}
		else
		{
			cout << "No Match" << endl;
		}
	}

	chosenCourse->ammendCourse();
}