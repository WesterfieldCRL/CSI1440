/**
 * file: proj5-BUAthelete.hpp
 * author: Wesley Anastasi
 * course: CSI 1440
 * assignment: Project 5
 * due date: 10/17/2022
 *
 * date modified: 10/09/2022
 * - created file
 * 
 * Function header for BUAthlete
 */

#include "proj5-NCAAAthlete.hpp"

#ifndef BUATHLETE_H
#define BUATHLETE_H

enum Position {OL, QB, RB, WR, TE, DL, DE, LB, CB, S, K};

class BUAthlete : public NCAAAthlete
{
    private:
        int evaluation;
        Position bestFit;
    public:
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
        void setEvaluation(int num);

        /** 
         * setPosition
         * 
         * This function sets position to the provided value
         * 
         * Parameters: 
         *      pos: value to set Position
         * 
         * Output: 
         *      return:  none
         *      reference parameters: none 
         *      stream:  none 
         */
        void setPosition(Position pos);

        /** 
         * getEvaluation
         * 
         * This function returns evaluation
         * 
         * Parameters: 
         *      none
         * 
         * Output: 
         *      return:  int
         *      reference parameters: none 
         *      stream:  none 
         */
        int getEvaluation();

        /** 
         * getPosition
         * 
         * This function returns Position
         * 
         * Parameters: 
         *      none
         * 
         * Output: 
         *      return:  Position
         *      reference parameters: none 
         *      stream:  none 
         */
        Position getPosition();

        /** 
         * toString
         * 
         * This function returns a string of the Athlete
         * 
         * Parameters: 
         *      none
         * 
         * Output: 
         *      return:  string
         *      reference parameters: none 
         *      stream:  none 
         */
        string toString();
};

#endif