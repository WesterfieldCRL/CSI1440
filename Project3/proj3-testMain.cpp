/**
 * file: proj3-testMain.cpp
 * author: Wesley Anastasi
 * course: CSI 1440
 * assignment: Project 3
 * due date: 9/19/2022
 *
 * date modified: 9/14/2022
 * - created file
 * 
 * Project 3 test driver
 */

#include <iostream>
#include "proj3-MyString.h"

using namespace std;

int main() 
{
    char *test = new char[20];
    test[0] = 'h';
    test[1] = 'e';
    test[2] = 'l';
    test[3] = 'l';
    test[4] = 'o';
    test[5] = ' ';
    test[6] = 'w';
    test[7] = 'o';
    test[8] = 'r';
    test[9] = 'l';
    test[10] = 'd';
    test[11] = '\0';

    char *test2 = new char[20];
    test2[0] = 'g';
    test2[1] = 'o';
    test2[2] = 'o';
    test2[3] = 'd';
    test2[4] = 'b';
    test2[5] = 'y';
    test2[6] = 'e';
    test2[7] = ' ';
    test2[8] = 'w';
    test2[9] = 'o';
    test2[10] = 'r';
    test2[11] = 'l';
    test2[12] = 'd';
    test2[13] = '\0';

    cout << "test = ";
    for (int i = 0; i < 11; i++)
    {
        cout << test[i];
    }
    cout << endl;

    cout << "test2 = ";
    for (int i = 0; i < 13; i++)
    {
        cout << test2[i];
    }
    cout << endl;

    MyString thing1(test);
    MyString thing2(test2);

    cout << "thing = ";
    cout << thing1;
    cout << "||size = " << thing1.length() << endl;

    cout << "thing2 = ";
    cout << thing2;
    cout << "||size = " << thing2.length() << endl;

    //testing operator +
    MyString thing3 = thing1+thing2;

    cout << "thing3 = ";
    cout << thing3;
    cout << "||size = " << thing3.length() << endl;

    //since the += function uses the = and + functions, this tests all of those
    thing3+=thing2;
    cout << "thing3 = ";
    cout << thing3;
    cout << "||size = " << thing3.length() << endl;

    thing1.getline(cin);

    cout << "thing1 = ";
    cout << thing1;
    cout << "||size = " << thing1.length() << endl;

    return 0;   
}