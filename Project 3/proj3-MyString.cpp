/**
 * file: proj3-MyString.cpp
 * author: Wesley Anastasi
 * course: CSI 1440
 * assignment: Project 3
 * due date: 9/19/2022
 *
 * date modified: 9/12/2022
 * - created file
 * 
 * Project 3 MyString functions
 */

#include "proj3-MyString.h"



MyString::MyString()
{
    this->capacity = 10;
    this->size = 9;
    this->data = new char[10];
}

MyString::MyString(const char *n)
{
    this->capacity = 10;
    this->size = 9;
    this->data = new char[10];
    this->data[0] = *n;
}

MyString::~MyString()
{
   delete [] this->data;
}

MyString::MyString(const MyString &n)
{
    this->capacity = n.capacity;
    this->size = n.size;
    this->data = new char[this->capacity];
    for (int i = 0; i < this->size; i++)
    {
        this->data[i] = n.data[i];
    }
}

MyString& MyString::operator = (const MyString& n)
{
    if (this != &n)
    {
        delete [] this->data;
        this->capacity = n.capacity;
        this->size = n.size;
        this->data = new char[this->capacity];
        for (int i = 0; i < this->size; i++)
        {
            this->data[i] = n.data[i];
        }
    }
    return *this;
}

bool MyString::operator == (const MyString& n) const
{
    bool result = true;

    if (this->size == n.size)
    {
        for (int i = 0; i < size; i++)
        {
            if (this->data[i] != n.data[i])
            {
                result = false;
            }
        }
    }
    else
    {
        result = false;
    }

    return result;
}

char& MyString::operator [](int ndx)
{
    return this->data[ndx];
}

void MyString::operator += (const MyString& n)
{
    this->size += n.size;
    while (this->size >= this->capacity)
    {
        this->capacity *= 2;
    }



}

MyString MyString::operator + (const MyString&) const
{
    
}

void MyString::getline(istream&, char delimit = '\n')
{

}

int MyString::length() const
{

}

ostream& operator<< (ostream&, MyString&)
{
   
}