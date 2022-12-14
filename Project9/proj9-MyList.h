/**
 * file: proj9-MyList.h
 * author: Wesley Anastasi
 * course: CSI 1440
 * assignment: project 9
 * due date: 11/28/2022
 *
 * date modified: 11/14/2022
 * - created file
 * 
 * date modifiedL 11/18/2022
 * - fixing nonworking functions
 * 
 * Linked List implementation
 */

#include "proj9-ContainerIfc.h"
#include "proj9-Node.h"

#include <iostream>

using namespace std;

template <class T>
class MyList : public ContainerIfc <T> {
	public:
		MyList();
		~ MyList();
		MyList(const MyList&);
		MyList <T>& operator = (const MyList&);
		MyList <T>& pushFront(T);
		MyList <T>& pushBack(T);
		MyList <T>& popFront(T&);
		MyList <T>& popBack(T&);
		int getSize();
		bool isEmpty();
		T front();
		T back();
		T& operator [](int);
		void erase();

	protected:
		Node<T> *head;
};

/** 
 * setEvaluation
 * 
 * This function sets evaluation to the provided value
 * 
 * Parameters: 
 *      num: number to set evaluation
 * 
 * Output: 
 *      return:  none
 *      reference parameters: none 
 *      stream:  none 
 */

template <class T>
MyList<T>::MyList()
{
    this->head = NULL;
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
MyList<T>::MyList(const MyList& n)
{
    this->head = n.head;
}

template <class T>
MyList<T>& MyList<T>::operator=(const MyList& n)
{
    ~this;
    this->head = n.head;

    return *this;
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
    Node<T> *temp = this->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new Node<T>(n);

    return *this;
}

template <class T>
MyList<T>& MyList<T>::popFront(T &n)
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
MyList<T>& MyList<T>::popBack(T &n)
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
T MyList<T>::front()
{
    if (this->head == NULL)
    {
        throw BADINDEX();
    }
    return this->head->data;
}

template <class T>
T MyList<T>::back()
{
    if (this->head == NULL)
    {
        throw BADINDEX();
    }
    Node<T> *temp = this->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    return temp->data;
}

template <class T>
T& MyList<T>::operator[](int n)
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
