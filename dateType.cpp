
#include <iostream>
#include "dateType.h"

using namespace std;

void dateType::setDate(int month, int day, int year)
{
    dMonth = month;
    dDay = day;
    dYear = year;
}

void dateType::getDate(int& month, int& day, int& year) const
{
    month = dMonth;
    day = dDay;
    year = dYear;
}

void dateType::printDate() const
{
    cout << dMonth << "/" << dDay << "/" << dYear;
}

dateType::dateType(int month, int day, int year)
{
    dMonth = month;
    dDay = day;
    dYear = year;
}
