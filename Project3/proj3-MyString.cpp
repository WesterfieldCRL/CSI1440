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
    while (n[this->size] != '\0')
    {
        this->data[size] = n[size];
        this->size++;
        if (this->size == this->capacity)
        {
            capacity*=2;
            char *temp = this->data;
            this->data = new char[this->capacity];
            for (int i = 0; i < this->size; i++)
            {
                this->data[i] = temp[i];
            }
            this->data[this->size] = '\0';
            delete []temp;
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
        for (int i = 0; i < this->size; i++)
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
    MyString temp = *this + n;

    *this = temp;

}

MyString MyString::operator + (const MyString& n) const
{
    int tempCapacity = this->capacity;
    int tempSize;
    char *newString = new char[this->capacity];

    for (tempSize = 0; tempSize < this->size; tempSize++)
    {
        newString[tempSize] = this->data[tempSize];
    }

    

    for (int i = 0; i < n.length(); i++)
    {
        newString[tempSize] = n.data[i];
        tempSize++;
        if (tempSize >= tempCapacity)
        {
            tempCapacity*=2;
            char *temp2 = newString;
            newString = new char[tempCapacity];
            
            for (int a = 0; a < tempSize; a++)
            {
                newString[a] = temp2[a];
            }
            
            
            delete []temp2;
        }
        
    }
    newString[tempSize] = '\0';

    return newString;
}

void MyString::getline(istream& in, char delimit)
{
    char inputChar;
    delete [] this->data;
    this->capacity = 10;
    this->size = 0;
    this->data = new char[10];
    in.get(inputChar);
    while(inputChar!=delimit)
    {
        this->data[size] = inputChar;
        size++;
        if (size == capacity)
        {
            capacity*=2;
            char *temp = this->data;
            this->data = new char[this->capacity];
            for (int i = 0; i < this->size; i++)
            {
                this->data[i] = temp[i];
            }
            this->data[this->size] = '\0';
            delete[] temp;
        }
        in.get(inputChar);
    }
}

int MyString::length() const
{
    return this->size;
}

ostream& operator<< (ostream& out, MyString& n)
{

    for (int i = 0; i < n.length(); i++)
    {
        cout << n[i];
    }
    return out;
}