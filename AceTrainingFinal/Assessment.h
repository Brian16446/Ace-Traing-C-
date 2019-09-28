#pragma once
#include <string>
#include<iostream>
#include <locale>
#include<vector>
#include<sstream>
#ifndef VALIDDATE_H
#define VALIDDATE_H
#include "validDate.h"
#endif
#ifndef DATE_CPP
#define DATE_CPP
#include "date.cpp"
#endif
#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP
#include "AssessmentLinkedList.cpp"
#endif
using namespace std;

class Assessment
{
public:
	Assessment();
	~Assessment();
	//void createNewAssessments(); // needs to contain other methods to create an assessment once they are finished and stays public
	string* setAssessmentDetails();
	void linkedList();
	friend class Course;


private:
	string dateToString(int intArray[], int sizeOfArray);
	int setNumOfAssessments();
	//string *setAssessmentDetails(int numOfAssessments);
	Date setDeadlineDate();
	//void linkedList();
	Node * temphead;
	//NEED TO MOVE ALL PRIVATE FUNCTIONS TO PROTECTED WHEN DONE SO INHERITANCE CAN WORK



	string *assessments; // Pointer to array that will have assessment info in it. Name/weight/dates


};