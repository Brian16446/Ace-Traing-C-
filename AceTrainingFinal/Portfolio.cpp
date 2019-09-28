#include "Portfolio.h"


Portfolio::Portfolio()
{
}


Portfolio::~Portfolio()
{
}


Date Portfolio::setStartDate()
{
	Date courseStartDate;

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

	courseStartDate.dd = nums[0];
	courseStartDate.mm = nums[1];
	courseStartDate.yyyy = nums[2];






	if (!validation::checkIfDateValid(courseStartDate.dd, courseStartDate.mm, courseStartDate.yyyy)) {
		cout << "Please enter a valid date: ";
		setStartDate();
	}

	return courseStartDate;
}