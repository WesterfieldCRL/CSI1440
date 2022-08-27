/**
-  file: lab1-pointers1-1.cpp
-  author:  Wesley Anastasi
-  course: CSI 1440
-  assignment: Lab 1
-  due date: 8/23/2022
-   
-  Date Modified: 8/23/2022
-    - File Created
-  
-  The Reference Operator
*/
#include <iostream>

using namespace std;

int main() {
    int x;
    int *intPtr;
    char ch;
    char *chPtr;

    //assign value to x and ch, and point the pointers to ch and x
    x = 10;
    ch = 'a';
    chPtr = &ch;
    intPtr = &x;

    //print out the value, address, and size of each variable
    cout << "x's value is " << x << endl;
    cout << "intPtr's value is " << intPtr << endl;

    cout << "x's address is " << &x << endl;

    cout << "The size of x is " << sizeof(x) << endl;
    cout << "The size of intPtr is " << sizeof(intPtr) << endl;

    cout << endl;

    cout << "ch's value is " << ch << endl;
    cout << "chPtr's value is " << (int*)(chPtr) << endl;

    cout << "ch's address is " << &ch << endl;

    cout << "The size of ch is " << sizeof(ch) << endl;
    cout << "The size of chPtr is " << sizeof(chPtr) << endl;



    return 0;
}