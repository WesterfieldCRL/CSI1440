/**
 * file: functionTemplate.cpp
 * author: Wesley Anastasi
 * course: CSI 1440
 * assignment: none
 * due date: 8/29/2022
 *
 * date modified: 8/29/2022
 * - created file
 * 
 * template
 */

#include "proj5-BUAthleteList.hpp"

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

int part(int a[], int lo, int hi)
{
    int pv = a[lo];
    int pp = lo;
    for (int p = lo+1; p < hi; p++)
    {
        if (a[p] < pv)
        {
            swap(a[pp+1],a[p]);
            swap(a[pp+1],a[pp]);
            pp++;
        }
    }
    return pp;
}