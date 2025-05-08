#pragma once
//date.h
//m4 additions added: written at work
#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>

class date;
ostream& operator<<(ostream& os, const date& dt);
istream& operator>>(istream& is, date& dt);

class date
{
private: //stores day month year
	int day;
	int month;
	int year;

	//date validation
	bool isvaliDD(int d, int m, int y) const;

	//helper for date calc:
	int toDayNum() const; //converts date to single int
	void fromDayNum(int totalDays); //sets date from single int


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

	//overload operators, incr and decr:
	date& operator++)_;
	date operator++(int);
	date& operator--();
	date operator--(int);

	//date subtraction:
	int operator-(const date& other) const;

	//fren functions :)
	friend ostream& operator<<(ostream& os, const date& dt);
	friend istream& operator>>(istream& is, date& dt);
};
#endif
