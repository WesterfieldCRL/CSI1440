/**
 * file: Dogs1.h
 * author: Wesley Anastasi
 * course: CSI 1440
 * assignment: Lab 5
 * due date: 10/18/2022
 *
 * date modified: 10/18/2022
 * - created file
 * 
 * Dogs 1
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

  void Bark() {
    cout << "Bow-Wow" << endl;
  }
};

class BostonTerrier {
private:
  string name;

public:
  BostonTerrier( string n ) {
    name = n;
  }

  string getName() {
    return name;
  }   

  void Bark() {
    cout << "Arf-Arf" << endl;
  }
};

class Heinz57 {
private:
  string name;

public:
  Heinz57( string n ) {
    name = n;
  }

  string getName() {
    return name;
  }

  void Bark() {
    cout << "Bow-Wow" << endl;
  }
};