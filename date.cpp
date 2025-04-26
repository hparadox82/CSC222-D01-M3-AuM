//date.cpp
#include "date.h"
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

const std::vector <std::string> moNAMES = { "January", "February", "March", "April", "May", "June","July", "August", "September", "October", "November", "December" };

using namespace std;

//date values set
/*date::date(int d, int m, int y)
{	//checks for input validity
	if (isvaliDD(day, month, year)) //checks with isvaliDD + sets
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
	if (m < 1 || m>12 || d < 1 || y < 1)
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
		return isLeap(year) ? 29 : 28;
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



	/*std::string date::printD1() const
	{
		ostringstream oss;
		oss << month << "/" << day << "/" << year;
		return oss.str();
	}
	/*std::string date::printD2() const
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
			oss << day << " " << "INvalid Month " << year;
		}
		return oss.str();
	}
	*/
