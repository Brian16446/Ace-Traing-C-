#pragma once
#include "Assessment.h"
class Portfolio :
	public Assessment
{
public:
	Portfolio();
	~Portfolio();

	Date setStartDate();
private:
	//Date setStartDate();
};
