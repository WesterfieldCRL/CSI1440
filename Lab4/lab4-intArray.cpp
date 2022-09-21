#include "lab4-IntArray.h"

IntArray::IntArray() {
   this->size = 0;
   this->capacity = 5;
   this->data = new int[capacity];
   this->data[0] = '\0';
}

IntArray::~IntArray()
{
    delete [] this->data;
}
IntArray::IntArray(const IntArray &n)
{
    this->capacity = 5;
    this->size = 0;
    this->data = new int[5];
    while (n.data[this->size] != '\0')
    {
        this->data[size] = n.data[size];
        this->size++;
        if (this->size == this->capacity)
        {
            capacity+=5;
            int *temp = this->data;
            this->data = new int[this->capacity];
            for (int i = 0; i < this->size; i++)
            {
                this->data[i] = temp[i];
            }
            this->data[this->size] = '\0';
            delete []temp;
        }
    }
}
IntArray& IntArray::operator = (const IntArray &n)
{
    if (this != &n)
    {
        delete [] this->data;
        this->capacity = n.capacity;
        this->size = n.size;
        this->data = new int[this->capacity];
        for (int i = 0; i < this->size; i++)
        {
            this->data[i] = n.data[i];
        }
    }
    return *this;
}
int IntArray::getVal(int ndx)
{
    return this->data[ndx];
}
int IntArray::getCapacity()
{
    return this->capacity;
}
int IntArray::getSize()
{
    return this->size;
}
void IntArray::insertVal(int val)
{
    if (this->size+1 == this->capacity)
    {
        this->capacity+=5;
        int *temp = this->data;
        this->data = new int[this->capacity];
        for (int i = 0; i < this->size; i++)
        {
            this->data[i] = temp[i];
        }
        this->data[this->size] = '\0';
        delete []temp;
    }
    data[this->size] = val;
    data[this->size+1] = '\0';
    this->size++;
}
int IntArray::removeVal()
{
    int temp = this->data[this->size-1];
    this->data[this->size-1] = '\0';
    return temp;
}