/**
 * file: proj2-arrayFunctions.cpp
 * author: Wesley Anastasi
 * course: CSI 1440
 * assignment: Project 2
 * due date: 9/5/2022
 *
 * date modified: 9/2/2022
 * - created file
 * date modified: 9/3/2022
 * - finished functions
 * 
 * 1D Dynamic Arrays functions
 */

#include "proj2-arrayFunctions.h"

/** 
 * bubbleSort
 * 
 * Sorts the array in ascending order using bubble sort
 * 
 * Parameters: 
 *      array: array of integers passed as a reference
 *      size: size of the array
 * 
 * Output: 
 *      return: none
 *      reference parameters: array 
 *      stream: none 
 */

void bubbleSort(int *array, int size)
{
    bool unsorted = true;
    while (unsorted)
    {
        unsorted = false;
        for (int i = 0; i < size-1; i++)
        {
            if (array[i]>array[i+1])
            {
                int temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
                unsorted = true;
            }
        }
    }
}

/** 
 * largestValue
 * 
 * finds the largest value in the array
 * 
 * Parameters: 
 *      array: array of integers passed as a reference
 *      size: size of the array
 * 
 * Output: 
 *      return: largest value (int)
 *      reference parameters: array 
 *      stream: none 
 */

int largestValue(int *array, int size)
{
    int largest = array[0];
    for (int i = 1; i < size; i++)
    {
        if (largest < array[i])
        {
            largest = array[i];
        }
    }

    return largest;
}

/** 
 * smallestValue
 * 
 * finds the smallest value in the array
 * 
 * Parameters: 
 *      array: array of integers passed as a reference
 *      size: size of the array
 * 
 * Output: 
 *      return: smallest value (int)
 *      reference parameters: array 
 *      stream: none 
 */

int smallestValue(int *array, int size)
{
    int smallest = array[0];
    for (int i = 1; i < size; i++)
    {
        if (smallest > array[i])
        {
            smallest = array[i];
        }
    }

    return smallest;
}

/** 
 * averageValue
 * 
 * finds the average of the numbers in the array
 * 
 * Parameters: 
 *      array: array of integers passed as a reference
 *      size: size of the array
 * 
 * Output: 
 *      return: the average value (double)
 *      reference parameters: array 
 *      stream: none 
 */

double averageValue(int *array, int size)
{
    double average = 0;
    for (int i = 0; i < size; i++)
    {
        average += array[i];
    }
    average /= static_cast<double>(size);
    return average;
}

/** 
 * medianValue
 * 
 * finds the median of the numbers in the array
 * 
 * Parameters: 
 *      array: array of integers passed as a reference
 *      size: size of the array
 * 
 * Output: 
 *      return: the median (int)
 *      reference parameters: array 
 *      stream: none 
 */

int medianValue(int *array, int size)
{
    int median;
    median = array[size/2];

    return median;
}
