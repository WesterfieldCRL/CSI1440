/**
 * file: MyVector.h
 * author: Wesley Anastasi
 * course: CSI 1440
 * assignment: project 7
 * due date: 11/7/2022
 *
 * date modified: 11/5/2022
 * - created file
 * 
 * Template class
 */

#include "proj7-ContainerIfc.h"

#include <iostream>

#ifndef MYVECTOR_H
#define MYVECTOR_H

using namespace std;

template <class T>
class MyVector : public ContainerIfc<T> 
{
  public:

    /** 
     * MyVector ()
     * 
     * creates a MyVector object with size = 0, capacity = 10
     * 
     * Parameters: 
     *      none
     * 
     * Output: 
     *      return:  none
     *      reference parameters: none 
     *      stream:  none 
     */
      MyVector ();

    /** 
     * ~MyVector
     * 
     * all memory allocated to the MyVector is deleted
     * 
     * Parameters: 
     *      none
     * 
     * Output: 
     *      return:  none
     *      reference parameters: none 
     *      stream:  none 
     */
      ~MyVector ();

    /** 
     * MyVector
     * 
     * creates a MyVector as a copy of the provided MyVector object
     * 
     * Parameters: 
     *      MyVector, object being copied
     * 
     * Output: 
     *      return:  none
     *      reference parameters: MyVector
     *      stream:  none 
     */
      MyVector (const MyVector&);

      /** 
     * operator=
     * 
     * makes an exact copy of the data from the provided MyVector
     * into this MyVector
     * 
     * Parameters: 
     *      MyVector, object being copied
     * 
     * Output: 
     *      return:  reference to self
     *      reference parameters: MyVector
     *      stream:  none 
     */
      MyVector<T>& operator = (const MyVector&);

    /** 
     * pushFront
     * 
     * adds data element e to the front of the vector
     * 
     * Parameters: 
     *      e, data to push to front
     * 
     * Output: 
     *      return:  reference to self
     *      reference parameters: none 
     *      stream:  none 
     */
      MyVector<T>& pushFront(T e);

      /** 
     * pushBack
     * 
     * adds data element e in end of vector
     * 
     * Parameters: 
     *      e, data to push to back
     * 
     * Output: 
     *      return:  reference to self
     *      reference parameters: none 
     *      stream:  none 
     */
      MyVector<T>& pushBack(T);

      /** 
     * popFront
     * 
     * removes element from front of vector
     * 
     * Parameters: 
     *      e, set to the removed element
     * 
     * Output: 
     *      return:  reference to self
     *      reference parameters: e
     *      stream:  none 
     */
      MyVector<T>& popFront(T& e);

      /** 
     * popBack
     * 
     * removes a data element from the rear (end) of the data structure (MyVector)
     * 
     * Parameters: 
     *      e, set to the removed element
     * 
     * Output: 
     *      return:  reference to self
     *      reference parameters: e
     *      stream:  none 
     */
      MyVector<T>& popBack(T&);

    /** 
     * front
     * 
     * returns a copy of the first data item in the MyVector
     * 
     * Parameters: 
     *      none
     * 
     * Output: 
     *      return:  T
     *      reference parameters: none
     *      stream:  none 
     */
      T  front();

    /** 
     * back
     * 
     * returns a copy of the last data item in MyVector
     * 
     * Parameters: 
     *      none
     * 
     * Output: 
     *      return:  T
     *      reference parameters: none
     *      stream:  none 
     */
      T  back();

    /** 
     * operator []
     * 
     * returns the data of the provided ndx
     * 
     * Parameters: 
     *      none
     * 
     * Output: 
     *      return:  T
     *      reference parameters: none
     *      stream:  none 
     */
      T&  operator [](int ndx);

    /** 
     * getSize
     * 
     * returns size of MyVector
     * 
     * Parameters: 
     *      none
     * 
     * Output: 
     *      return:  int
     *      reference parameters: none
     *      stream:  none 
     */
      int getSize();

    /** 
     * isEmpty
     * 
     * returns true if there is no data in the vector
     * 
     * Parameters: 
     *      none
     * 
     * Output: 
     *      return:  boolean
     *      reference parameters: none
     *      stream:  none 
     */
      bool isEmpty();

    /** 
     * erase
     * 
     * erases the vector
     * 
     * Parameters: 
     *      none
     * 
     * Output: 
     *      return:  none
     *      reference parameters: none
     *      stream:  none 
     */
      void erase();

  private:
      T  *data;
      int size;
      int capacity;

    /** 
     * grow
     * 
     * increases the capacity of data by doubling the previous value and allocating the appropriate memory for data
     * 
     * Parameters: 
     *      none
     * 
     * Output: 
     *      return:  none
     *      reference parameters: none
     *      stream:  none 
     */
      void grow();

    /** 
     * shiftRight
     * 
     * shifts all values in the array one space to the right
     * 
     * Parameters: 
     *      none
     * 
     * Output: 
     *      return:  none
     *      reference parameters: none
     *      stream:  none 
     */
      void shiftRight();

    /** 
     * shiftLeft
     * 
     * shifts all values in the array one space to the left
     * 
     * Parameters: 
     *      none
     * 
     * Output: 
     *      return:  none
     *      reference parameters: none
     *      stream:  none 
     */
      void shiftLeft();
};

template <class T>
MyVector<T>::MyVector ()
{
  this->size = 0;
  this->capacity = 10;
  this->data = new T[10];
}

template <class T>
MyVector<T>::~MyVector ()
{
  delete [] this->data;
}

template <class T>
MyVector<T>::MyVector (const MyVector& v)
{
  this->size = 0;
  this->capacity = 10;
  this->data = new T[10];
  for (int i = 0; i < v.size; i++)
  {
    this->data[i] = v.data[i];
    this->size++;
    if (this->size >= this->capacity)
    {
      grow();
    }
  }
}

template <class T>
MyVector<T>& MyVector<T>::operator = (const MyVector& v)
{
  if (this != &v)
  {
    int temp = v.size;
    this->size = 0;
    this->capacity = 10;

    delete [] this->data;

    this->data = new T[10];

    for (int i = 0; i < temp; i++)
    {
      this->data[i] = v.data[i];
      this->size++;
      if (this->size >= this->capacity)
      {
        grow();
      }
    }
  }

  return *this;
}

template <class T>
MyVector<T>& MyVector<T>::pushFront(T e)
{
  this->shiftRight();
  this->data[0] = e;

  if (this->size >= this->capacity)
  {
    this->grow();
  }
  
  return *this;
}

template <class T>
MyVector<T>& MyVector<T>::pushBack(T e)
{
  this->data[this->size] = e;
  this->size++;

  if (this->size >= this->capacity)
  {
    this->grow();
  }

  return *this;
}

template <class T>
MyVector<T>& MyVector<T>::popFront(T& e)
{
  e = this->data[0];
  this->shiftLeft();
  return *this;
}

template <class T>
MyVector<T>& MyVector<T>::popBack(T& e)
{
  if (this->size <= 0)
  {
    throw BADINDEX();
  }
  else
  {
    e = this->data[this->size-1];
    this->size--;
    return *this;
  }
  
}

template <class T>
T  MyVector<T>::front()
{
  return this->data[0];
}

template <class T>
T  MyVector<T>::back()
{
  return this->data[this->size-1];
}

template <class T>
T&  MyVector<T>::operator [](int ndx)
{
  if (this->size <= ndx || ndx < 0)
  {
    throw BADINDEX();
  }
  else
  {
    return this->data[ndx];
  }
}

template <class T>
int MyVector<T>::getSize()
{
  return this->size;
}

template <class T>
bool MyVector<T>::isEmpty()
{
  if (this->size <= 0)
  {
    return true;
  }
  return false;
}

template <class T>
void MyVector<T>::erase()
{
  delete this->data;
  this->size = 0;
  this->capacity = 10;
  this->data = new T[10];
}

template <class T>
void MyVector<T>::grow()
{
  this->capacity *=2;
  T *temp = this->data;
  this->data = new T[this->capacity];
  for (int i = 0; i < this->size; i++)
  {
    this->data[i] = temp[i];
  }
  delete [] temp;
}

template <class T>
void MyVector<T>::shiftRight()
{
  for (int i = this->size; i > 0; i--)
  {
    this->data[i] = this->data[i-1];
  }
  this->size++;
}

template <class T>
void MyVector<T>::shiftLeft()
{
  for (int i = 0; i < this->size-1; i++)
  {
    this->data[i] = this->data[i+1];
  }
  this->size--;
}

#endif