/**
 * file: proj5-BUAthleteList.hpp
 * author: Wesley Anastasi
 * course: CSI 1440
 * assignment: Project 5
 * due date: 10/17/2022
 *
 * date modified: 10/11/2022
 * - created file
 * 
 * Function Header for BUAthleteList
 */

#include "proj5-BUAthlete.hpp"

#ifndef BUATHLETELIST_H
#define BUATHLETELIST_H


class BUAthleteList
{
    private:
        BUAthlete *list;
        int capacity;
        int size;

        /** 
         * resizeArray
         * 
         * This function resizes list by adding 2 to capacity
         * 
         * Parameters: 
         *      none
         * 
         * Output: 
         *      return:  none
         *      reference parameters: none 
         *      stream:  none 
         */
        void resizeArray();
    public:

        /** 
         * addNCAAAthlete
         * 
         * This function adds an athlete to list
         * 
         * Parameters: 
         *      int id, string name, string LOI, string school
         * 
         * Output: 
         *      return:  none
         *      reference parameters: none 
         *      stream:  none 
         */
        void addNCAAAthlete(int id, string name, string LOI, string school);

        /** 
         * setBUInfo
         * 
         * This function adds an athlete to list
         * 
         * Parameters: 
         *      int index, Position pos, int eval
         * 
         * Output: 
         *      return:  none
         *      reference parameters: none 
         *      stream:  none 
         */
        void setBUInfo(int index, Position pos, int eval);

        /** 
         * findById
         * 
         * This function searches for an athlete with binary search
         * 
         * Parameters: 
         *      int id
         * 
         * Output: 
         *      return:  int
         *      reference parameters: none 
         *      stream:  none 
         */
        int findById(int id);

        /** 
         * sortById
         * 
         * This function sorts list by id using quicksort
         * 
         * Parameters: 
         *      none
         * 
         * Output: 
         *      return:  none
         *      reference parameters: none 
         *      stream:  none 
         */
        void sortByID();

        /** 
         * sortByPosition
         * 
         * This function uses quicksort to sort list by position
         * 
         * Parameters: 
         *      none
         * 
         * Output: 
         *      return:  none
         *      reference parameters: none 
         *      stream:  none 
         */
        void sortByPosition();

        /** 
         * sortByEvaluation
         * 
         * This function uses quicksort to sort list by evaluation
         * 
         * Parameters: 
         *      none
         * 
         * Output: 
         *      return:  none
         *      reference parameters: none 
         *      stream:  none 
         */
        void sortByEvaluation();

        /** 
         * operator[]
         * 
         * This function returns the item from list given by ndx
         * 
         * Parameters: 
         *      int ndx
         * 
         * Output: 
         *      return:  BUAthlete
         *      reference parameters: none 
         *      stream:  none 
         */
        BUAthlete& operator[](int ndx);

        /** 
         * toString
         * 
         * This function returns a string representation of BUAthleteList
         * 
         * Parameters: 
         *      none
         * 
         * Output: 
         *      return:  none
         *      reference parameters: none 
         *      stream:  none 
         */
        string toString();
};

#endif