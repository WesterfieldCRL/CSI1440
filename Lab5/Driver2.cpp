/**
 * file: Driver2.cpp
 * author: Wesley Anastasi
 * course: CSI 1440
 * assignment: Lab 5
 * due date: 10/18/2022
 *
 * date modified: 10/18/2022
 * - created file
 * 
 * Driver 2
 */
 
 #include "Dogs2.h"

int main(){
  Dog aDog("Fido");
  cout << aDog.getName() << " says ";
  aDog.Bark();

  BostonTerrier aBoston("Dixie");
  cout << aBoston.getName() << " says ";
  aBoston.Bark();

  Heinz57 aHeinz("Bones");
  cout << aHeinz.getName() << " says ";
  aHeinz.Bark();

  return 0;
}