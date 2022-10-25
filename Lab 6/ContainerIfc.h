/**
 * file: ContainerIfc.h
 * author: Wesley Anastasi
 * course: CSI 1440
 * assignment: Lab 6 
 * due date: 10/25/2022
 *
 * date modified: 10/25/2022
 * - created file
 * 
 * ContainerIfc class
 */

#ifndef CONTAINERIFC_H
#define CONTAINERIFC_H

#include <string>

using namespace std;

class BADINDEX{};

template <class T>
class ContainerIfc {
public:
  virtual ContainerIfc<T>& pushBack(T) = 0;
  virtual ContainerIfc<T>& popBack(T &) = 0;  // throws BADINDEX
  virtual int getSize() = 0;
  virtual bool isEmpty() = 0;
  virtual T& operator[](int) = 0;  // throws BADINDEX
  virtual string toString() = 0;
};

#endif