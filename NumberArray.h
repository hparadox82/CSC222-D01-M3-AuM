#pragma once
//Numbers.h
#ifndef NUMBERARRAY_H
#define NUMBERARRAY_H

#include <iostream>

class NumberArray
{
private:
	double* aPtr;
	int arraySize;
	bool isValid(int sizeCheck) const;
public:
	//default size if none specified
	static const int DEFAULT_SIZE, MIN_SIZE = 10;
	static const int MAX_SIZE = 20;

	//default to return from getNumber if index invalid
	static const double DEFAULT_VALUE;

	//Constructor:
	NumberArray(int size = DEFAULT_SIZE);
	//Copy:
	NumberArray(const NumberArray &obj);

	//Destructor:
	~NumberArray();

	//Overloads (copy, move):
	NumberArray& operator=(const NumberArray& right);


	//Member:
	void setNumber(int index, double value);
	
	//Accessors:
	double getNumber(int index) const;
	double getLowest() const;
	double getHighest() const;
	double getAverage() const;

	//Print:
	void print() const;

	//Helper:
	int getSize() const;
	
};
#endif

