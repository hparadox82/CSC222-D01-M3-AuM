// CSC222-D01-M3-AuM.cpp : This file contains the 'main' function. Program execution begins and ends there.
//main func
#include <iostream>
#include "date.h"

using namespace std;
int main()
{
    /*int day, month, year;
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
    cout << "Date 3: " << userDate.printD3() << endl;*/

    cout << "Test 1: Default constructor." << endl;
    date d1;
    cout << "d1: " << d1.printD1() << endl;

    cout << "\n\nTest 2: April 18 2018." << endl;
    date d2(18, 4, 2018);
    cout << "d2: " << d2.printD2() << endl;

    cout << "\n\nTest 3: October 25 2025." << endl;
    d3.setDate(25, 10, 2025);
    cout << "d3 after setdate(25,10,2025): " << d3.printD3() << endl;

    cout << "\n\nTest 4: Invalid date." << endl;
    date invalidTest;
    invalidTest.setDate(1, 1, 1900);
    invalidTest.setDate(45, 13, 2018);
    cout << invalidTest.printD1();
    if (invalidTest.getD() == 1 && invalidTest.getMo() == 1 && invalidTest.getYr() == 1900)
    {
        cout << "Correctly not accepted and defaulted!" << endl;

    }
    else
    {
        cout << "ERROR: Date not defaulted!" << endl;
    }

    cout << "\n\nTest 5: Another invalid date." << endl;
    invalidTest.setDate(1, 1, 1900);
    invalidTest.setDate(31, 4, 2000);
    cout << invalidTest.printD1();
    if (invalidTest.getD() == 1 && invalidTest.getMo() == 1 && invalidTest.getYr() == 1900)
    {
        cout << "Correctly not accepted and defaulted!" << endl;

    }
    else
    {
        cout << "ERROR: Date not defaulted!" << endl;
    }

    cout << "\n\nTest 6: Another invalid date, again!" << endl;
    invalidTest.setDate(1, 1, 1900);
    invalidTest.setDate(29, 2, 2009);
    cout << invalidTest.printD1();
    if (invalidTest.getD() == 1 && invalidTest.getMo() == 1 && invalidTest.getYr() == 1900)
    {
        cout << "Correctly not accepted and defaulted!" << endl;

    }
    else
    {
        cout << "ERROR: Date not defaulted!" << endl;
    }

    cout << "\n\nTest 7,8: Subtraction operator." << endl;
    date date_subA(10, 4, 2014);
    date date_subB(18, 4, 2014);
    cout << date_subB.printD1() << "-" << date_subA.printD1() << "=" << (date_subB - date_subA) << " days. Expected 8." << endl;

    date date_subC(2, 2, 2006);
    date date_subD(10, 11, 2003);
    cout << date_subB.printD1() << "-" << date_subC.printD1() << "=" << (date_subD - date_subC) << " days. Expected 815." << endl;

    cout << "\n\nTest 9,10: Increment/Decrement." << endl;
    date d_id(29, 2, 2008);
    cout << "Initial date: " << d_id << endl;
    cout << "Pre Incrementing: " << ++d_id << ". Expected March 1, 2008" << endl;
    cout << "Pre Decrementing: " << --d_id << ". Expected February 29, 2008." << endl;
    cout << "Post Incrementing: " << d_id++ << ". Now: " << d_id << ". Expecting March 1 2008." << endl;
    cout << "Post Decrementing: " << d_id-- << ". Now: " << d_id << ". Expecting February 29, 2008." << endl;

    cout << "\n\nTest 11,12: Pre/Post Increment/Decrement Rollover." << endl;
    date d_ro(31, 12, 2024);
    cout << "Initial: " << d_ro << endl;
    cout << "++ rollover: " << ++d_ro << ". Expected January 1, 2025." << endl;
    cout << "-- rollover: " << --d_ro << ". Expected December 31, 2024." << endl;
    cout << "rollover ++: " << d_ro++ << ". Now: " << d_ro << ". Expecting January 1, 2025." << endl;
    cout << "rollover --: " << d_ro-- << ". Now: " << d_ro << ". Expecting December 31, 2024." << endl;

    cout << "\n\nTest 13,14: Stream (cin, cout)." << endl;
    date date_cin;
    cout << "Enter a date (MMDDYYYY or MM/DD/YYYY)." << endl;
    cin >> date_cin;

    if (cin.fail())
    {
        cout << "ERROR: Input wrong. Clearing flags. Date set to default: " << date_cin << endl;
        cin.clear();
        cin.ignore(10000, '\n');
    }
    else
    {
        cout << "Date read using >> and displaying using <<: " << date_cin << endl;
    }

    date date_cin2;
    cout << "Try another date using the same format." << endl;
    cin >> date_cin2;
    if (cin.fail())
    {
        cout << "ERROR: Input wrong. Clearing flags. Date set to default: " << date_cin << endl;
        cin.clear();
        cin.ignore(10000, '\n');
    }
    else
    {
        cout << "Date read using >> and displaying using <<: " << date_cin2 << endl;
    }

    return 0;

}