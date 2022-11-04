#include "proj7-ContainerIfc.h"

template <class T>
class MyVector : public ContainerIfc<T> {
public:

/** 
 * MyVector ()
 * 
 * creates a MyVector object with size = 0, capacity = 10
 * 
 * Parameters: 
 *      none
 * 
 * Output: 
 *      return:  none
 *      reference parameters: none 
 *      stream:  none 
 */
  MyVector ();

/** 
 * ~MyVector
 * 
 * all memory allocated to the MyVector is deleted
 * 
 * Parameters: 
 *      none
 * 
 * Output: 
 *      return:  none
 *      reference parameters: none 
 *      stream:  none 
 */
  ~MyVector ();

/** 
 * MyVector
 * 
 * creates a MyVector as a copy of the provided MyVector object
 * 
 * Parameters: 
 *      MyVector, object being copied
 * 
 * Output: 
 *      return:  none
 *      reference parameters: MyVector
 *      stream:  none 
 */
  MyVector (const MyVector&);

  /** 
 * operator=
 * 
 * makes an exact copy of the data from the provided MyVector
 * into this MyVector
 * 
 * Parameters: 
 *      MyVector, object being copied
 * 
 * Output: 
 *      return:  none
 *      reference parameters: MyVector
 *      stream:  none 
 */
  MyVector<T>& operator = (const MyVector&);

  /** 
 * pushFront
 * 
 * 
 * 
 * Parameters: 
 *      none
 * 
 * Output: 
 *      return:  none
 *      reference parameters: none 
 *      stream:  none 
 */
  MyVector<T>& pushFront(T);
  MyVector<T>& pushBack(T);
  MyVector<T>& popFront(T&);
  MyVector<T>& popBack(T&);
  T  front();
  T  back();
  T&  operator [](int);
  int getSize();
  bool isEmpty();
  void erase();

private:
  T  *data;
  int size;
  int capacity;
  void grow();
  void shiftRight();
  void shiftLeft();
};