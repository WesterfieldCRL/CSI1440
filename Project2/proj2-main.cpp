/**
 * file: proj2-main.cpp
 * author: Wesley Anastasi
 * course: CSI 1440
 * assignment: Project 2
 * due date: 9/5/2022
 *
 * date modified: 9/2/2022
 * - created file
 * date modified: 9/3/2022
 * - made some progress
 * 
 * 1D Dynamic Arrays main
 */

#include <iostream>
#include <fstream>
#include "proj2-arrayFunctions.h"

using namespace std;

int main() 
{
    fstream inputFile;
    int input;
    int size;
    bool firstPass = true;
    int largest;
    int smallest;
    int localLargest, localSmallest;
    int *a;
    inputFile.open("arrays.txt");

    while (inputFile >> size)
    {
        a = new int[size];
        for (int i = 0; i < size; i++)
        {
            inputFile >> input;
            a[i] = input;
        }
        bubbleSort(a,size);
        
        localLargest = largestValue(a,size);
        localSmallest = smallestValue(a,size);

        if (firstPass)
        {
            largest = localLargest;
            smallest = localSmallest;
            firstPass = false;
        }
        else
        {
            if (largest < localLargest)
            {
                largest = localLargest;
            }
            if (smallest > localSmallest)
            {
                smallest = localSmallest;
            }
        }

        cout << "Smallest value = " << localSmallest;
        cout << " Largest value = " << localLargest;
        cout << " Median = " << medianValue(a,size);
        cout << " Average = " << averageValue(a,size) << endl; 

        delete a;

    }

    cout << endl;
    cout << "Overall largest = " << largest;
    cout << " Overall smallest = " << smallest << endl;

    return 0;   
}