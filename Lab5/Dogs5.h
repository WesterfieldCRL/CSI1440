/**
 * file: Dogs5.h
 * author: Wesley Anastasi
 * course: CSI 1440
 * assignment: Lab 5
 * due date: 10/18/2022
 *
 * date modified: 10/18/2022
 * - created file
 * 
 * Dogs 5
 */

#include <iostream>
#include <string>

using namespace std;
 
class Dog {
private:
  string name;

public:
  Dog( string n ) {
    name = n;
  }

  string getName() {
    return name;
  }   

  virtual void Bark() {
    cout << "Bow-Wow" << endl;
  }

  void Wimper() {
    cout << "Rrrrrrrrr" << endl;
  }

 void Pant() {
    cout << "Ah-ha-ha-ha-ha" << endl;
  }
};

 
class BostonTerrier : public Dog {
public:
  BostonTerrier( string n ) : Dog( n ) { }

  void Bark() {
    cout << "Arf-Arf" << endl;
  }
};

class Heinz57 : public Dog {
public:
  Heinz57( string n ) : Dog( n ) { }
};