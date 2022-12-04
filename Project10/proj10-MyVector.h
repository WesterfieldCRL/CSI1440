/**
 * file: proj10-MyVector.h
 * author: Wesley Anastasi
 * course: CSI 1440
 * assignment: Project 10
 * due date: 12/5/2022
 *
 * date modified: 11/28/2022
 * - created file
 * 
 * MyVector
 */

#include "proj10-ContainerIfc.h"

#ifndef MYVECTOR_H
#define MYVECTOR_H

template <class T>
class MyVector : public ContainerIfc<T> {
public:
  MyVector ();
  ~MyVector ();
  MyVector (const MyVector&);
  MyVector<T>& operator = (const MyVector&);
  MyVector<T>& pushFront(T);
  MyVector<T>& pushBack(T);
  MyVector<T>& popFront(T&); // throws BADINDEX
  MyVector<T>& popBack(T&);  // throws BADINDEX
  T  front();        // throws BADINDEX
  T  back();        // throws BADINDEX
  T&  operator [](int);   // throws BADINDEX
  int getSize();
  bool isEmpty();
  void erase();

protected:
  T  *data;
  int size;
  int capacity;
  void grow();
  void shiftRight();
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