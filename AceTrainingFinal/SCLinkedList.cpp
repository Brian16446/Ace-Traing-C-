#include "SCLinkedList.h"



SCLinkedList::SCLinkedList()
{
	head = NULL;
	tail = NULL;
}


SCLinkedList::~SCLinkedList()
{
}

void SCLinkedList::createNode(int studentID, string student, string surname, int courseID)
{
	SCNode *temp = new SCNode;
	temp->studentID = studentID;
	temp->studentName = student;
	temp->studentSurname = surname;
	temp->courseID = courseID;
	temp->link = NULL;
	if (head == NULL)
	{
		head = temp;
		tail = temp;
		temp = NULL;
	}
	else
	{
		tail->link = temp;
		tail = temp;
	}
}

void SCLinkedList::display()
{
	SCNode *temp = new SCNode;
	temp = head;
	while (temp != NULL)
	{
		if (temp->studentID == 0) {
			continue;
		}
		else {
			std::cout << temp->studentID << endl;
			std::cout << temp->studentName << endl;
			std::cout << temp->studentSurname << endl;
			std::cout << temp->courseID << endl;
			temp = temp->link;
		}
	}
}

SCNode * SCLinkedList::search(SCNode * head, int studentID)
{
	SCNode * here = head;
	if (here == NULL)
	{
		return NULL;
	}
	else
	{
		while (here->studentID != studentID && here->link != NULL)
		{
			here = here->link;
		}

		if (here->studentID == studentID)
		{
			return here;
		}
		else
		{
			return NULL;
		}
	}
}

int SCLinkedList::searchNodeNumber(SCNode * head, int studentID)
{
	SCNode * here = head;
	int number = 1;
	if (here == NULL)
	{
		return NULL;
	}
	else
	{
		while (here->studentID != studentID && here->link != NULL)
		{
			here = here->link;
			number++;
		}

		if (here->studentID == studentID)
		{
			return number;
		}
		else
		{
			return NULL;
		}
	}
}

void SCLinkedList::deleteNodeAt(int nodeNumber)
{
	SCNode *current = new SCNode;
	SCNode *previous = new SCNode;
	current = head;
	previous = head;
	for (int i = 1; i<nodeNumber; i++)
	{
		previous = current;
		current = current->link;
	}
	if (nodeNumber == 1) {
		head = head->link;
	}
	else {
		previous->link = current->link;
	}

	cout << "Student removed from course" << endl;
}