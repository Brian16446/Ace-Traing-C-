#pragma once
#ifndef SCLIST_CPP
#define SCLIST_CPP
#include "SCList.cpp"
#endif
#include <iostream>

class SCLinkedList
{
private:
	SCNode * tail;
public:
	void createNode(int studentID, string student, string surname, int courseID);
	void deleteNodeAt(int nodeNumber);
	SCNode * search(SCNode* head, int studentID);
	int searchNodeNumber(SCNode * head, int studentID);
	SCNode *head;
	void display();
	SCLinkedList();
	~SCLinkedList();
};