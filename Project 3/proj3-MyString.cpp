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
    this->size = 0;
    this->data = new char[10];
    this->data[0] = '\0';
}

MyString::MyString(const char *n)
{
    this->capacity = 10;
    this->size = 0;
    this->data = new char[10];
    while (n[size] != '\0')
    {
        this->data[size] = n[size];
        size++;
        if (size == capacity)
        {
            capacity*=2;
            char *temp = this->data;
            this->data = new char[capacity];
            for (int i = 0; i < this->size; i++)
            {
                this->data[i] = temp[i];
            }
            data[this->size] = '\0';
            delete temp;
        }
    }

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

}

MyString MyString::operator + (const MyString& n) const
{
    int tempCapacity = this->capacity;
    int tempSize;
    char *temp = new char[this->capacity];

    for (tempSize = 0; tempSize < this->size; tempSize++)
    {
        temp[tempSize] = this->data[tempSize];
    }

    for (int i = 0; i < n.length(); i++)
    {
        if (tempSize >= tempCapacity)
        {
            tempCapacity*=2;
            char *temp2 = this->data;
            temp = new char[tempCapacity];
            for (int a = 0; a < tempSize; a++)
            {
                temp[i] = temp2[i];
            }
            delete temp2;
        }
        temp[i+tempSize] = n.data[i];
        tempSize++;
    }
    temp[tempSize] = '\0';

    for (int i = 0; temp[i] != '\0'; i++)
    {
        cout << temp[i];
    }
    cout << endl;


    return *this;
}

void MyString::getline(istream&, char delimit)
{

}

int MyString::length() const
{
    return this->size;
}

ostream& operator<< (ostream& out, MyString&)
{
   return out;
}