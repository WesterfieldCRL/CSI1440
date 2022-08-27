/**
-  file: lab1-pointers1.cpp
-  author:  Wesley Anastasi
-  course: CSI 1440
-  assignment: Lab 1
-  due date: 8/23/2022
-   
-  Date Modified: 8/23/2022
-    - File Created
-  
-  Testing the reference operator
*/
#include <iostream>

using namespace std;

int main() {
  int x = 5;
    //output the address of x
    cout << &x << " is the address of x" << endl;
    //output the value of x
    cout << x << " is the value stored in x" << endl;

    return 0;
}