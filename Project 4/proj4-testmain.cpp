/**
 * file: proj4-testmain.cpp
 * author: Wesley Anastasi
 * course: CSI 1440
 * assignment: Project 4
 * due date: 10/03/2022
 *
 * date modified: 9/26/2022
 * - created file
 * 
 * Testmain
 */

#include <iostream>
#include <fstream>
#include "proj4-ItemInfo.hpp"

using namespace std;

int main() 
{
    fstream output ("testOutput.txt");
    ItemInfo item;
    char *temp = new char[10];

    //testing stuCstrToDbl
    //testing with 1digit 
    temp[0] = '1';
    temp[1] = '\0';
    cout << stuCstrToDbl(temp) << endl;
    //testing with multiple digits
    temp[0] = '5';
    temp[1] = '3';
    temp[2] = '8';
    temp[3] = '2';
    temp[4] = '\0';
    cout << stuCstrToDbl(temp) << endl;
    //testing with negative value
    temp[0] = '-';
    temp[1] = '3';
    temp[2] = '8';
    temp[3] = '2';
    temp[4] = '\0';
    cout << stuCstrToDbl(temp) << endl;
    //testing with 1 decimal
    temp[0] = '5';
    temp[1] = '3';
    temp[2] = '.';
    temp[3] = '2';
    temp[4] = '\0';
    cout << stuCstrToDbl(temp) << endl;
    //testing with multiple decimals
    temp[0] = '5';
    temp[1] = '3';
    temp[2] = '.';
    temp[3] = '2';
    temp[4] = '3';
    temp[5] = '0';
    temp[6] = '\0';
    cout << stuCstrToDbl(temp) << endl;
    //testing with negative decimals
    temp[0] = '-';
    temp[1] = '3';
    temp[2] = '.';
    temp[3] = '2';
    temp[4] = '3';
    temp[5] = '0';
    temp[6] = '\0';
    cout << stuCstrToDbl(temp) << endl;
    //testing with only decimals
    temp[0] = '.';
    temp[1] = '3';
    temp[2] = '0';
    temp[3] = '2';
    temp[4] = '3';
    temp[5] = '0';
    temp[6] = '\0';
    cout << stuCstrToDbl(temp) << endl;

    return 0;   
}