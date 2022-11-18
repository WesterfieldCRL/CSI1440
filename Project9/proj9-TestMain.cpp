/**
 * file: proj9-TestMain.cpp
 * author: Wesley Anastasi
 * course: CSI 1440
 * assignment: Project 9
 * due date: 11/28/2022
 *
 * date modified: 11/18/2022
 * - created file
 * 
 * Test Main
 */

#include <iostream>
#include "proj9-MyList.h"

using namespace std;

int main()
{
    MyList<int> list;
    int num;

    cout << "testing pushFront" << endl;

    for (int i = 0; i < 16; i++)
    {
        list.pushFront(i);
    }

    cout << "testing getSize and operator[]" << endl;

    for (int i = 0; i < list.getSize(); i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;

    cout << "testing pushBack" << endl;

    for (int i = 0; i < 5; i++)
    {
        list.pushBack(i);
    }

    for (int i = 0; i < list.getSize(); i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;

    cout << "testing popBack" << endl;

    for (int i = 0; i < 5; i++)
    {
        list.popBack(num);
        cout << num << " ";
    }
    cout << endl;

    for (int i = 0; i < list.getSize(); i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;

    cout << "testing popFront" << endl;

    for (int i = 0; i < 5; i++)
    {
        list.popFront(num);
        cout << num << " ";
    }
    cout << endl;

    for (int i = 0; i < list.getSize(); i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;

    cout << "testing popFront removing everything" << endl;

    for (int i = 0; i < 11; i++)
    {
        list.popFront(num);
        cout << num << " ";
    }
    cout << endl;

    for (int i = 0; i < list.getSize(); i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;

    cout << "testing popBack removing everything" << endl;

    for (int i = 0; i < 5; i++)
    {
        list.pushFront(i);
    }

    for (int i = 0; i < 5; i++)
    {
        list.popBack(num);
        cout << num << " ";
    }
    cout << endl;
 
    for (int i = 0; i < list.getSize(); i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;

    return 0;
}