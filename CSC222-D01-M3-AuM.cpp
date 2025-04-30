// CSC222-D01-M3-AuM.cpp : This file contains the 'main' function. Program execution begins and ends there.
//main func
#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>
#include "date.h"
#include "NumberArray.h"

using namespace std;
int main()
 { 
    srand(static_cast<unsigned int>(time(0)));
    /*
    //DATE FORMATTER:
    int day, month, year;
    cout << "Enter a day (cannot be less than 1 or over 31): " << endl;
    cin >> day;
    cout << "Enter a month (1-12): " << endl;
    cin >> month;
    cout << "Enter a year (cannot be before 1900): " << endl;
    cin >> year;

    date userDate(day, month, year);

    cout << "\nDate entered: " << endl;
    cout << "Date 1: " << userDate.printD1() << endl;
    cout << "Date 2: " << userDate.printD2() << endl;
    cout << "Date 3: " << userDate.printD3() << endl;

    return 0;*/

    //NUMBER ARRAY:
    cout << fixed << setprecision(1);

    cout << "For diagnostic reasons, any value set to 10000.0 indicates an error.\n\n\n\n";

    cout << "Array with default size (10): " << endl;
    NumberArray array1(10);
    cout << "Lowest value: " << array1.getLowest() << endl;
    cout << "Highest value: " << array1.getHighest() << endl;
    cout << "Average: " << array1.getAverage() << endl;
    cout << "Getting a number at index 7: " << array1.getNumber(7) << endl;
    array1.print();

    cout << endl;

    cout << "Array with preset test size (12): " << endl;
    NumberArray array2(12);
    array2.print();
    cout << "Lowest value: " << array2.getLowest() << endl;
    cout << "Highest value: " << array2.getHighest() << endl;
    cout << "Average: " << array2.getAverage() << endl;
    cout << "Getting a number at index 9: " << array2.getNumber(9) << endl;
    cout << endl;

    cout << "Array with invalid size (0): " << endl;
    NumberArray invalidSArray(0);
    invalidSArray.print();
    cout << "Lowest value: " << invalidSArray.getLowest() << endl;
    cout << "Highest value: " << invalidSArray.getHighest() << endl;
    cout << "Average: " << invalidSArray.getAverage() << endl;
    cout << "Getting a number at index 3: " << array2.getNumber(3) << endl;
    cout << endl;

    
    int userSize = 0;
    cout << "Input custom array size here, must be between 1 and 20 inclusive: " << endl;
    cin >> userSize;
    NumberArray customArray(userSize);
    customArray.print();
    cout << "Lowest value: " << customArray.getLowest() << endl;
    cout << "Highest value: " << customArray.getHighest() << endl;
    cout << "Average: " << customArray.getAverage() << endl;
    if (customArray.getSize() > 0)
    {
        //generates random index position
        int randIndex = rand() % customArray.getSize();
        
        //retrieves value at specified position
        double valuRandIndex = customArray.getNumber(randIndex);

        //input validation:
        if (valuRandIndex != NumberArray::DEFAULT_VALUE)
        {
            cout << "Getting a number at index " << randIndex << ": " << valuRandIndex << endl;
        }
        else
        {
            cout << "Couldn't get number at index " << randIndex << " . Oops, error." << endl;
        }
    }
    else
    {
        cout << "Skipping random index display due to array being empty." << endl;
    }
}