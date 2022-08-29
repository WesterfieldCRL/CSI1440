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
 * reference parameters: array of Person's
 * stream: istream, input
 */

istream &getAPersonFromStream(istream &input, Person *p)
{
    string temp;
    getline(input, p->name,','); 
    input >> p->age;
    getline(input, temp, '\n');
    return input;
}

/**
 * sortPersonArrayByAge
 *
 * sorts the array of Person's by name in ascending order with selection sort
 *
 * Parameters:
 * p: array of Person's
 * num: num of items in the array
 *
 * Output:
 * return: none
 * reference parameters: Array of pointers to array of persons
 * stream: none
 */

void sortPersonArrayByAge(Person **p, int num)
{
    int lowestIndex = 0;
    int temp;
    for (int i = 1; i < num; i++)
    {
        for (int a = i; a < num; a++)
        {
            if (p[a]->age < p[lowestIndex]->age)
            {
                lowestIndex = a;
            }
        }
        swap(p[i-1],p[lowestIndex]);
        lowestIndex = i;
    }
}

/**
 * sortPersonArrayByName
 *
 * sorts the array of Person's by age in ascending order with bubble sort
 *
 * Parameters:
 * p: array of Person's
 * num: num of items in the array
 *
 * Output:
 * return: none
 * reference parameters: Array of pointers to array of persons
 * stream: none
 */

void sortPersonArrayByName(Person **p, int num)
{
    bool sorted = true;
    
    while (sorted)
    {
        sorted = false;
        for (int i = 0; i < num-1; i++)
        {
            if (p[i]->name > p[i+1]->name)
            {
                swap(p[i],p[i+1]);
                sorted = true;
            }
        }
    }
}

/**
 * findAPerson
 *
 * searches for the input with linear search
 *
 * Parameters:
 * p: array of Person's
 * num: length of array
 * word: person to search for
 *
 * Output:
 * return: Person object
 * reference parameters: Array of pointers to array of persons
 * stream: none
 */

Person * findAPerson(Person **p, int num, string input)
{
    int returnIndex;
    for (int i = 0; i < num; i++)
    {
        if (input == p[i]->name)
        {
            i = num;
            returnIndex = 1;
        }
    }
    return p[returnIndex];
}

/**
 * displayAPerson
 *
 * writes a Person 
 *
 * Parameters:
 * output: what the function is sending the information too
 * p: person object
 *
 * Output:
 * return: none
 * reference parameters: Array of Person's
 * stream: ostream, output
 */

void displayAPerson(ostream &output, const Person *p)
{
    output << p->name << ", " << p->age << endl;
}