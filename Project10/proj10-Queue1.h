#include "proj10-MyVector.h"

#ifndef QUEUE1_H
#define QUEUE1_H

template <class T>
class Queue1 : public MyVector<T> {
public:
  void enqueue( T );
  void dequeue( T& ); // throws BADINDEX
};

template <class T>
void Queue1<T>::enqueue(T n)
{
    this->pushFront(n);
}

template <class T>
void Queue1<T>::dequeue(T& n) // throws BADINDEX
{
    this->popBack(n);
}

#endif