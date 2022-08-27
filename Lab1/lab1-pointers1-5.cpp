/**
-  file: lab1-pointers1-5.cpp
-  author:  Wesley Anastasi
-  course: CSI 1440
-  assignment: Lab 1
-  due date: 8/23/2022
-   
-  Date Modified: 8/23/2022
-    - File Created
-  
-  Pointer as Parameters
*/

#include <iostream>
#include <cmath>

using namespace std;

/**
-  changeIt
-   
-  This function changes the value of the parameter passed to it using 
-    pointers to a random int between -1 and 100.
-  
-  Parameters:  
-    n: an address of variable declared locally in the calling function
-  
-  Output:  
-    return: none
-    parameters: n - the changed value at the address passed
-    stream: none
*/
//creates function changeIt
void changeIt( int *n )
{
    //assigns the random value to the value at the address passed
    *n = rand()%100;
}

int main() {
    //creates variables
   int x, y, z;

    //assigns variables a value
   x = y = z = 1;

    //prints the original value and then sends a call to changeIt() and prints a new value
   cout << "x's value was " << x << " before a call to changeIt()" << endl;
   changeIt( &x );
   cout << "x's value is " << x << " after a call to changeIt()" << endl;

   cout << "y's value was " << y << " before a call to changeIt()" << endl;   
   changeIt( &y );
   cout << "y's value is " << y << " after a call to changeIt()" << endl;

   cout << "z's value was " << z << " before a call to changeIt()" << endl;
   changeIt( &z );
   cout << "z's value is " << z << " after a call to changeIt()" << endl;

   return 0;
}