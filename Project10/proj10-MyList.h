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
  MyList<T>& operator = (const MyList &);
  MyList<T>& pushFront(T);
  MyList<T>& pushBack(T);
  MyList<T>& popFront(T&); // throws BADINDEX
  MyList<T>& popBack(T&);  // throws BADINDEX
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

template <class T>
MyList<T>::MyList()
{
  this->head = NULL;
  this->tail = NULL;
}

template <class T>
MyList<T>::~MyList()
{
  Node<T> *temp;
  while (this->head != NULL)
  {
    temp = this->head;
    this->head = this->head->next;
    delete temp;
  }
}

template <class T>
MyList<T>::MyList(const MyList &v)
{
  this->head = new Node<T>(v->head->data);
  Node<T> *node = v->head;
  Node<T> *temp = this->head;
  while (this->node != NULL) 
  {
    temp->next = new Node<T>(node->data);
    node = node->next;
    temp = temp->next;
  }
  temp->next = NULL;
}

template <class T>
MyList<T>& MyList<T>::operator=(const MyList &v)
{
  if (this != &v)
  {
    erase();
    this->head = new Node<T>(v->head->data);
    Node<T> *node = v->head;
    Node<T> *temp = this->head;
    while (this->node != NULL) 
    {
      temp->next = new Node<T>(node->data);
      node = node->next;
      temp = temp->next;
    }
    temp->next = NULL;
    this->tail = temp;
  }
}

template <class T>
MyList<T>& MyList<T>::pushFront(T n)
{
  Node<T> *temp = new Node<T>(n);
  temp->next = this->head;
  this->head = temp;

  return *this;
}

template <class T>
MyList<T>& MyList<T>::pushBack(T n)
{
  this->tail->next = new Node<T>(n);
  this->tail = this->tail->next;
  this->tail->next = NULL;
  return *this;
}

template <class T>
MyList<T>& MyList<T>::popFront(T& n) // throws BADINDEX
{
  if (this->head == NULL)
  {
    throw BADINDEX();
  }

  Node<T> *temp = this->head;
  this->head = this->head->next;
  n = temp->data;
  delete temp;

  return *this;
}

template <class T>
MyList<T>& MyList<T>::popBack(T& n)  // throws BADINDEX
{
  if (this->head == NULL)
  {
      throw BADINDEX();
  }

  Node<T> *temp = this->head;

  if (temp->next == NULL)
  {
      n = temp->data;
      delete temp;
      this->head = NULL;
  }
  else
  {
      while (temp->next->next != NULL)
      {
          temp = temp->next;
      }
      n = temp->next->data;
      delete temp->next;
      temp->next = NULL;
  }
  
  return *this;
}

template <class T>
int MyList<T>::getSize()
{
  Node<T> *temp = this->head;
  int size = 0;
  while (temp != NULL)
  {
      temp = temp->next;
      size++;
  }

  return size;
}

template <class T>
bool MyList<T>::isEmpty()
{
  if (this->head == NULL)
  {
      return true;
  }
  return false;
}

template <class T>
T MyList<T>::front()      // throws BADINDEX
{
  if (this->head == NULL)
  {
      throw BADINDEX();
  }
  return this->head->data;
}

template <class T>
T MyList<T>::back()      // throws BADINDEX
{
  if (this->head == NULL)
  {
    throw BADINDEX();
  }
  return this->tail->data;
}

template <class T>
T& MyList<T>::operator[](int n) // throws BADINDEX
{
  if (n < 0 || n > this->getSize())
  {
      throw BADINDEX();
  }

  Node<T> *temp = this->head;

  for (int i = 0; i < n; i++)
  {
      temp = temp->next;
  }

  return temp->data;
}

template <class T>
void deleteEm(Node<T> *node)
{
    if (node != NULL)
    {
        deleteEm(node->next);
        delete node;
    }
}

template <class T>
void MyList<T>::erase()
{
    deleteEm(this->head);
    this->head = NULL;
}
#endif