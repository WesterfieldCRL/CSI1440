/**
-  file: lab1-pointers1-3.cpp
-  author:  Wesley Anastasi
-  course: CSI 1440
-  assignment: Lab 1
-  due date: 8/23/2022
-   
-  Date Modified: 8/23/2022
-    - File Created
-  
-  Pointer Arithmetic
*/

#include <iostream>

using namespace std;

int main() 
{
    //creates variables x, ch, and dbl, and then creates pointers for each variable
    int x, *intPtr = &x;
    char ch, *chPtr = &ch;
    double dbl, *dblPtr = &dbl;

    //prints out the value of the pointers
    cout << intPtr << " is the initial value of intPtr" << endl;
    cout << (int*)chPtr << " is the initial value of chPtr"<< endl;
    cout << dblPtr << " is the initial value of dblPtr" << endl;

    //adds one to the value of each pointer
    intPtr++;
    chPtr++;
    dblPtr++;

    //prints the new value of the pointers
    cout << intPtr << " is the new value of intPtr" << endl;
    cout << (int*)chPtr << " is the new value of chPtr"<< endl;
    cout << dblPtr << " is the new value of dblPtr" << endl;

    return 0;
}