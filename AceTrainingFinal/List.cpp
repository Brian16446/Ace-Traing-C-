#include "List.h"



List::List()
{
	head = NULL;
	tail = NULL;
}


List::~List()
{
}

void List::createNode(string name, string weight, Date deadline)
{
	Node *temp = new Node;
	temp->assessmentName = name;
	temp->assessmentWeight = weight;
	temp->deadlineDate = deadline;
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

void List::display()
{
	Node *temp = new Node;
	temp = head;
	Date tempdate;
	int tempday;
	int tempmonth;
	int tempyear;
	while (temp != NULL)
	{
		tempdate = temp->deadlineDate;
		tempday = tempdate.dd;
		tempmonth = tempdate.mm;
		tempyear = tempdate.yyyy;
		std::cout << temp->assessmentName << endl;
		std::cout << temp->assessmentWeight << endl;
		std::cout << tempday << "/" << tempmonth << "/" << tempyear << endl;
		temp = temp->link;
	}

}

void List::insertStart(string name, string weight, Date deadline)
{
	Node * temp = new Node;
	temp->assessmentName = name;
	temp->assessmentWeight = weight;
	temp->deadlineDate = deadline;
	temp->link = head;
	head = temp;
}