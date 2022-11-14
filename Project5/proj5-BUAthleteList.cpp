/**
 * file: proj5-BUAthleteList.cpivotPoint
 * author: Wesley Anastasi
 * course: CSI 1440
 * assignment: Project 5
 * due date: 10/17/2022
 *
 * date modified: 10/12/2022
 * - created file
 * 
 * date modified: 10/15/2022
 * - implemented sorts
 * 
 * Implementation of BUAthleteList's functions
 */

#include "proj5-BUAthleteList.hpp"
#include <sstream>
#include <iostream>

BUAthleteList::BUAthleteList()
{
    this->size = 0;
    this->capacity = 2;
    this->list = new BUAthlete[this->capacity];
}

void BUAthleteList::resizeArray()
{
    BUAthlete *temp = this->list;
    this->capacity += 2;
    this->list = new BUAthlete[this->capacity];

    for (int i = 0; i < this->size; i++)
    {
        this->list[i] = temp[i];
    }

    delete [] temp;
}

void BUAthleteList::addNCAAAthlete(int id, string name, string LOI, string school)
{
    BUAthlete temp;
    temp.setID(id);
    temp.setLOI(LOI);
    temp.setName(name);
    temp.setSchool(school);
    if (this->size >= this->capacity)
    {
        resizeArray();
    }
    this->list[this->size] = temp;
    this->size++;
    
}

void BUAthleteList::setBUInfo(int index, Position pos, int eval)
{
    if (index < this->size)
    {
        this->list[index].setPosition(pos);
        this->list[index].setEvaluation(eval);   
    }
}

int BUAthleteList::findById(int id)
{
    int lo = 0, hi = this->size - 1;
    int mid;
    while (hi - lo > 1) {
        int mid = (hi + lo) / 2;
        if (this->list[mid].getID() < id) {
            lo = mid + 1;
        }
        else {
            hi = mid;
        }
    }
    if (this->list[lo].getID() == id) {
        return lo;
    }
    else if (this->list[hi].getID() == id) {
        return hi;
    }
    else {
        return -1;
    }
}

void BUAthleteList::sortByID()
{
    int high = this->size-1;
    int low = 0;
    // Create an auxiliary stack
    int stack[high - low + 1];
 
    // initialize top of stack
    int top = -1;
 
    // push initial values of l and h to stack
    stack[++top] = low;
    stack[++top] = high;
 
    // Keep popping from stack while is not empty
    while (top >= 0) 
    {
        // Pop h and l
        high = stack[top--];
        low = stack[top--];
 
        // Set pivot element at its correct position
        // in sorted array
        int x = this->list[high].getID();
        int i = (low - 1);
    
        for (int j = low; j <= high - 1; j++) 
        {
            if (this->list[j].getID() <= x) 
            {
                i++;
                swap(this->list[i], this->list[j]);
            }
        }
        swap(this->list[i + 1], this->list[high]);
        int p = (i + 1);
 
        // If there are elements on left side of pivot,
        // then push left side to stack
        if (p - 1 > low) 
        {
            stack[++top] = low;
            stack[++top] = p - 1;
        }
 
        // If there are elements on right side of pivot,
        // then push right side to stack
        if (p + 1 < high) 
        {
            stack[++top] = p + 1;
            stack[++top] = high;
        }
    }
}

void BUAthleteList::sortByPosition()
{
    for (int i = 0; i < this->size-1; i++)
    {
        for (int j = 0; j < this->size-i-1;j++)
        {
            if (this->list[j].getPosition() > this->list[j+1].getPosition())
            {
                swap(this->list[j],this->list[j+1]);
            }
        }
    }
}

void BUAthleteList::sortByEvaluation()
{
    int high = this->size-1;
    int low = 0;
    int stack[high - low + 1];
    int top = -1;

    stack[++top] = low;
    stack[++top] = high;

    while (top >= 0) 
    {

        high = stack[top--];
        low = stack[top--];

        int x = this->list[high].getEvaluation();
        int i = (low - 1);
    
        for (int j = low; j <= high - 1; j++) 
        {
            if (this->list[j].getEvaluation() <= x) 
            {
                i++;
                swap(this->list[i], this->list[j]);
            }
        }
        swap(this->list[i + 1], this->list[high]);
        int p = (i + 1);
 
        if (p - 1 > low) 
        {
            stack[++top] = low;
            stack[++top] = p - 1;
        }

        if (p + 1 < high) 
        {
            stack[++top] = p + 1;
            stack[++top] = high;
        }
    }
}

BUAthlete& BUAthleteList::operator[](int ndx)
{
    return this->list[ndx];
}

string BUAthleteList::toString()
{
    ostringstream out;
    Position currPos = this->list[this->size].getPosition();
    int numOfPos = 0;
    int num = 0;
    for (int i = this->size-1; i >= 0; i--)
    {
        if (this->list[i].getPosition() != currPos || numOfPos < 1)
        {
            out << "[ " << num << " ]" << endl;
            out << this->list[i].toString();
            num++;
            if (this->list[i].getPosition() == currPos)
            {
                numOfPos++;
            }
            else 
            {
                numOfPos = 0;
                currPos = this->list[i].getPosition();     
            }
            
        }
    }

    return out.str();
}
