#pragma once
//date.h
#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>


class date
{
private: //stores day month year
	int day;
	int month;
	int year;
	bool isvaliDD(int d, int m, int y) const;

public:
	//default date:
	date(int day = 1, int month = 1, int year = 1900);

	//getters
	int getD() const;
	int getMo() const;
	int getYr() const;

	
	//leap year check
	bool isLeap() const;
	bool isLeap(int year) const;

	//gets last day
	int lastD() const;
	int lastD(int month, int year) const;

	std::string printD1() const; //format: mm/dd/yyyy
	std::string printD2() const; //format: monthname day, year
	std::string printD3() const; //format: dd monthname year
};
#endif
