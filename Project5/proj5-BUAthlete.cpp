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
#include <sstream>

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
   ostringstream out;
   out << "ID: " << this->athleteID << endl;
   out << "Name: " << this->athleteName << endl;

   if (this->athleteLOI)
   {
      out << "School: " << this->schoolChoice << endl;
   } 
   else 
   {
      out << "Available" << endl;
   }

   out << "Evaluation: " << this->evaluation << endl;

   out << "Position: ";
   switch (this->bestFit)
   {
   case 0:
      out << "OL";
      break;
   case 1:
      out << "QB";
      break;
   case 2:
      out << "RB";
      break;
   case 3:
      out << "WR";
      break;
   case 4:
      out << "TE";
      break;
   case 5:
      out << "DL";
      break;
   case 6:
      out << "DE";
      break;
   case 7:
      out << "LB";
      break;
   case 8:
      out << "CB";
      break;
   case 9:
      out << "S";
      break;
   case 10:
      out << "K";
      break;
   default:
      out << "Error";
      break;
   }

   out << endl;

   return out.str();

}
