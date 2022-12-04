#include "proj10-MyList.h"
#include <ostream>

using namespace std;

#ifndef QUEUE3_H
#define QUEUE3_H

template <class T>
class Queue3 : public MyList<T> {
public:
  void enqueue( T );
  void dequeue( T& ); // throws BADINDEX
};

template <class T>
void Queue3<T>::enqueue(T n)
{
    this->pushFront(n);
}

template <class T>
void Queue3<T>::dequeue(T& n) // throws BADINDEX
{
    this->popBack(n);
}


#endif