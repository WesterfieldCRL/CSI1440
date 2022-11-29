/**
 * file: proj10-MyList.h
 * author: Wesley Anastasi
 * course: CSI 1440
 * assignment: Project 10
 * due date: 12/5/2022
 *
 * date modified: 11/28/2022
 * - created file
 * 
 * MyList
 */

#include "proj10-ContainerIfc.h"
#include "proj10-Node.h"

#ifndef MYLIST_H
#define MYLIST_H

template <class T>
class MyList : public ContainerIfc <T> {
public:
  MyList();
  ~ MyList();
  MyList(const MyList &);
  MyList <T>& operator = (const MyList &);
  MyList <T>& pushFront(T);
  MyList <T>& pushBack(T);
  MyList <T>& popFront(T&); // throws BADINDEX
  MyList <T>& popBack(T&);  // throws BADINDEX
  int getSize();
  bool isEmpty();
  T front();      // throws BADINDEX
  T back();      // throws BADINDEX
  T& operator [](int); // throws BADINDEX
  void erase();

private:
  Node<T> *head;
  Node<T> *tail;
};

#endif