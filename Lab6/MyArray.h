/**
 * file: MyArray.h
 * author: Wesley Anastasi
 * course: CSI 1440
 * assignment: Lab 6 
 * due date: 10/25/2022
 *
 * date modified: 10/25/2022
 * - created file
 * 
 * MyArray class
 */

#ifndef MYARRAY_H
#define MYARRAY_H

#include "ContainerIfc.h"
#include <sstream>

template <class T>
class MyArray : public ContainerIfc<T> {
  private:
      T *data;
      int capacity, size;

  public:
      MyArray();
      MyArray(MyArray<T>&);
      void operator~();
      MyArray<T> operator=(MyArray<T>&);
      string toString();
      int getSize();
      int getCapacity();
      bool isEmpty();
      T& operator[](int);
      MyArray<T>& popBack(T &);
      MyArray<T>& pushBack(T);
};

/** 
 * MyArray
 * 
 * This function constructs MyArray
 * 
 * Parameters: 
 *      none
 * 
 * Output: 
 *      return:  none
 *      reference parameters: none 
 *      stream:  none 
 */
template <class T>
MyArray<T>::MyArray(){
   this->capacity = 5;
   this->size = 0;
   this->data = new T[this->capacity];
}

/** 
 * MyArray
 * 
 * This function constructs MyArray
 * 
 * Parameters: 
 *      a: what MyArray is going to be equal to
 * 
 * Output: 
 *      return:  none
 *      reference parameters: a
 *      stream:  none 
 */
template <class T>
MyArray<T>::MyArray(MyArray<T>& a)
{
    this->capacity = a.getCapacity();
    this->size = a.getSize();
    this->data = new T[this->capacity];
    for (int i = 0; i < this->size; i++)
    {
        this->data[i] = a.data[i];
    }
}

/** 
 * toString
 * 
 * This function returns a string representation of the object
 * 
 * Parameters: 
 *      none
 * 
 * Output: 
 *      return:  string
 *      reference parameters: none 
 *      stream:  none 
 */
template <class T>
string MyArray<T>::toString()
{
    stringstream result;
    result << this->size << endl;
    result << this->capacity << endl;
    for (int i = 0; i < this->size; i++)
    {
        result << this->data[i] << "\t";
    }
    result << endl;
    return result.str();
}

/** 
 * setEvaluation
 * 
 * This function deletes MyArray
 * 
 * Parameters: 
 *      none
 * 
 * Output: 
 *      return:  none
 *      reference parameters: none 
 *      stream:  none 
 */
template <class T>
void MyArray<T>::operator~()
{
    delete [] this->data;
}

/** 
 * operator=
 * 
 * This function sets the object equal to a
 * 
 * Parameters: 
 *      a: object to set MyArray to
 * 
 * Output: 
 *      return:  none
 *      reference parameters: a
 *      stream:  none 
 */
template <class T>
MyArray<T> MyArray<T>::operator=(MyArray<T>& a)
{
    this->capacity = a.getCapacity();
    this->size = a.getSize();
    delete [] this->data;
    this->data = new T[this->capacity];
    for (int i = 0; i < this->size; i++)
    {
        this->data[i] = a[i];
    }
    return a;
}

/** 
 * getSize
 * 
 * This function returns MyArray's size
 * 
 * Parameters: 
 *      none
 * 
 * Output: 
 *      return:  int
 *      reference parameters: none 
 *      stream:  none 
 */
template <class T>
int MyArray<T>::getSize()
{
    return this->size;
}

/** 
 * getCapacity
 * 
 * This function returns MyArray's capacity
 * 
 * Parameters: 
 *      none
 * 
 * Output: 
 *      return:  int
 *      reference parameters: none 
 *      stream:  none 
 */
template <class T>
int MyArray<T>::getCapacity()
{
    return this->capacity;
}

/** 
 * isEmpty
 * 
 * This function checks to see if MyArray is empty
 * 
 * Parameters: 
 *      none
 * 
 * Output: 
 *      return:  bool
 *      reference parameters: none 
 *      stream:  none 
 */
template <class T>
bool MyArray<T>::isEmpty()
{
    if (this->size == 0)
    {
        return true;
    }
    return false;
}

/** 
 * operator[]
 * 
 * This function returns the data of the provided index
 * 
 * Parameters: 
 *      ndx: index of the data
 * 
 * Output: 
 *      return:  T
 *      reference parameters: T
 *      stream:  none 
 */
template <class T>
T& MyArray<T>::operator[](int ndx)
{
    if (ndx > this->size-1 || ndx < 0)
    {
        throw BADINDEX();
    }
    return this->data[ndx];
}

/** 
 * popBack
 * 
 * This function removes the last item from MyArray
 * 
 * Parameters: 
 *      thing: the last item is stored here
 * 
 * Output: 
 *      return:  MyArray<T>
 *      reference parameters: thing, MyArray<T>
 *      stream:  none 
 */
template <class T>
MyArray<T>& MyArray<T>::popBack(T& thing)
{
    if (this->size > 0)
    {
        thing = this->data[size-1];
        this->size--;
        if (this->size < this->capacity/4 && this->capacity > 5)
        {
            this->capacity -= 5;
            T *temp = this->data;
            this->data = new T[this->capacity];
            for (int i = 0; i < this->size; i++)
            {
                this->data[i] = temp[i];
            }
            delete [] temp;
        }
    }
    else
    {
        throw BADINDEX();
    }
    return *this;
}

/** 
 * pushBack
 * 
 * This function adds the item to the end of MyArray
 * 
 * Parameters: 
 *      thing: item to be added
 * 
 * Output: 
 *      return:  MyArray<T>
 *      reference parameters: MyArray<T>
 *      stream:  none 
 */
template <class T>
MyArray<T>& MyArray<T>::pushBack(T thing)
{
    this->data[size] = thing;
    this->size++;
    if (this->size > this->capacity)
    {
        this->capacity += 5;
        T *temp = this->data;
        this->data = new T[this->capacity];
        for (int i = 0; i < this->size; i++)
        {
            this->data[i] = temp[i];
        }
        delete [] temp;
    }
    return *this;
}

#endif