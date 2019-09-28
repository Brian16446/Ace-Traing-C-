#pragma once
#include <string>
#include <vector>

// Header guard
#ifndef DATE_CPP
#define DATE_CPP
#include "date.cpp"
#endif // !DATE_CPP


using namespace std;


class student
{
public:
	student();
	~student();

	friend class CourseAssessmentList;

	static int numOfStudents;
	static vector<string> students;
	static void getStudents();
	static vector<student*> studentReferences;

	// Get Functions
	int getID();
	string getForename();
	string getSurname();

	string getCourseName();
	
	Date getDOB();
	string getEmail();
	void getMark();
	void getGrade();
	void getUniversityRef();
	void getQualification();
	void getStatus();
	void getProgrammeName();
	void getProgrammeDate();
	void getModeOfAttendence();
	void getVisaExpiryDate();
	int getCourseID();
	vector<int> assessmentMarks;

	// Display Functions
	void displayForename();
	void displaySurname();
	void displayID();
	void displayEmail();
	void displayDOB();
	void displayStudent();
	void createStudent();

	static void editStudent();

	void createNewStudentFromFile(vector<string> section);

	void deleteStudent(int studentID);

	void ammendStudent(student c);
	static int searchStudents();

private:
	int studentID;
	string forename;
	string surname;
	Date DOB;
	string email;
	int mark;
	char grade;
	int universityRef;
	string qualification;
	string status;
	string programmeName;
	string programmeDate;
	string modeOfAttendence;
	string visaExpiryDate;
	string isRegistered;

	string courseName;
	int courseID;

	int assessmentMark1;
	int assessmentMark2;
	int assessmentMark3;
	int assessmentMark4;

	int setCourseID();
	string setForename();
	string setSurname();
	string setEmail();
	string setIsRegistered();
	int setMark(int i);
	int marks[4];
	char setGrade();
	int setUniversityRef();
	string setQualification();
	string setStatus();
	string setProgrammeName();
	string setProgrammeDate();
	string setModeOfAttendence();
	string setVisaExpiryDate();
	Date setDOB();
	Date setDOB(string line);
	void addToFile();
};