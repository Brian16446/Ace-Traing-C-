#pragma once
#include "Assessment.h"
#ifndef LIST_H
#define LIST_H
#include "List.h"
#endif



using namespace std;



Assessment::Assessment()
{
}


Assessment::~Assessment()
{
}

void Assessment::linkedList()
{
	List* assessmentList = new List();

	string * assessments;
	assessments = setAssessmentDetails();
	string stringnum = assessments[0];
	int assessmentNum = stoi(stringnum);

	int sizeOfArray = (assessmentNum * 2) + 2;
	Date* dateArray;
	dateArray = new Date[sizeOfArray];
	Date tempDate;




	for (int i = 2; i < (assessmentNum * 2) + 2; i += 2) {

		tempDate = setDeadlineDate();
		dateArray[i] = tempDate;

	}



	for (int j = 2; j < (assessmentNum * 2) + 2; j += 2) {


		assessmentList->createNode(assessments[j], assessments[j + 1], dateArray[j]);




	}


	temphead = assessmentList->head;

}

int Assessment::setNumOfAssessments()
{
	int num;
	bool numValidate = 0;
	cout << "Please enter the number of assessments: ";
	cin >> num;
	while (numValidate == 0)
	{
		if (num < 0 || num > 100)
		{
			cout << "Please enter a number between 0-100: ";
			cin >> num;
		}
		else
		{
			//cout << num << "\n";
			numValidate = 1;
		}
	}
	return num;
}

string * Assessment::setAssessmentDetails()
{
	locale loc;
	int numberOfAssessments = setNumOfAssessments();
	string initName;
	//string splitName[50];
	//string finalName;
	int num = 1;
	string weighting;
	string* nameArray;
	int arraySize = (numberOfAssessments * 2) + 2;
	nameArray = new string[arraySize]; //dynamic array use
	int totalweight = 0;
	int iweight;
	string stringnum = to_string(numberOfAssessments);
	nameArray[0] = stringnum;



	/*For loop contains an if statement and cin.ignore due to a problem with
	compatbility between looping and getline, this is also why <= is used
	as the first iteration is skipped, so the loop really starts executing
	code at 1, not 0*/

	for (int i = 0; i <= (numberOfAssessments * 2) + 1; i += 2)
	{

		if (i == 0)
		{
			cin.ignore();
		}
		else
		{

			cout << "Please enter the name of assessment number " << num << ": ";
			getline(cin, initName);
			nameArray[i] = initName;
			cout << "Please enter the weighting for assessment number " << num << ": ";
			getline(cin, weighting);
			iweight = stoi(weighting);
			totalweight += iweight;
			weighting.append("%");
			nameArray[i + 1] = weighting;
			num++;
			//cout << nameArray[i] << " " << nameArray[i + 1] << endl;
			//cout.flush();


		}
	}
	if (totalweight != 100)
	{
		cout << "Weightings did not add up to 100% please re-enter the assessment names and their weightings \n";
		nameArray = setAssessmentDetails();
	}

	return nameArray;
}

Date Assessment::setDeadlineDate()
{
	Date courseEndDate;

	string initDate;
	cout << "Please enter the deadline date. (DD/MM/YYYY)" << endl;
	cin >> initDate;

	stringstream ss(initDate);
	string token;
	char delim = '/';
	vector<string> arr;
	vector<int> nums;



	while (std::getline(ss, token, delim)) {
		arr.push_back(token);
	}

	for (int i = 0; i < 3; i++) {
		int num = atoi(arr[i].c_str());
		nums.push_back(num);
	}

	courseEndDate.dd = nums[0];
	courseEndDate.mm = nums[1];
	courseEndDate.yyyy = nums[2];






	if (!validation::checkIfDateValid(courseEndDate.dd, courseEndDate.mm, courseEndDate.yyyy)) {
		cout << "Please enter a valid date: ";
		setDeadlineDate();
	}

	return courseEndDate;
}

string Assessment::dateToString(int intArray[], int sizeOfArray) {
	string returnstring = "";
	string tempstring = "";
	for (int temp = 0; temp < sizeOfArray; temp++) {
		tempstring = to_string(intArray[temp]);
		returnstring.append(tempstring);
	}

	return returnstring;
}
