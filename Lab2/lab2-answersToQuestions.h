//Wesley Anastasi
//CSI 1440 Section 2
//Lab 2

//1. What would be printed if we just incremented the pointer (myPtr++)?
// it prints "ello World!" Instead of hello world!.
//2. How does “myArray += 6” differ from what we talked about in class - “*(myArray + 6)” - which we said was OK?
// myArray += 6 doesnt dereference. *(myArray + 6) = x is used to assign a value to location 6 of the array.
//3. Replace the array notation statements with pointer notation statements for the assignment of ‘o’, ‘w’, ‘d’, and ‘y’.
/*
  *(myArray + 1) = 'o';
  *(myArray + 2) = 'w';
  *(myArray + 3) = 'd';
  *(myArray + 4) = 'y';
*/
//4. Could this code be fixed by using pointer notation instead of array notation? Why/Why not?
// no, they both do the same thing, so changing notation will not change the result
//5. Why did we not give the memory back to the computer, using the delete operator, within the function?
// because then the array would not exist outside of the function
//7. Write two additional lines of code to print out the contents of str as a c-string representation 
//using c_str() with both the indirection operator and the structure pointer operator.
/*
  cout << str->c_str() << endl;
  cout << (*str).c_str() << endl;
*/