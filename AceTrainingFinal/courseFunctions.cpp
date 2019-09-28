#include <iostream>
#include "Course.h"
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;


void loadCoursesFromFile(vector<Course> &c) {
	int n = 0;
	string line;
	ifstream courseFile;

	courseFile.open("Courses.txt");

	while (getline(courseFile, line)) {
		vector<string> lines;

		// now split the line by , and then pushback into sections array.
		stringstream ss(line);
		string token;
		char delim = ',';

		while (std::getline(ss, token, delim)) {
			lines.push_back(token);
		}

		Course *course = new Course();
		course->createNewCourseFromFile(lines);
		c.push_back(*course);
		Course::courseReferences.push_back(course);
	}
}

void displayCourse(Course c) {
	cout << std::string(80, '=') << endl;
	c.displayProgrammeName();
	cout << endl;
	c.displayCourseType();
	cout << endl;
	cout << "Start Date: ";
	c.displayCourseStartDate();
	cout << endl;
	cout << "End Date: ";
	c.displayCourseEndDate();
	cout << endl;
	cout << "Modules: ";
	c.displayModules();
	cout << endl;
	cout << std::string(80, '=') << endl;
}

void displayCourses(vector<Course> &c) {
	// Looping through vector of objects and display to screen.
	
	for (size_t i = 0; i < c.size(); i++) {
		cout << std::string(80, '=') << endl;
		c[i].displayCourseID();
		cout << endl;
		c[i].displayProgrammeName();
		cout << endl;
		c[i].displayCourseType();
		cout << endl;
		cout << "Start Date: ";
		c[i].displayCourseStartDate();
		cout << endl;
		cout << "End Date: ";
		c[i].displayCourseEndDate();
		cout << endl;
		cout << "Modules: ";
		c[i].displayModules();
		cout << endl;
		if (i == c.size()-1) {
			cout << std::string(80, '=') << endl;
		}
	}

	// Looping through vector and checking for a subject

}

int searchCourses(vector<Course> &c, string courseInput) {

	int coursesFound = 0;
	for (size_t i = 0; i < c.size(); i++) {
		//c[i].displayCourseName();
		string cname = c[i].getProgrammeName();
		if (cname == courseInput) { //CHANGE THIS TO BE INPUT FROM CIN
			cout << courseInput << " found at line " << i + 1 << endl;
			displayCourse(c[i]);
			coursesFound++;
		}
	}
	if (coursesFound == 0) {
		cout << courseInput << " not found" << endl;
		cout << "Would you like to search again? Y/N " << endl;
		char choice;
		cin >> choice;
		
		if ((choice == 'Y') || (choice == 'y')) {
			cout << "Please search again" << endl;
			cin.ignore();
			getline(cin, courseInput);
			searchCourses(c, courseInput);
		}
		// Maybe if choice is N return to main menu instead of quitting

	}
	return coursesFound;
}


