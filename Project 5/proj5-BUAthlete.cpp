/**
 * file: proj5-BUAthlete.cpp
 * author: Wesley Anastasi
 * course: CSI 1440
 * assignment: Project 5
 * due date: 10/17/2022
 *
 * date modified: 10/09/2022
 * - created file
 * 
 * Function implementation for BUAthlete
 */

#include "proj5-BUAthlete.hpp"

void BUAthlete::setEvaluation(int num)
{
   this->evaluation = num;
}

void BUAthlete::setPosition(Position pos)
{
   this->bestFit = pos;
}

int BUAthlete::getEvaluation()
{
   return this->evaluation;
}

Position BUAthlete::getPosition()
{
   return this->bestFit;
}

string BUAthlete::toString()
{
   return "not implemented yet";
}
