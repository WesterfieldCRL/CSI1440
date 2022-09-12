/**
 * file: proj2-testmain.cpp
 * author: Wesley Anastasi
 * course: CSI 1440
 * assignment: Project 2
 * due date: 9/5/2022
 *
 * date modified: 9/2/2022
 * - created file
 * date modified: 9/3/2022
 * - finished testing
 * 
 * 1D Dynamic Arrays test driver
 */

#include <iostream>
#include "proj2-arrayFunctions.h"

using namespace std;

int main() 
{
    srand(time(0));
    int size = 10;
    int *a = new int[size];

    a[0] = rand()%10;
    a[1] = rand()%10;
    a[2] = rand()%10;
    a[3] = rand()%10;
    a[4] = rand()%10;
    a[5] = rand()%10;
    a[6] = rand()%10;
    a[7] = rand()%10;
    a[8] = rand()%10;
    a[9] = rand()%10;

    //testing bubble sort

    cout << "sorted via bubble sort:" << endl;

    bubbleSort(a, size);

    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "largest value: " << largestValue(a, size) << endl;
    cout << "smallest value: " << smallestValue(a, size) << endl;
    cout << "average value: " << averageValue(a, size) << endl;
    cout << "median value: " << medianValue(a, size) << endl;

    delete a;

    return 0;   
}