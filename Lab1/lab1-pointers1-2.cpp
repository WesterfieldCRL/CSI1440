/**
-  file: lab1-pointers1-2.cpp
-  author:  Wesley Anastasi
-  course: CSI 1440
-  assignment: Lab 1
-  due date: 8/23/2022
-   
-  Date Modified: 8/23/2022
-    - File Created
-  
-  Pointer as a variable
*/

#include <iostream>

using namespace std;

int main() {
    //create variables
    double dbl = 2.5;
    double dbl2 = 3.14;
    double *dblPtr;

    //point dblPtr to dbl's address
    dblPtr = &dbl;

    //print value, address, and size for dbl and dblPtr
    cout << "dbl value = " << dbl << endl;
    cout << "dblPtr value = " << dblPtr << endl;
    cout << "dbl address = " << &dbl << endl;
    cout << "dblPtr address = " << &dblPtr << endl;
    cout << "size of dbl = " << sizeof(dbl) << endl;
    cout << "size of dblPtr = " << sizeof(dblPtr) << endl; 

    //point dblPtr to dbl2
    dblPtr = &dbl2;

    //print value, address, and size for dbl2 and dblPtr
    cout << "dbl2 value = " << dbl2 << endl;
    cout << "dblPtr value = " << dblPtr << endl;
    cout << "dbl2 address = " << &dbl2 << endl;
    cout << "dblPtr address = " << &dblPtr << endl;
    cout << "size of dbl2 = " << sizeof(dbl2) << endl;
    cout << "size of dblPtr = " << sizeof(dblPtr) << endl; 

    return 0;
}