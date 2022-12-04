/**
 * file: proj10-Queue3.h
 * author: Wesley Anastasi
 * course: CSI 1440
 * assignment: project 10
 * due date: 12/5/2022
 *
 * date modified: 12/4/2022
 * - created file
 * 
 * Queue3
 */

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

/** 
 * enqueue
 * 
 * This function adds n to the back of the queue
 * 
 * Parameters: 
 *      n: number to be added
 * 
 * Output: 
 *      return:  none
 *      reference parameters: none 
 *      stream:  none 
 */

template <class T>
void Queue3<T>::enqueue(T n)
{
    this->pushFront(n);
}

/** 
 * dequeue
 * 
 * This function removes the first element from the queue
 * 
 * Parameters: 
 *      n: number that was removed
 * 
 * Output: 
 *      return:  none
 *      reference parameters: n
 *      stream:  none 
 */

template <class T>
void Queue3<T>::dequeue(T& n) // throws BADINDEX
{
    this->popBack(n);
}


#endif