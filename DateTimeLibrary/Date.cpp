#include "pch.h"
#include "Date.h"
#include <vector> 

Date::Date(int monthParameter, int dayParameter, int yearParameter, Days* daysParameter)
{
	daysWeek = *daysParameter;
	setMonth(monthParameter);
	setDay(dayParameter);
	setYear(yearParameter);
}

Date::~Date()
{
	delete this;
}

void Date::ToDate(string stringToDate)
{
	if(stringToDate.max_size() != 9)
		throw exception("ArgumentOutOfRangeException");

	auto Split = [](string &dateToProcess, char delemiter) -> vector<int>
	{ 	
		vector<int> processedDate;
		int index = 0;
		string auxiliar = '\0';

		for (char character : dateToProcess)
		{
			if(character != delemiter)
				auxiliar += character;
			else 
			{
				auxiliar = '\0';
				processedDate.push_back(stoi(auxiliar));
				index++;
			}
		}

		return processedDate;
	};

	vector<int> dateSplit = Split(stringToDate, '/');
	
	try 
	{
		setMonth(dateSplit[0]);
		setDay(dateSplit[1]);
		setYear(dateSplit[2]);
	}
	catch(exception)
	{
		throw;
	};
}

Date::Days Date::getDaysWeek()
{
	return daysWeek;
}

void Date::setDaysWeek(Days daysWeekParameter)
{
	daysWeek = daysWeekParameter;
}

int Date::getMonth()
{
	return month;
}

void Date::setMonth(int value)
{
	if (ValidateMonth(value))
		month = value;
	else
		throw exception("ArgumentOutOfRangeException");
}


bool ValidateMonth(int monthToValidate)
{
	return (monthToValidate >= 1 && monthToValidate <= 12);
}



int Date::getDay()
{
	return day;
}

void Date::setDay(int value)
{
	auto ValidationMonth = [](int &refValue, int valueMax = 31) -> bool { return refValue < 1 || refValue > valueMax; };
	switch(month)
	{
		case 1:
			if (ValidationMonth(value))
				throw exception("ArgumentOutOfRangeException");
			break;
		case 2:
			if (year % 4 == 0)
			{
				if (year % 100 == 0) 
				{
					if (year % 400 == 0) 
					{
						if (ValidationMonth(value, 29))
							throw exception("ArgumentOutOfRangeException");
					}
					else
						if(ValidationMonth(value, 28))
							throw exception("ArgumentOutOfRangeException");
				}
				else
					if (ValidationMonth(value, 29))
						throw exception("ArgumentOutOfRangeException");
			}
			else 
				if (ValidationMonth(value, 28))
					throw exception("ArgumentOutOfRangeException");
			break;
		case 3:
			if (ValidationMonth(value))
				throw exception("ArgumentOutOfRangeException");
			break;
		case 4:
			if (ValidationMonth(value, 30))
				throw exception("ArgumentOutOfRangeException");
			break;
		case 5:
			if (ValidationMonth(value))
				throw exception("ArgumentOutOfRangeException");
			break;
		case 6:
			if (ValidationMonth(value, 30))
				throw exception("ArgumentOutOfRangeException");
			break;
		case 7:
			if (ValidationMonth(value))
				throw exception("ArgumentOutOfRangeException");
			break;
		case 8:
			if (ValidationMonth(value))
				throw exception("ArgumentOutOfRangeException");
			break;
		case 9:
			if (ValidationMonth(value, 30))
				throw exception("ArgumentOutOfRangeException");
			break;
		case 10:
			if (ValidationMonth(value))
				throw exception("ArgumentOutOfRangeException");
			break;
		case 11:
			if (ValidationMonth(value, 30))
				throw exception("ArgumentOutOfRangeException");
			break;
		case 12:
			if (ValidationMonth(value, 31))
				throw exception("ArgumentOutOfRangeException");
			break;
		default:
			day = value;
			break;
	}
}

int Date::getYear()
{
	return year;
}

void Date::setYear(int value)
{
	if (value < 0)
		throw exception("ArgumentOutOfRangeException");
	else
		year = value;
}

