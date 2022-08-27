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

    Person p;

    //testing getAPersonFromStream
    string paul = "Paul Daniels (eldritch god), 405";
    stringstream input;
    input << paul;

    getAPersonFromStream(input, &p);
    cout << p.name << endl;
    cout << p.age << endl;

    


    
    return 0;   
}