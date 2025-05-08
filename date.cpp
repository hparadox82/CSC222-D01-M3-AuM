//date.cpp
#include "date.h"
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

const std::vector <std::string> moNAMES = { "January", "February", "March", "April", "May", "June","July", "August", "September", "October", "November", "December" };

using namespace std;

//date values set
date::date(int d, int m, int y)
{	//checks for input validity
	if (isvaliDD(d, m, y)) //checks with isvaliDD + sets
	{
		day = d;
		month = m;
		year = y;
	}
	else //if not, sets default date + display error explaining
	{
		day = 1;
		month = 1;
		year = 1900;
		cerr << "Invalid date: " << d << "|" << m << "|" << y << "; setting to default of 1/1/1900." << endl;
	}
}

//input validation
bool date::isvaliDD(int d, int m, int y) const
{	//checking for date ranges, if invalid enforces default date
	if (m < 1 || m>12 || d < 1 || d > 31 || y < 1900)
	{
		return false;
	}
	//checks if day is valid for given month and year.
	return d <= lastD(m, y);
}

//getters for day month yr:
int date::getD() const
{
	return day;
}
int date::getMo() const
{
	return month;
}
int date::getYr() const
{
	return year;
}


bool date::isLeap()const
{	//calls helper
	return isLeap(year);
} //checks for leap year!


/*leap year math:*/ bool date::isLeap(int year) const
{	
	return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

/*gets last day of obj month*/int date::lastD() const
{
	return lastD(month, year);
}


/*gets last day of specific m/yr*/int date::lastD(int m, int y) const

{
	if (m == 2)
	{
		return isLeap(y) ? 29 : 28;
	}
	else if (m == 4 || m == 6 || m == 9 || m == 11)
	{
		return 30;
	}
	else
	{
		return 31;
	}
}



	std::string date::printD1() const
	{
		ostringstream oss;
		oss << month << "/" << day << "/" << year;
		return oss.str();
	}
	std::string date::printD2() const
	{
		ostringstream oss;
		if (month >= 1 && month <= 12)
		{
			oss << moNAMES[month - 1] << " " << day << ", " << year;
		}
		else
		{
			oss << "Invalid Month " << day << ", " << year;
		}
		return oss.str();
	}
	std::string date::printD3() const
	{
		ostringstream oss;
		if (month >= 1 && month <= 12)
		{
			oss << day << " " << moNAMES[month - 1] << " " << year;
		}
		else
		{
			oss << day << " " << "Invalid Month " << year;
		}
		return oss.str();
	}
	//helper for date calc (operators):
	//single int converter (days since default date, default date day = 0)
	int date::toDayNum() const
	{
		int totalDays = 0;

		for (int y = 1900; y < year; ++y)
		{
			totalDays += isLeap(y) ? 366 : 365;
		}
		for (int m = 1; m < month; ++m)
		{
			totalDays += lastD(m, year);
		}
		totalDays += (day - 1);
		return totalDays;
	}
	void date::fromDayNum(int totalDays)
	{
		//days for years
		year = 1900;
		while (true)
		{
			int daysCurrentYr = isLeap(year) ? 366 : 365;
			if (totalDays >= daysCurrentYr)
			{
				totalDays -= daysCurrentYr;
				year++;
			}
			else
			{
				break;
			}
		}
		month = 1;
		//days for months
		while (true)
		{
			int daysCurrentMo = lastD(month, year);
			if (totalDays >= daysCurrentMo)
			{
				totalDays -= daysCurrentMo;
				month++;
			}
			else
			{
				break;
			}
		}
		//days
		day = totalDays + 1;

		//final check
		if (!isValiDD(day, month, year))
		{
			this->day = 1; this->month = 1; this->year = 1900;
		}
	}

	//overloads:

	//prefix incr:
	date& date::operator++()
	{
		int dayNum = toDayNum();
		dayNum++;
		fromDayNum(dayNum);
		return*this;
	}

	//postfix incr:
	date date::operator++(int)
	{
		date temp = *this; //copy
		++(*this); //call prefix
		return temp; //return
	}

	//prefix decr:
	date& date::operator--()
	{
		int dayNum = toDayNum{}; //prevents going back before default date
		if (dayNum > 0)
		{
			dayNum--;
			fromDayNum(dayNum);
		}
		else
		{
			fromDayNum(0); //will reset or stay at default if dayNum is <= 0.
		}
		return *this;
	}

	//postfix decr:
	date date::operator--(int)
	{
		date temp = *this;
		--(*this);
		return temp;
	}

	//subtract:
	int date::operator-(const date& other) const
	{
		return this->toDayNum() - other.toDayNum();
	}

	//fren functions :D
	ostream& operator<<(ostream& os, const date& dt)
	{
		if (dt.getMo() >= 1 && dt.getMo() <= 12)
		{
			os << moNames[dt.getMo() - 1] << " " << dt.getD() << ", " << dt.getYr();
		}
		else
		{
			os << "Invalid date object.";
		}
		return os;
	}
	istream& operator>>(istream& is, date& dt)
	{
		int d, m, y;
		char sep1 = ' ', sep2 = ' '; //spacing

		is >> m;

		if (is.peek() == '/' || is.peek() == '-' || is.peak() == '.')
		{
			is >> sep1 >> d;
			if (is.peek() == '/' || is.peek() == '-' || is.peak() == '.')
			{
				is >> sep2 >> y;
			}
			else
			{
				is >> d >> y;
			}
		}
		if (is)
		{
			if (dt.isvaliDD(d, m, y))
			{
				dt.setDate(d, m, y);
			}
			else
			{
				dt.setDate(1, 1, 1900);
				is.setstate(failbit);
			}
		
		}
		else
		{
			dt.setDate(1, 1, 1900);
		}
		return is;
	}

	
