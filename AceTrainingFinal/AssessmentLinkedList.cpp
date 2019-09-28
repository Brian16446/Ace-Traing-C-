#pragma once
#include <string>
#ifndef DATE_CPP
#define DATE_CPP
#include "date.cpp"
#endif

using namespace std;


struct Node
{
	string assessmentName;
	string assessmentWeight;
	Date deadlineDate;
	Node *link;

};