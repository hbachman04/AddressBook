
#ifndef H_extPersonType
#define H_extPersonType

#include <string>
#include "personType.h"
#include "dateType.h"
#include "addressType.h"

using namespace std;

class extPersonType : public personType
{
public:
    void print() const;
    void printInfo() const;

    bool isMonth(int month);
    bool isStatus(string status);
    bool isLastName(string lName);

    string getLastName();
    string getFirstName();

    void getDOB(int& month, int& day, int& year) const;
    void getAddress(string& street, string& city,
        string& state, string& zip);

    string getPhoneNumber();
    string getStatus();

    extPersonType(string first = "", string last = "",
        int month = 1, int day = 1, int year = 2000,
        string street = "", string city = "",
        string state = "", string zip = "",
        string phone = "", string status = "");

private:
    dateType dob;
    addressType address;
    string phoneNumber;
    string status;
};

#endif
