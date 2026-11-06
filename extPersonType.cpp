
#include <iostream>
#include <string>
#include "extPersonType.h"

using namespace std;

void extPersonType::print() const
{
    personType::print();
}

void extPersonType::printInfo() const
{
    personType::print();
    cout << endl;

    int month, day, year;
    getDOB(month, day, year);

    cout << month << "/" << day << "/" << year << endl;
    address.print();
    cout << "Phone: " << phoneNumber << endl;
    cout << "Status: " << status << endl;
}

bool extPersonType::isMonth(int month)
{
    int m, d, y;
    getDOB(m, d, y);
    return m == month;
}

bool extPersonType::isStatus(string status)
{
    return this->status == status;
}

bool extPersonType::isLastName(string lName)
{
    return getLastName() == lName;
}

string extPersonType::getLastName()
{
    return personType::getLastName();
}

string extPersonType::getFirstName()
{
    return personType::getFirstName();
}

void extPersonType::getDOB(int& month, int& day, int& year) const
{
    dob.getDate(month, day, year);
}

void extPersonType::getAddress(string& street, string& city,
    string& state, string& zip)
{
    address.getAddress(street, city, state, zip);
}

string extPersonType::getPhoneNumber()
{
    return phoneNumber;
}

string extPersonType::getStatus()
{
    return status;
}

extPersonType::extPersonType(string first, string last,
    int month, int day, int year,
    string street, string city,
    string state, string zip,
    string phone, string status)
    : personType(first, last),
    dob(month, day, year),
    address(street, city, state, zip),
    phoneNumber(phone),
    status(status)
{
}
