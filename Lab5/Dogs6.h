/**
 * file: Dogs6.h
 * author: Wesley Anastasi
 * course: CSI 1440
 * assignment: Lab 5
 * due date: 10/18/2022
 *
 * date modified: 10/18/2022
 * - created file
 * 
 * Dogs 6
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

class HuckleberryHound : public Dog {
public:
  HuckleberryHound( string n ) : Dog( n ) { }

  void Bark() {
    cout << "Oh, my darlin" << endl;
  }
};

class Poodle : public Dog {
public:
  Poodle( string n ) : Dog( n ) { }

  void Bark() {
    cout << "Oui-Oui" << endl;
  }
};

class ScoobyDoo : public Dog {
public:
  ScoobyDoo( string n ) : Dog( n ) { }

  void Bark() {
    cout << "Ruh-Roh" << endl;
  }
};

class GermanSheperd : public Dog {
public:
  GermanSheperd( string n ) : Dog( n ) { }

  void Bark() {
    cout << "I see nothing!" << endl;
  }
};