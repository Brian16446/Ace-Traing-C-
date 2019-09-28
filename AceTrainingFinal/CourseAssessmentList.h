#pragma once
#include <string>
#ifndef CALINKEDLIST_CPP
#define CALINKEDLIST_CPP
#include "CourseAssessmentLinkedList.cpp"
#endif
#include <iostream>
#include <vector>




class CourseAssessmentList
{
private:
	//CANode * head, *tail;
	int count;
public:
	void createNode(int courseID, string course, string assessment, string weight, Date deadline);
	void display();
	int searchNumberOfInstances(CANode * head, int courseID);
	void resetCount();
	void iteratingDisplay(int numOfAssessments, int startingPoint);
	vector<string> storeAssessments(int numOfAssessments, int startingPoint);
	int searchNodeNumber(CANode * head, int courseID);
	CANode * head, *tail;
	CourseAssessmentList();
	~CourseAssessmentList();
};