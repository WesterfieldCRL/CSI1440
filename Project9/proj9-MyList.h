#include "proj9-ContainerIfc.h"
#include "proj9-Node.h"

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
    Node *temp = this->head;
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

    Node *temp = this->head;
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

    Node *temp = this->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    n = temp->data;
    //might need to set previous node's next to null
    delete temp;

    return *this;
}

template <class T>
int MyList<T>::getSize()
{
    
}