#pragma once
#include "Time.h"
#include "Date.h"

using namespace std;

class DataTime : Date, Time
{
	public:
		DataTime(int, int, int, Days*); //Constructor
		~DataTime(); //Destructor
};
