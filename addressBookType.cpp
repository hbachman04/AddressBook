
#include <iostream>
#include <fstream>
#include <string>
#include "addressBookType.h"

using namespace std;

addressBookType::addressBookType()
{
    length = 0;
}

void addressBookType::print() const
{
    for (int i = 0; i < length; i++)
    {
        extPersonType person = list.getAt(i);
        person.printInfo();
        cout << endl;
    }
}

void addressBookType::printNameInTheMonth(int month)
{
    bool found = false;

    for (int i = 0; i < length; i++)
    {
        extPersonType person = list.getAt(i);

        if (person.isMonth(month))
        {
            person.print();
            cout << endl;
            found = true;
        }
    }

    if (!found)
        cout << "No contacts found for that month." << endl;
}

void addressBookType::printInfoOf(string lName)
{
    int position = search(lName);

    if (position != -1)
    {
        extPersonType person = list.getAt(position);
        person.printInfo();
    }
    else
    {
        cout << lName << " is not in address book." << endl;
    }
}

void addressBookType::printNamesWithStatus(string status)
{
    bool found = false;

    for (int i = 0; i < length; i++)
    {
        extPersonType person = list.getAt(i);

        if (person.isStatus(status))
        {
            person.print();
            cout << endl;
            found = true;
        }
    }

    if (!found)
        cout << "No contacts found with that status." << endl;
}

void addressBookType::printAt(int i)
{
    if (i >= 0 && i < length)
    {
        extPersonType person = list.getAt(i);
        person.printInfo();
    }
    else
    {
        cout << "No such person." << endl;
    }
}

void addressBookType::printNamesBetweenLastNames(
    string last1, string last2)
{
    for (int i = 0; i < length; i++)
    {
        extPersonType person = list.getAt(i);
        string lastName = person.getLastName();

        if (last1 <= lastName && lastName <= last2)
        {
            person.print();
            cout << endl;
        }
    }
}

void addressBookType::insertAt(const extPersonType& eP, int i)
{
    if (length >= MAX_ENTRIES)
    {
        cout << "Address book is full." << endl;
        return;
    }

    if (list.insertAt(eP, i))
    {
        length++;
        cout << "Contact inserted." << endl;
    }
    else
    {
        cout << "Invalid position." << endl;
    }
}

void addressBookType::insertLast(const extPersonType& eP)
{
    if (length >= MAX_ENTRIES)
    {
        cout << "Address book is full." << endl;
        return;
    }

    if (list.insertLast(eP))
        length++;
}

bool addressBookType::deletePerson(string lName)
{
    int position = search(lName);

    if (position == -1)
        return false;

    if (list.deleteAt(position))
    {
        length--;
        return true;
    }

    return false;
}

int addressBookType::search(string lName)
{
    for (int i = 0; i < length; i++)
    {
        extPersonType person = list.getAt(i);

        if (person.isLastName(lName))
            return i;
    }

    return -1;
}

void addressBookType::sort()
{
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            extPersonType firstPerson = list.getAt(j);
            extPersonType secondPerson = list.getAt(j + 1);

            if (firstPerson.getLastName() >
                secondPerson.getLastName())
            {
                list.setAt(secondPerson, j);
                list.setAt(firstPerson, j + 1);
            }
        }
    }
}

void addressBookType::saveData(ofstream& outFile)
{
    for (int i = 0; i < length; i++)
    {
        extPersonType person = list.getAt(i);

        int month, day, year;
        string street, city, state, zip;

        person.getDOB(month, day, year);
        person.getAddress(street, city, state, zip);

        outFile << person.getFirstName() << " "
            << person.getLastName() << endl;

        outFile << month << " " << day << " "
            << year << endl;

        outFile << street << endl
            << city << endl
            << state << endl
            << zip << endl;

        outFile << person.getPhoneNumber() << endl
            << person.getStatus() << endl;
    }
}
