/**
-  file: lab2-pointers2-1.cpp
-  author:  Wesley Anastasi
-  course: CSI 1440
-  assignment: Lab 2
-  due date: 8/30/2022
-   
-  Date Modified: 8/30/2022
-    - File Created
-  
-  Pointers and arrays
*/

#include <iostream>

using namespace std;

int main() 
{
  char myArray[] = "Hello World!";
  char *myPtr = "Hello World!";

  cout << "This is from the array: " << myArray << endl;
  cout << "This is from the pointer: " << myPtr << endl;   
  cout << endl;

  cout << "Trying to move the array ..." << endl;
  myArray += 6;
  cout << "This is from the array: " << myArray << endl;

  return 0;
}