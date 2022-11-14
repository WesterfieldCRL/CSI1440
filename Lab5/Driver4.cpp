/**
 * file: Driver4.cpp
 * author: Wesley Anastasi
 * course: CSI 1440
 * assignment: Lab 5
 * due date: 10/18/2022
 *
 * date modified: 10/18/2022
 * - created file
 * 
 * Driver 4
 */
 
 #include "Dogs4.h"


 void WalkTheDog( Dog &aDog ) {
  aDog.Pant();
  aDog.Bark();
  aDog.Pant();
}

void BegForFood( Dog &aDog ) {
  aDog.Wimper();
  aDog.Bark();
}

int main(){
  Dog aDog("Fido");
  cout << aDog.getName() << " says ";
  aDog.Bark();
  WalkTheDog(aDog);
  BegForFood(aDog);

  BostonTerrier aBoston("Dixie");
  cout << aBoston.getName() << " says ";
  aBoston.Bark();
  WalkTheDog(aBoston);
  BegForFood(aBoston);

  Heinz57 aHeinz("Bones");
  cout << aHeinz.getName() << " says ";
  aHeinz.Bark();
  WalkTheDog(aHeinz);
  BegForFood(aHeinz);

  return 0;
}