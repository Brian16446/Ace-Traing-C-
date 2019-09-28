#pragma once
#include <string>

// Header guard
#ifndef DATE_CPP
#define DATE_CPP
#endif // !DATE_CPP

#include "date.cpp"
#include <vector>


using namespace std;
class Course
{
public:
	Course();
	~Course();
	static int numCourses;
	static vector<Course*> courseReferences;

	void createNewCourse();
	void displayCourseID();
	void displayProgrammeName();
	void displayCourseName();
	void displayCourseType();
	void displayCourseStartDate();
	void displayCourseEndDate();
	void displayModules();
	void displayCourseAssessments(int courseID);
	vector<string> storeCourseAssessments(int courseID);

	void displayCourse();

	string getProgrammeName();
	int getCourseID();
	void loadCoursesFromFile();
	void createNewCourseFromFile(vector<string> section);
	void ammendCourse();
	void deleteCourse(int courseID);

	static void editCourse();

	string getCourseType();
	string getCourseName();

private:
	string setProgrammeName(); // I.e Computer Science
	string setCourseName(); // I.e Databases
	string setCourseName(string line);
	string setCourseType(); // Level C/H/I
	string setCourseType(string line);
	Date setCourseDate();
	Date setCourseDate(string line);
	Date setCourseStartDate();
	Date setCourseEndDate();
	vector<string> setCourseModules(string line);
	vector<string> setCourseModules();
	void addToFile();

	int courseID;
	string programmeName;
	string courseName;
	string courseType;
	Date courseStartDate;
	Date courseEndDate;
	vector<string> modules;

	string assessment1;
	string weight1;
	Date deadline1;
	string assessment2;
	string weight2;
	Date deadline2;
	string assessment3;
	string weight3;
	Date deadline3;
	string assessment4;
	string weight4;
	Date deadline4;

};

