#include "NumberArray.h"
#include <iostream>
#include <iomanip>
#include <new>

//Static init:
const double NumberArray::DEFAULT_VALUE = 10000.0;

using namespace std;

//Validates size of array
bool NumberArray::isValid(int sizeCheck) const
{
	return (sizeCheck >= MIN_SIZE && sizeCheck <= MAX_SIZE);
}

//Constructor:
NumberArray::NumberArray(int size)
{
	aPtr = nullptr;
	arraySize = 0;
	if (!isValid(size)) //calling isValid to check if the size array fits within parameters
	{
		cerr << "Wrong array size. " << size << " must be between " << MIN_SIZE << " and " << MAX_SIZE << " inclusive. Can't create array." << endl;
		arraySize = 0;
		aPtr = nullptr; //setting to invalid state/clearing.

		return;
	}
	arraySize = size;
	//if valid, allocate memory:
	aPtr = new(nothrow) double[arraySize];
	if (aPtr == nullptr) //check allocation, if no:
	{
		cerr << "Memory allocation failed. Can't create the array." << endl;
		arraySize = 0;
		return;
	}
	//if yes, fill array of requested size
	for (int i = 0; i < arraySize; ++i)
	{
		aPtr[i] = (i + 1) * 1;
	}
	cout << "Created array object with size " << arraySize << "." << endl;
}
//Copy:
NumberArray::NumberArray(const NumberArray& obj)
{
	arraySize = obj.arraySize;
	aPtr = nullptr;
	if (arraySize > 0)
	{
		aPtr = new(nothrow) double[arraySize]; //check for allocate
		if (aPtr == nullptr)
		{
			cerr << "Memory allocation failed. Can't copy the array." << endl;
			arraySize = 0;
			return;
		}
		for (int i = 0; i < arraySize; ++i)
		{
			aPtr[i] = obj.aPtr[i];
		}
	}
}

//Destructor:
NumberArray::~NumberArray()
{
	cout << "Destructor running for array at address: " << aPtr << endl;
	delete[] aPtr;
	aPtr = nullptr;
}

//Overloads (copy, move):
NumberArray& NumberArray::operator=(const NumberArray& right)
{
	if (this == &right)
	{
		return *this;
	}
	delete[] aPtr;
	aPtr = nullptr;
	arraySize = 0;

	arraySize = right.arraySize;

	if (arraySize > 0)
	{
		aPtr = new(nothrow) double[arraySize];
		if (aPtr == nullptr)
		{
			cerr << "Memory allocation failed during copy assignment." << endl;
			arraySize = 0;
			return *this;
		}
		for (int i = 0; i < arraySize; ++i)
		{
			aPtr[i] = right.aPtr[i];
		}

	}
	return *this;
}


//Member:
void NumberArray::setNumber(int index, double value)
{
	if (index >= 0 && index < arraySize && aPtr != nullptr)
	{
		aPtr[index] = value;
	}
	else if (aPtr == nullptr)
	{
		cerr << "Can't set number; array isn't initialized." << endl;
	}
	else
	{
		cerr << "Index out of bounds (" << (arraySize - 1) << "). Value not stored." << endl;
	}
}

//Accessors:
double NumberArray::getNumber(int index) const
{
	if (index >= 0 && index < arraySize && aPtr != nullptr)
	{
		return aPtr[index];
	}
	else if (aPtr == nullptr)
	{
		cerr << "Can't set number; array isn't initialized. Opting for default value." << endl;
		return DEFAULT_VALUE;
	}
	else
	{
		cerr << "Index " << index << " out of bounds (" << (arraySize - 1) << "). Opting for default value." << endl;
		return DEFAULT_VALUE;
	}
}
double NumberArray::getLowest() const
{
	if (arraySize < 0 || aPtr == nullptr)
	{
		cerr << "Can't get lowest value from empty/uninit array!" << endl;
		return 0.0;
	}
	double lowest = aPtr[0];
	for (int i = 1; i < arraySize; ++i)
	{
		if (aPtr[i] < lowest)
		{
			lowest = aPtr[i];
		}
	}
	return lowest;
}
double NumberArray::getHighest() const
{
	if (arraySize <= 0 || aPtr == nullptr)
	{
		cerr << "Can't get highest value from empty/uninit array!" << endl;
		return 0.0;
	}
	double highest = aPtr[0];
	for (int i = 1; i < arraySize; ++i)
	{
		if (aPtr[i] > highest)
		{
			highest = aPtr[i];
		}
	}
	return highest;
}
double NumberArray::getAverage() const
{
	if (arraySize < 0 || aPtr == nullptr)
	{
		cerr << "Can't get average from empty/uninit array!" << endl;
		return 0.0;
	}
	double sum = 0.0;
	for (int i = 0; i < arraySize; ++i)
	{
		sum += aPtr[i];
	}
	return (arraySize > 0) ? (sum / arraySize) : 0.0;
}

//Print:
void NumberArray::print() const
{
	if (arraySize <= 0 || aPtr == nullptr)
	{
		cout << "Array is empty/uninit!" << endl;
		return;
	}
	cout << fixed << setprecision(1);
	for (int i = 0; i < arraySize; ++i)
	{
		cout << aPtr[i] << " ";
	}
	cout << endl;
}

//Helper:
int NumberArray::getSize() const
{
	return arraySize;
}