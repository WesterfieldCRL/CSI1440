/**
-  file: lab2-pointers2-4.cpp
-  author:  Wesley Anastasi
-  course: CSI 1440
-  assignment: Lab 2
-  due date: 8/30/2022
-   
-  Date Modified: 8/30/2022
-    - File Created
-  
-  Creating and Accessing Dynamic Objects
*/

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
  string *str = new string("Hello World!");

  // using the indirection operator to access the public interface of string
  cout << (*str).length() << endl;

  // using the structure pointer operator to access the public interface of string
  cout << str->length() << endl;

  cout << str->c_str() << endl;
  cout << (*str).c_str() << endl;

  delete str;

  return 0;
}