#pragma once
#include <string>

using namespace std;

struct SCNode
{
	int studentID;
	string studentName;
	string studentSurname;
	int courseID;
	SCNode* link;
};