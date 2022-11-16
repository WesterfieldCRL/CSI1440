#include "ListNode.h"

ListNode *insert(ListNode *ptr, string val)
{
      ListNode *temp = new ListNode();
      temp->data = val;
      temp->next = ptr;
      return temp;
}

void insert(ListNode **ptr, string val)
{
    ListNode *temp = new ListNode();
    temp->data = val;
    temp->next = *ptr;
    *ptr = temp;
}

ListNode *remove(ListNode *ptr)
{
    ListNode *temp = ptr;
    ptr = ptr->next;
    delete temp;
    return ptr;
}

void remove(ListNode** ptr)
{
    ListNode *temp = *ptr;
    ListNode *temp2 = temp;
    temp = temp->next;
    delete temp2;
    *ptr = temp;
}

void printForward(ostream &out, ListNode *ptr)
{
    if (ptr != NULL)
    {
        out << ptr->data << endl;
        printForward(out, ptr->next);
    }
}

void printReverse(ostream &out, ListNode *ptr)
{
    if (ptr != NULL)
    {
        printReverse(out, ptr->next);
        out << ptr->data << endl;
    }
}