#ifndef LAB4_INTARRAY_H
#define LAB4_INTARRAY_H

#include "lab4-LabArray.h"

class IntArray : public LabArray { 
  private:
  
  int test;

  public:
  IntArray(); //default constructor
  ~IntArray(); //destructor
  IntArray(const IntArray &); //copy constructor
  IntArray& operator = (const IntArray&); //overloaded assignment operator
  int getVal(int);  // notice loss of virtual and = 0
  int getCapacity();
  int getSize();
  void insertVal(int);
  int removeVal();
};

#endif