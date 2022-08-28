/**
 * file: proj1-main.cpp
 * author: Wesley Anastasi
 * course: CSI 1440
 * assignment: project 1
 * due date: 8/29/2022
 *
 * date modified: 8/29/2022
 * - created file
 * 
 * Template
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include "proj1-person.hpp"

using namespace std;

const int maxDataSize = 25;

int main() 
{
    ifstream input;
    string userInput = "";
    string data;
    Person p[maxDataSize];
    Person *referenceToP[maxDataSize];
    int numOfItems = 0;

    input.open("people.dat");

    while(getAPersonFromStream(input, &p[numOfItems]) && numOfItems < 25)
    {
        displayAPerson(cout, &p[numOfItems]);
        numOfItems++;
    }
    for (int i = 0; i < numOfItems; i++)
    {
        referenceToP[i] = &p[i];
    }

    cout << "Sorted by Age: " << endl;

    sortPersonArrayByAge(referenceToP, numOfItems);

    for (int i = 0; i < 5; i++)
    {
        displayAPerson(cout, referenceToP[i]);
    }

    cout << "Sorted by Name: " << endl;

    sortPersonArrayByName(referenceToP, numOfItems);

    for (int i = 0; i < 5; i++)
    {
        displayAPerson(cout, referenceToP[i]);
    }

    while (userInput != "no more")
    {
        cout << "who do you want to search for" << endl;
        getline(cin, userInput);
        displayAPerson(cout, findAPerson(referenceToP, numOfItems, userInput));
    }

    return 0;   
}