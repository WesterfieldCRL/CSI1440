#ifndef PROJ3_MYSTRING_H
#define PROJ3_MYSTRING_H

#include <iostream>
#include <fstream>

using namespace std;

class MyString
{
    private:

    char list;

    public:

    // Default Constructor
    MyString( );

    // Constructor with an initialization character string
    MyString(const char *);

    // Destructor
    ~MyString( );

    // Copy constructor
    MyString(const MyString &);

    // Overloaded assignment operator, make a copy of MyString object
    MyString& operator = (const MyString&);

    // Overloaded equivalence relational operator
    bool operator == (const MyString&) const;

    // Overloaded [ ] should return a char by reference
    char& operator [ ] (int);

    // Overloaded += operator, use to concatenate two MyStrings
    void operator += (const MyString&);

    // Create a new MyString object that is the concatenation of two MyString objects
    MyString operator + (const MyString&) const;

    // Reads an entire line from a istream. Lines are terminated with delimit which is newline 
    // ‘\n’ by default
    void getline(istream&, char delimit = '\n');

    // Return the length of the string
    int length( ) const;

    // Overloaded insertion operator
    friend ostream& operator<< (ostream&, MyString&);

};

#endif