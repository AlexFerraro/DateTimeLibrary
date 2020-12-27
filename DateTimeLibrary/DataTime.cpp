#include "pch.h"
#include "DataTime.h"
#include "Date.h"

DataTime::DataTime(int monthParameter, int dayParameter, int yearParameter, Days* daysParameter) : Date::Date(monthParameter, dayParameter, yearParameter, daysParameter)
{

}

DataTime::~DataTime()
{
	Date::~Date();
	//delete time;
	delete this;
}