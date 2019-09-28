#include "CourseAssessmentList.h"




CourseAssessmentList::CourseAssessmentList()
{
	head = NULL;
	tail = NULL;
	count = 0;
}


CourseAssessmentList::~CourseAssessmentList()
{
}

void CourseAssessmentList::createNode(int courseID, string course, string assessment, string weight, Date deadline)
{
	CANode *temp = new CANode;
	temp->courseID = courseID;
	temp->courseName = course;
	temp->assessmentName = assessment;
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

void CourseAssessmentList::display()
{
	CANode *temp = new CANode;
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
		std::cout << temp->courseID << endl;
		std::cout << temp->courseName << endl;
		std::cout << temp->assessmentName << endl;
		std::cout << temp->assessmentWeight << endl;
		std::cout << tempday << "/" << tempmonth << "/" << tempyear << endl;

		temp = temp->link;
	}
}

int CourseAssessmentList::searchNumberOfInstances(CANode * head, int courseID)
{
	if (head == NULL)
		return count;
	if (head->courseID == courseID)
		count++;
	return searchNumberOfInstances(head->link, courseID);
}

void CourseAssessmentList::resetCount()
{
	count = 0;
}


void CourseAssessmentList::iteratingDisplay(int numOfAssessments, int startingPoint)
{
	CANode *current = new CANode;
	CANode *previous = new CANode;
	current = head;
	previous = head;
	for (int i = 1; i<startingPoint; i++)
	{
		previous = current;
		current = current->link;
	}
	for (int i = 0; i < numOfAssessments; i++)
	{
		//cout << current->courseName << endl;
		cout << "Assessment " << i+1 << ":";
		cout << current->assessmentName << endl;
		cout << "Weighting:   ";
		cout << current->assessmentWeight << endl;
		// need to display mark somehow
		current = current->link;
		cout << std::string(85, '=') << endl;
	}
}

vector<string> CourseAssessmentList::storeAssessments(int numOfAssessments, int startingPoint)
{
	CANode *current = new CANode;
	CANode *previous = new CANode;
	current = head;
	previous = head;

	for (int i = 1; i<startingPoint; i++)
	{
		previous = current;
		current = current->link;
	}
	vector<string> assessments;
	for (int i = 0; i < numOfAssessments; i++)
	{

		assessments.push_back(current->assessmentName);
		assessments.push_back(current->assessmentWeight);
		current = current->link;
	}

	return assessments;
}

int CourseAssessmentList::searchNodeNumber(CANode * head, int courseID)
{
	CANode * here = head;
	int number = 1;
	if (here == NULL)
	{
		return NULL;
	}
	else
	{
		while (here->courseID != courseID && here->link != NULL)
		{
			here = here->link;
			number++;
		}

		if (here->courseID == courseID)
		{
			return number;
		}
		else
		{
			return NULL;
		}
	}
}