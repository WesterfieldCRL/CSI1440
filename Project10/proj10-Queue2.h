#include "proj10-MyVector.h"

#ifndef QUEUE2_H
#define QUEUE2_H

template <class T>
class Queue2 : public MyVector<T> {
private:
  int front, rear;

public:
  Queue2();
  void enqueue( T );
  void dequeue( T& ); // throws BADINDEX
};

template <class T>
Queue2<T>::Queue2()
{
    this->front = -1;
    this->rear = -1;
}

template <class T>
void Queue2<T>::enqueue(T n)
{
    if (this->size == this->capacity)
    {
        this->capacity+=5;
        T *temp = new T[this->capacity];
        rear = -1;
        for (int i = 0; i < this->size; i++)
        {
            front = (front+1) % this->size;
            rear++;
            temp[rear] = this->data[front];
        }
        delete [] temp;
        this->data = temp;
        front = -1;
    }
    rear = (rear+1)%this->capacity;
    this->data[rear] = n;
    this->size++;
}

template <class T>
void Queue2<T>::dequeue(T& n) // throws BADINDEX
{
    if (this->size == 0)
    {
        throw BADINDEX();
    }
    front = (front+1)%this->capacity;
    n = this->data[front];

    this->size--;
}

#endif