// CSC222-D01-M3-AuM.cpp : This file contains the 'main' function. Program execution begins and ends there.
//main func
#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>
#include "date.h"

using namespace std;
int main()
{
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

    return 0;

}