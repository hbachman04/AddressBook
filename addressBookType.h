
#ifndef H_addressBookType
#define H_addressBookType

#include <string>
#include <fstream>
#include "linkedListType.h"

using namespace std;

class addressBookType
{
public:
    void print() const;
    void printNameInTheMonth(int month);
    void printInfoOf(string lName);
    void printNamesWithStatus(string status);
    void printAt(int i);
    void printNamesBetweenLastNames(string last1, string last2);

    void insertAt(const extPersonType& eP, int i);
    void insertLast(const extPersonType& eP);

    bool deletePerson(string lName);

    int search(string lName);
    void sort();
    void saveData(ofstream&);

    addressBookType();

private:
    linkedListType list;
    int length;
    static const int MAX_ENTRIES = 500;
};

#endif
