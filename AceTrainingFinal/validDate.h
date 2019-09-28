#pragma once
#include <iostream>
using namespace std;

namespace validation
{

	inline bool checkIfDateValid(int day, int month, int year) {
		if ((month == 2) && (day > 28)) {
			if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {
				if (day > 29) {
					cout << "Invalid Date. February has 29 days during a leap year" << endl;
					return false;
				}
			}
			else {
				cout << "Invalid Date. February has 28 days outside a leap year." << endl;
				return false;
			}
		}
		if ((month == 4 && (day > 30)) || (month == 6 && (day > 30)) || (month == 9 && (day > 30)) || (month == 11 && (day > 30))) {
			cout << "Invalid Date. This month has 30 days." << endl;
			return false;
		}

		if (day > 31) {
			cout << "Invalid date. This month has 31 days." << endl;
			return false;
		}
		if (month > 12) {
			cout << "Invalid date. A year has 12 months." << endl;
			return false;
		}

		return true;
	}
}