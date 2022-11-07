/**
 * file: proj7-TestMain.cpp
 * author: Wesley Anastasi
 * course: CSI 1440
 * assignment: project 7
 * due date: 11/7/2022
 *
 * date modified: 11/6/2022
 * - created file
 * 
 * test main
 */

#include "proj7-MyVector.h"

#include <iostream>

using namespace std;

int main ()
{
    srand(time(0));
    MyVector<int> vector;

    cout << "testing pushBack" << endl;
    for (int i = 0; i < 13; i++)
    {
        int temp = rand()%10;
        vector.pushBack(temp);
        cout << temp << " ";
    }

    cout << endl;

    for (int i = 0; i < vector.getSize(); i++)
    {
        cout << vector[i] << " ";
    }
    
    cout << endl;

    cout << "testing pushFront" << endl;

    for (int i = 0; i < 13; i++)
    {
        int temp = rand()%10;
        vector.pushFront(temp);
        cout << temp << " ";
    }

    cout << endl;

    for (int i = 0; i < vector.getSize(); i++)
    {
        cout << vector[i] << " ";
    }
    
    cout << endl;

    cout << "testing popFront" << endl;

    for (int i = 0; i < 13; i++)
    {
        int temp;
        vector.popFront(temp);
        cout << temp << " ";
    }
    cout << endl;

    cout << "testing pushBack" << endl;

    for (int i = 0; i < 13; i++)
    {
        int temp = rand()%10;
        vector.pushBack(temp);
        cout << temp << " ";
    }

    cout << endl;

    for (int i = 0; i < vector.getSize(); i++)
    {
        cout << vector[i] << " ";
    }

    cout << endl << "testing popBack" << endl;

    for (int i = 0; i < 13; i++)
    {
        int temp;
        vector.popBack(temp);
        cout << temp << " ";
    }
    cout << endl;

    cout << "testing front/back" << endl;

    for (int i = 0; i < vector.getSize(); i++)
    {
        cout << vector[i] << " ";
    }

    cout << endl;

    cout << "front is: " << vector.front() << endl;
    cout << "back is: " << vector.back() << endl;

    cout << "testing erase" << endl;

    vector.erase();

    cout << "isEmpty = " << vector.isEmpty() << endl;

    cout << "size = " << vector.getSize() << endl;

    cout << "testing copy constructer" << endl;

    for (int i = 0; i < 13; i++)
    {
        int temp = rand()%10;
        vector.pushBack(temp);
        cout << temp << " ";
    }

    cout << endl;

    MyVector newVector(vector);

    for (int i = 0; i < vector.getSize(); i++)
    {
        cout << vector[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < vector.getSize(); i++)
    {
        cout << newVector[i] << " ";
    }

    cout << endl;

    cout << "testing equal operator" << endl;

    for (int i = 0; i < 13; i++)
    {
        int temp = rand()%10;
        vector.pushBack(temp);
        cout << temp << " ";
    }

    cout << endl;

    for (int i = 0; i < vector.getSize(); i++)
    {
        cout << vector[i] << " ";
    }

    cout << endl;

    newVector = vector;

    newVector = newVector;

    for (int i = 0; i < vector.getSize(); i++)
    {
        cout << newVector[i] << " ";
    }

    cout << endl;

    return 0;
}