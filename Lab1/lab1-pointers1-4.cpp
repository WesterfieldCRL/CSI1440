/**
-  file: lab1-pointers1-4.cpp
-  author:  Wesley Anastasi
-  course: CSI 1440
-  assignment: Lab 1
-  due date: 8/23/2022
-   
-  Date Modified: 8/23/2022
-    - File Created
-  
-  Pointer Introduction to inderection
*/

#include <iostream>

using namespace std;

int main() 
{
    //creates all variables
    int x, *intPtr;
    char ch, *charPtr;

    //assigns value to x and ch, and points the pointers to the appropriate address
    x = 10;
    intPtr = &x;

    ch = 'a';
    charPtr = &ch;  

    //prints the value of x and ch normally, and then using the inderection operator.
    cout << "The value of x is " << x << endl;
    cout << "The value of x using intPtr is " << *intPtr << endl;  

    cout << "The value of ch is " << ch << endl;
    cout << "The value of ch using charPtr is " << *charPtr << endl;

    //changes the value of x and ch using the inderection operator
    *intPtr = 0;
    *charPtr = 'Z';

    //prints the new value of x and ch.
    cout << "The value of x is " << x << endl;
    cout << "The value of ch is " << ch << endl; 

    return 0;
}