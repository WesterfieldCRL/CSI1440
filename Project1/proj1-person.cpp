/**
 * file: proj1-person.cpp
 * author: Wesley Anastasi
 * course: CSI 1440
 * assignment: project 1
 * due date: 8/29/2022
 *
 * date modified: 8/29/2022
 * - created file
 * 
 * implementation of the person related functions
 */

#include "proj1-person.hpp"

/**
 * getAPersonFromStream
 *
 * This function extracts the name and age from the istream, 
 * and assigns them to the appropriate values in person
 *
 * Parameters:
 * input: the istream, passed by reference
 * p: a pointer to the person object
 *
 * Output:
 * return: returns the istream that was inputted
 * reference parameters: none
 * stream: none
 */

istream &getAPersonFromStream(istream &input, Person *p)
{
    string temp;
    getline(input, p->name,',');
    getline(input, temp);
    p->age = stod(temp);
    return input;
}

void sortPersonArrayByAge(Person **, int)
{
    
}