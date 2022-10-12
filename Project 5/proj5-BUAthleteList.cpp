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

void BUAthleteList::resizeArray()
{
    BUAthlete *temp = this->list;
    this->capacity += 2;
    this->list = new BUAthlete[this->capacity];
    for (int i = 0; i < this->size; i++)
    {
        this->list[i] = temp[i];
    }
    delete temp;
}

void BUAthleteList::addNCAAAthlete(int id, string name, string LOI, string school)
{
    BUAthlete temp;
    temp.setID(id);
    temp.setLOI(LOI);
    temp.setName(name);
    temp.setSchool(school);
    this->list[this->size] = temp;
    this->size++;
    if (this->size > this->capacity)
    {
        resizeArray();
    }
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
    int low = 0;
    int high = this->size-1;
    int mid;

    while (low != high)
    {
        mid = (low + high)/2;
        if (id == this->list[mid].getID())
        {
            return mid;
        }
        else if (id > this->list[mid].getID())
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }

}

void BUAthleteList::sortByID()
{

}

void BUAthleteList::sortByPosition()
{

}

void BUAthleteList::sortByEvaluation()
{

}

BUAthlete& BUAthleteList::operator[](int ndx)
{
    if (ndx < this->size)
    {
        return this->list[ndx];
    }
}

string BUAthleteList::toString()
{

}
