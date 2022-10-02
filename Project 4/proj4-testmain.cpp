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
    //testing with 0 
    temp[0] = '0';
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

    //testing stuDblToCstr
    //testing with multiple digits
    double tempNum = 139;
    stuDblToCstr(temp,tempNum);
    for (int i = 0; temp[i] != '\0'; i++)
    {
        cout << temp[i];
    }
    cout << endl;
    //testing with negative
    tempNum = -139;
    stuDblToCstr(temp,tempNum);
    for (int i = 0; temp[i] != '\0'; i++)
    {
        cout << temp[i];
    }
    cout << endl;
    //testing with decimals
    tempNum = 1.293;
    stuDblToCstr(temp,tempNum);
    for (int i = 0; temp[i] != '\0'; i++)
    {
        cout << temp[i];
    }
    cout << endl;
    //testing with negative and decimals
    tempNum = -1.293;
    stuDblToCstr(temp,tempNum);
    for (int i = 0; temp[i] != '\0'; i++)
    {
        cout << temp[i];
    }
    cout << endl;
    //testing with zero
    tempNum = 0;
    stuDblToCstr(temp,tempNum);
    printCString(cout,temp);
    cout << endl;

    //testing stuCstrCpy
    temp[0] = 'H';
    temp[1] = 'e';
    temp[2] = 'l';
    temp[3] = 'l';
    temp[4] = 'o';
    temp[5] = '\0';
    char temp2[50];
    stuCstrCpy(temp2, temp);
    cout << temp2 << endl;

    //testing stuCstrLen
    cout << stuCstrLen(temp2) << endl;

    //testing printCstring
    printCString(cout,temp2);
    cout << endl;

    //testing toAmazonJSON
    item.setDescription(temp);
    item.toAmazonJSON(cout);

    //testing displayItemInfo
    item.displayItemInfo(cout);

    return 0;   
}