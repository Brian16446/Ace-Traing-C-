#include "Student.h"
#include <iostream>
#include <string>
#include <locale>
#include <sstream>
#include <fstream>

#ifndef SCLINKEDLIST_H
#define SCLINKEDLIST_H
#include "SCLinkedList.h"
#endif


using namespace std;
void displayStudentMenu();
SCLinkedList* studentCourse = new SCLinkedList;

student::student()
{
	numOfStudents++;
}

student::~student()
{
}

int student::getID() {
	return studentID;
}

string student::getForename() {
	return forename;
}

string student::getSurname() {
	return surname;
}

int student::getCourseID() {
	return courseID;
}

string student::getCourseName()
{
	return courseName;
}

string student::getEmail() {
	return email;
}

Date student::getDOB() {
	return DOB;

}

void student::displayID() {
	cout << studentID;
}

void student::displayForename()
{
	cout << forename;
}

void student::displaySurname()
{
	cout << surname;
}

void student::displayEmail() {
	cout << email;
}

void student::displayDOB() {
	cout << DOB.dd;
	cout << "/";
	cout << DOB.mm;
	cout << "/";
	cout << DOB.yyyy;
}

void student::displayStudent() {
	cout << std::string(110, '=') << endl;
	displayID();
	cout << " || ";
	displayForename();
	cout << " || ";
	displaySurname();
	cout << " || ";
	displayEmail();
	cout << " || ";
	displayDOB();
	cout << " || ";
	cout << "Status: " << isRegistered;
	cout << endl;
	cout << std::string(110, '=') << endl;
}


void student::createStudent()
{
	studentID = numOfStudents;
	forename = setForename();
	surname = setSurname();
	email = setEmail();
	DOB = setDOB();
	courseID = setCourseID();
	
	for (int i = 0; i < 4; i++) {
		marks[i] = setMark(i);
		//assessmentMarks.push_back(setMark(i));
	}

	isRegistered = setIsRegistered();


	addToFile();
	//setMark();
	//setGrade();
	
}
string student::setForename()
{
	cout << "Please enter the student's forename: " << endl;
	cin >> forename;
	//cout << "The student's forename is set to " << forename << "\n";
	//students.push_back(forename);
	return forename;

}

string student::setSurname()
{
	cout << "Please enter the student's surname: " << endl;
	cin >> surname;
	cout << "The student's surname is set to " << surname << endl;
	return surname;
}



string student::setEmail()
{
	cout << "Please enter the student's email: " << endl;
	cin >> email;
	cout << "The student's email is set to " << email << endl;
	return email;
}

int student::setCourseID()
{
	int course;
	cout << "Please enter the ID of the course you wish to enrol the student on: " << endl;
	cin >> course;
	return course;
}

int student::setMark(int i)
{
	i++;
	int tempMark;
	cout << "Please enter the student's mark for assessment " << i << endl;
	cin >> tempMark;
	return tempMark;
}

string student::setIsRegistered() {
	cout << "Enter the Students registration status: " << endl;
	cin >> isRegistered;
	return isRegistered;
}

void student::createNewStudentFromFile(vector<string> section) {
	// Method gets called on each object in loop. 
	studentID = numOfStudents;
	forename = section[1];
	surname = section[2];
	email = section[3];
	DOB = setDOB(section[4]);
	courseID = stoi(section[5]);

	assessmentMark1 = stoi(section[6]);
	assessmentMarks.push_back(assessmentMark1);
	assessmentMark2 = stoi(section[7]);
	assessmentMarks.push_back(assessmentMark2);
	assessmentMark3 = stoi(section[8]);
	assessmentMarks.push_back(assessmentMark3);
	assessmentMark4 = stoi(section[9]);
	assessmentMarks.push_back(assessmentMark4);
	isRegistered = section[10];

	studentCourse->createNode(studentID, forename, surname, courseID);

}

Date student::setDOB() {
	Date dateOfBirth;

	string line;

	cout << "Enter the students Date of Birth" << endl;
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

	dateOfBirth.dd = nums[0];
	dateOfBirth.mm = nums[1];
	dateOfBirth.yyyy = nums[2];

	return dateOfBirth;
}

Date student::setDOB(string line) {
	Date dateOfBirth;

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

	dateOfBirth.dd = nums[0];
	dateOfBirth.mm = nums[1];
	dateOfBirth.yyyy = nums[2];

	return dateOfBirth;
}


void student::addToFile() {
	std::ofstream file;
	file.open("Students.txt", std::ios::app);

	file << studentID << ',';
	file << forename << ',';
	file << surname << ',';
	file << email << ',';
	file << ' ' << DOB.dd << '/' << DOB.mm << '/' << DOB.yyyy << ',';
	file << courseID << ',';
	for (int i = 0; i < 4; i++) {
		file << marks[i] << ',';
	}
	file << isRegistered;
	file << endl;
}

void student::ammendStudent(student mys) {
	std::ifstream file;
	file.open("Students.txt");

	// maybe create new temp file here or at the end
	std::ofstream newFile("temp.txt");
	std::ofstream deadFile("dead.txt");

	char c;
	int lineNum = 1;
	
	string studentName = mys.getForename();

	int n = 0;
	while (file.get(c)) {
		if (c == '\n') {
			lineNum++;
		}
		if (lineNum != mys.studentID) {
			newFile << c;
		}
		else {
			if (n == 0) {
				if (getID() != 1) {
					newFile << endl;
				}
				newFile << getID() << ", ";
				newFile << getForename() << ", ";
				newFile << getSurname() << ", ";
				newFile << getEmail() << ", ";
				int d = DOB.dd;
				int m = DOB.mm;
				int y = DOB.yyyy;
				newFile << d << "/" << m << "/" << y << ", ";
			}
			n++;
		
			//call add to file
		}
	}


	// now write this file 
	int result;
	file.close();
	newFile.close();

	if (remove("Students.txt") != 0) {
		cout << "error deleting file";
	}
	else {
		cout << "file deleted";
	}


	result = std::rename("temp.txt", "Students.txt");
	if (result == 0) {
		cout << "file renamed";
	}
	else {
		cout << "error renaming file";
	}
	
}

void student::deleteStudent(int studentID) {
	std::ifstream file;
	file.open("Students.txt");

	// maybe create new temp file here or at the end
	std::ofstream newFile("temp.txt");

	char c;
	int lineNum = 1;

	while (file.get(c)) {
		if (c == '\n') {
			lineNum++;
		}
		if (lineNum != studentID) {
			newFile << c;
		}
	}
	// now write this file 
	int result;
	file.close();
	newFile.close();

	if (remove("Students.txt") != 0) {
		cout << "error deleting file";
	}
	else {
		cout << "file deleted";
	}


	result = std::rename("temp.txt", "Students.txt");
	if (result == 0) {
		cout << "file renamed";
	}
	else {
		cout << "error renaming file";
	}

}

int student::searchStudents() {
	int choiceStudent;
	student* chosenStudent;
	string initChoice;
	string splitChoice[50];
	int choice;
	string choiceEnd;
	bool choiceCheck = 0;

	cout << "Enter the ID of the Student you would like to search for: " << endl;
	cin >> choiceStudent;
	if (choiceStudent > studentReferences.size()) {
		cout << "Student Does not exist" << endl;
		exit(EXIT_SUCCESS);
	}

	while (choiceCheck == 0)
	{
		for (int i = 0; i < numOfStudents; i++)
		{
			if (choiceStudent == studentReferences[i]->studentID)
			{
				cout << choiceStudent << endl;
				chosenStudent = studentReferences[i];
				chosenStudent->displayStudent();
				choiceCheck = 1;
			}
		}
	}
	return chosenStudent->getID();
}

void student::editStudent()
{
	

	locale loc; //Include locale
	int choiceStudent;
	student* chosenStudent;
	string initChoice;
	string splitChoice[50];
	//string choice;
	int choice;
	string choiceEnd;
	bool choiceCheck = 0;

	cout << "Enter the ID of the Student you would like to edit: " << endl;
	//cin.ignore(); //This must be called if setMark is called as it uses cin not getline
	cin >> choiceStudent;

	while (choiceCheck == 0)
	{
		for (int i = 0; i < numOfStudents; i++)
		{
			if (choiceStudent == studentReferences[i]->studentID)
			{

				chosenStudent = studentReferences[i];
				cout << "You are editing the student:";
				chosenStudent->displayForename();
				cout << endl;
				choiceCheck = 1;
			}
		}
		if (choiceCheck == 0)
		{

			cout << choiceStudent << endl;
			cout << "No Match" << endl;
			cout << "Please enter a valid Student ID: " << endl;
			cin >> choiceStudent;
			//getline(cin, choiceStudent);
		}
	}

	cin.ignore();
	choiceCheck = 0;
	while (choiceCheck == 0)
	{
		cout << "What do you want to edit? " << endl;
		cout << "1: Forename" << endl;
		cout << "2: Surname" << endl;
		cout << "3: Email" << endl;
		cout << "4: Date of Birth" << endl;
		cin >> initChoice;
		choice = stoi(initChoice);
		cout << choice;

		if (choice == 1)
		{
			cout << "Successful Match!" << endl;
			chosenStudent->setForename();
			choiceCheck = 1;
		}
		
		else if (choice == 2)
		{
			cout << "Successful Match!" << endl;
			chosenStudent->setSurname();
			choiceCheck = 1;

		}
		else if (choice == 3)
		{
			cout << "Successful Match!" << endl;
			chosenStudent->setEmail();
			choiceCheck = 1;
		}
		else if (choice == 4)
		{
			cout << "Successful Match!" << endl;
			chosenStudent->setDOB();
			choiceCheck = 1;
		}/*
		else if (choice == "mark")
		{
			cout << "Successful Match!" << endl;
			chosenStudent->setMark();
		}*/
		else
		{
			cout << "No Match" << endl;
		}
		
	}

	chosenStudent->ammendStudent(*chosenStudent);
}
