/**
-  file: lab2-pointers2-2.cpp
-  author:  Wesley Anastasi
-  course: CSI 1440
-  assignment: Lab 2
-  due date: 8/30/2022
-   
-  Date Modified: 8/30/2022
-    - File Created
-  
-  Pointers and arrays + Dynamic Memory
*/

#include <iostream>

using namespace std;

char* giveMemory( ) {
  char myArray[] = "Hello World!";
  return myArray;
}

int main() {
  char *myPtr;

  myPtr = giveMemory();
  cout << myPtr << endl;

  myPtr[1] = 'o';
  myPtr[2] = 'w';
  myPtr[3] = 'd';
  myPtr[4] = 'y';

  cout << endl << myPtr << endl;

  return 0;
}