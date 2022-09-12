/**
 * file: proj1-testmain.cpp
 * author: Wesley Anastasi
 * course: CSI 1440
 * assignment: project 1
 * due date: 8/29/2022
 *
 * date modified: 8/29/2022
 * - created file
 * 
 * Testing driver for testing the person function
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include "proj1-person.hpp"

using namespace std;

int main() 
{
    srand(time(0));
    Person p[25];
    Person *ptr[25];

    //testing getAPersonFromStream
    cout << "Testing getAPersonFromStream" << endl;

    ifstream input;
    stringstream data;

    data << "John Doe, 42\n";
    data << "Thor God of Thunder, 1500\n";
    data << "John Kelly, 26\n";

    int i = 0;
    while(getAPersonFromStream(data, &p[i]))
    {
        displayAPerson(cout, &p[i]);
        i++;
    }


    //testing sortPersonArrayByAge
    
    cout << endl << endl << "Testing sortPersonArrayByAge" << endl;

    cout << "unsorted: " << endl;
    for (int i = 0; i < 25; i++)
    {
        ptr[i] = new Person();
        ptr[i]->age = rand()%10;
        ptr[i]->name = "Bob";
        displayAPerson(cout, ptr[i]);
    }
    cout << endl << "sorted: " << endl;

    sortPersonArrayByAge(ptr,25);
    for (int i = 0; i < 25; i++)
    {
        displayAPerson(cout, ptr[i]);
    }
    //testing sortPersonArrayByName

    cout << endl << endl << "Testing sortPersonArrayByName" << endl;
    cout << "unsorted: " << endl;
    for (int i = 0; i < 25; i++)
    {
        ptr[i] = new Person();
        ptr[i]->age = rand()%10;
        ptr[i]->name = to_string(rand()%10);
        displayAPerson(cout, ptr[i]);
    }
    cout << "Sorted: " << endl;
    sortPersonArrayByName(ptr,25);
    for (int i = 0; i < 25; i++)
    {
        displayAPerson(cout,ptr[i]);
    }

    //testing findAPerson
    cout << "Testing findAPerson" << endl;

    cout << "unsorted: " << endl;
    for (int i = 0; i < 25; i++)
    {
        ptr[i] = new Person();
        ptr[i]->age = rand()%10;
        ptr[i]->name = to_string(rand()%10);
        displayAPerson(cout, ptr[i]);
    }
    string findMe = to_string(rand()%10);
    cout << "Person to find: " << findMe << endl;
    cout << "Found Person: " << endl;
    displayAPerson(cout,findAPerson(ptr,25,findMe));
    return 0;   
}