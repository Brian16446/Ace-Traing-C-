#include <iostream>
#include "Student.h"
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

void loadStudentsFromFile(vector<student> &s) {
	int n = 0;
	string line;
	ifstream courseFile;

	courseFile.open("Students.txt");

	while (getline(courseFile, line)) {
		// need to split the line into an array seperated by ,
		// then call course methods with line[0], line[1] etc
		// But maybe just pass the line as an array and then unpack it inside the class method

		vector<string> lines;

		// now split the line by , and then pushback into sections array.
		stringstream ss(line);
		string token;
		char delim = ',';

		while (std::getline(ss, token, delim)) {
			lines.push_back(token);
		}

		student *stu = new student();
		stu->createNewStudentFromFile(lines);
		s.push_back(*stu);
		student::studentReferences.push_back(stu);
	}
}

void displayStudents(vector<student> &s) {
	// Looping through vector of objects and display to screen.

	for (size_t i = 0; i < s.size(); i++) {
		cout << std::string(80, '=') << endl;
		s[i].displayID();
		cout << " || ";
		s[i].displayForename();
		cout << " || ";
		s[i].displaySurname();
		cout << " || ";
		s[i].displayEmail();
		cout << " || ";
		cout << "Date of Birth: ";
		s[i].displayDOB();
		cout << endl;
		if (i == s.size() - 1) {
			cout << std::string(80, '=') << endl;
		}
	}

	// Looping through vector and checking for a subject

}

char convertToGrade(int mark) {
	char grade;
	if (mark >= 0 && mark <= 19)
	{
		grade = 'F';
	}
	else if (mark >= 20 && mark <= 39)
	{
		grade = 'E';
	}
	else if (mark >= 40 && mark <= 49)
	{
		grade = 'D';
	}
	else if (mark >= 50 && mark <= 59)
	{
		grade = 'C';
	}
	else if (mark >= 60 && mark <= 69)
	{
		grade = 'B';
	}
	else if (mark >= 70 && mark <= 100)
	{
		grade = 'A';
	}
	else
	{
		cout << "Mark is out of range" << endl;
	}
	return grade;
}

/*NEED TO DO THE SEARCH STUDENTS*/