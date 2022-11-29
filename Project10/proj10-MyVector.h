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



#endif