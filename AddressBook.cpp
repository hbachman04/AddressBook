
#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include "addressBookType.h"

using namespace std;

// Function to enter a new contact
extPersonType enterContact()
{
    string firstName, lastName;
    int month, day, year;
    string street, city, state, zip;
    string phone, status;

    cout << "Enter first name: ";
    cin >> firstName;

    cout << "Enter last name: ";
    cin >> lastName;

    cout << "Enter birth month, day, and year: ";
    cin >> month >> day >> year;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter street address: ";
    getline(cin, street);

    cout << "Enter city: ";
    getline(cin, city);

    cout << "Enter state: ";
    getline(cin, state);

    cout << "Enter ZIP code: ";
    getline(cin, zip);

    cout << "Enter phone number: ";
    getline(cin, phone);

    cout << "Enter status (Family, Friend, or Business): ";
    getline(cin, status);

    return extPersonType(
        firstName, lastName,
        month, day, year,
        street, city, state, zip,
        phone, status
    );
}

int main()
{
    addressBookType addressBook;
    ifstream inFile;

    string firstName, lastName;
    int month, day, year;
    string street, city, state, zip;
    string phone, status;

    string fileName;

    cout << "Enter file name: ";
    getline(cin, fileName);

    inFile.open(fileName);

    if (!inFile)
    {
        cout << "Error: Could not open " << fileName << "." << endl;
        cout << "Check that the data file is in the program's working folder."
            << endl;
        return 1;
    }

    // Load contacts from the data file
    while (inFile >> firstName >> lastName)
    {
        if (!(inFile >> month >> day >> year))
            break;

        inFile.ignore(numeric_limits<streamsize>::max(), '\n');

        if (!getline(inFile, street) ||
            !getline(inFile, city) ||
            !getline(inFile, state) ||
            !getline(inFile, zip) ||
            !getline(inFile, phone) ||
            !getline(inFile, status))
        {
            break;
        }

        extPersonType person(
            firstName, lastName,
            month, day, year,
            street, city, state, zip,
            phone, status
        );

        addressBook.insertLast(person);
    }

    inFile.close();

    // Sort the contacts by last name
    addressBook.sort();

    cout << "\nWelcome to the address book program." << endl;

    int choice = 0;

    do
    {
        cout << "\nChoose among the following options:" << endl;
        cout << "1: To see if a person is in the address book" << endl;
        cout << "2: Print the information of a person" << endl;
        cout << "3: Print the names of people having a birthday in a particular month" << endl;
        cout << "4: Print the names of people between two last names" << endl;
        cout << "5: Print the names of people having a particular status" << endl;
        cout << "6: Print the address book" << endl;
        cout << "7: Save data" << endl;
        cout << "8: Add or delete a contact" << endl;
        cout << "9: Terminate the program" << endl;
        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a number from 1 to 9." << endl;
            continue;
        }

        string name, statusInput, last1, last2;
        int selectedMonth, action, found;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter the last name to search for: ";
            cin >> name;

            found = addressBook.search(name);

            if (found != -1)
                cout << name << " is in the address book." << endl;
            else
                cout << name << " is not in the address book." << endl;

            break;
        }

        case 2:
            cout << "Enter the last name of the person: ";
            cin >> name;
            cout << endl;
            addressBook.printInfoOf(name);
            break;

        case 3:
            cout << "Enter the month number (1-12): ";
            cin >> selectedMonth;

            if (selectedMonth >= 1 && selectedMonth <= 12)
                addressBook.printNameInTheMonth(selectedMonth);
            else
                cout << "Invalid month." << endl;

            break;

        case 4:
            cout << "Enter starting last name: ";
            cin >> last1;

            cout << "Enter ending last name: ";
            cin >> last2;

            addressBook.printNamesBetweenLastNames(last1, last2);
            break;

        case 5:
            cout << "Enter status (Family, Friend, or Business): ";
            cin >> statusInput;

            addressBook.printNamesWithStatus(statusInput);
            break;

        case 6:
            addressBook.print();
            break;

        case 7:
        {
            ofstream outFile("Ch11_Ex5Data_Saved.txt");

            if (outFile)
            {
                addressBook.saveData(outFile);
                outFile.close();

                cout << "Address book saved to "
                    << "Ch11_Ex5Data_Saved.txt." << endl;
            }
            else
            {
                cout << "Error saving the address book." << endl;
            }

            break;
        }

        case 8:
        {
            cout << "1: Add a contact" << endl;
            cout << "2: Delete a contact" << endl;
            cout << "Choose an action: ";
            cin >> action;

            if (action == 1)
            {
                extPersonType newPerson = enterContact();

                addressBook.insertLast(newPerson);
                addressBook.sort();

                cout << "Contact added." << endl;
            }
            else if (action == 2)
            {
                cout << "Enter the last name of the contact to delete: ";
                cin >> name;

                if (addressBook.deletePerson(name))
                    cout << "Contact deleted." << endl;
                else
                    cout << "Contact not found." << endl;
            }
            else
            {
                cout << "Invalid action." << endl;
            }

            break;
        }

        case 9:
            cout << "Terminating the address book program. Goodbye!" << endl;
            break;

        default:
            cout << "Invalid choice. Please choose from 1 to 9." << endl;
        }

    } while (choice != 9);

    return 0;
}
