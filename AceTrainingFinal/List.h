#pragma once
#include <string>
#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP
#include "AssessmentLinkedList.cpp"
#endif
#include <iostream>


class List
{
private:
	Node * head, *tail;
public:
	friend class Assessment;
	void createNode(string name, string weight, Date deadline);
	void display();
	void insertStart(string name, string weight, Date deadline);
	List();
	~List();
};