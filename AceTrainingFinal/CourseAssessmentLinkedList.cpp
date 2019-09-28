#pragma once
#include <string>
#ifndef DATE_CPP
#define DATE_CPP
#include "date.cpp"
#endif

using namespace std;

struct CANode {
	int courseID;
	string courseName;
	string assessmentName;
	string assessmentWeight;
	Date deadlineDate;
	CANode* link;

};