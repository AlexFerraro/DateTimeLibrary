#pragma once
#include "DateAbstract.h"

using namespace std;

class Date : virtual protected DateAbstract
{
	protected:
		const enum class Days { DEFAULT = 0, DOMINGO, SEGUNDA, TERCA, QUARTA, QUINTA, SEXTA, SABADO };
		void ToDate(string) override; // Is ok ?

	private:	
		unsigned int month, day, year;
		Days daysWeek;

    // Contrutores, Destrutores e Metodos Acessores
	public:
		Date(int, int, int, Days* daysWeek); //Construtor
		~Date(); //Destrutor
		bool ValidateMonth(int monthToValidate);
		Days getDaysWeek();
		void setDaysWeek(Days);
		int getMonth();
		void setMonth(int);
		int getDay();
		void setDay(int);
		int getYear();
		void setYear(int);
};

