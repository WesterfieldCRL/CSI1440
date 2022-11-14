/**
 * file: Driver7.cpp
 * author: Wesley Anastasi
 * course: CSI 1440
 * assignment: Lab 5
 * due date: 10/18/2022
 *
 * date modified: 10/18/2022
 * - created file
 * 
 * Driver 7
 */

 #include "Dogs7.h"


 void WalkTheDog( Dog &aDog ) {
  aDog.Pant();
  aDog.Bark();
  aDog.Pant();
}

void BegForFood( Dog &aDog ) {
  aDog.Wimper();
  aDog.Bark();
}

int main() {
  Dog *doggies[] = { new Dog("Fido"), new BostonTerrier("Dixie"), new Heinz57("Bones"),
            new HuckleberryHound("Huck"), new Poodle("Frenchy"), 
            new ScoobyDoo("Scooby"), new GermanSheperd("SgtShultz") };

  for( int i = 0; i < 7; i++ ) {
    cout << "Walking " << doggies[i]->getName() << "..." << endl;
    WalkTheDog( *doggies[i] );    

    cout << endl << doggies[i]->getName() << " is begging again..." << endl;

    BegForFood( *doggies[i] );     
    cout << endl;
  }

  return 0;
}