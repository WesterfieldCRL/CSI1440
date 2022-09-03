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
    int largest;
    int smallest;
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



    }

    return 0;   
}