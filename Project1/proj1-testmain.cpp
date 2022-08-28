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
#include <sstream>
#include "proj1-person.hpp"

using namespace std;

int main() 
{
    srand(time(0));
    Person p;
    Person *ptr[25];

    //testing getAPersonFromStream
    cout << "Testing getAPersonFromStream" << endl;
    string paul = "Paul Daniels (eldritch god), 405";
    stringstream input;
    input << paul;

    getAPersonFromStream(input, &p);
    displayAPerson(cout,&p);
    cout << endl;

    //testing sortPersonArrayByAge
    
    cout << endl << endl << "Testing sortPersonArrayByAge" << endl;

    cout << "unsorted: " << endl;
    for (int i = 0; i < 25; i++)
    {
        ptr[i] = new Person();
        ptr[i]->age = rand()%10;
        ptr[i]->name = "Bob";
        displayAPerson(cout, ptr[i]);
        cout << endl;
    }
    cout << endl << "sorted: " << endl;

    sortPersonArrayByAge(ptr,25);
    for (int i = 0; i < 25; i++)
    {
        displayAPerson(cout, ptr[i]);
        cout << endl;
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
        cout << endl;
    }
    cout << "Sorted: " << endl;
    sortPersonArrayByName(ptr,25);
    for (int i = 0; i < 25; i++)
    {
        displayAPerson(cout,ptr[i]);
        cout << endl;
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
        cout << endl;
    }
    string findMe = to_string(rand()%10);
    cout << "Person to find: " << findMe << endl;
    cout << "Found Person: " << endl;
    displayAPerson(cout,findAPerson(ptr,25,findMe));

    return 0;   
}