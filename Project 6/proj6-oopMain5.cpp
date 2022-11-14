/**
 * file: proj6-oopMain5.cpp
 * author: Wesley Anastasi
 * course: CSI 1440
 * assignment: project 6
 * due date: 11/14/2022
 *
 * date modified: 11/14/2022
 * - created file
 * 
 * oop Main
 */

#include <iostream>
#include <fstream>

using namespace std;

const int PLIST_SIZE = 10;

class Customer {
  string name;
  int age;
  double shippingRate;

public:
  string getName() { return name; }
  void readPerson( istream & );
  void writePerson( ostream & );
};

void Customer::readPerson( istream &in ) {
  getline( in, name );
  in >> age;
  in.ignore(3, '\n');
  in >> shippingRate;
  cin.ignore(3, '\n');
}

void Customer::writePerson( ostream &out ) {
  out << name << endl;
  out << age << endl;
  out << shippingRate << endl;
}

class Mega {
  string name;
  int age;

public:
  string getName() { return name; }
  void readPerson( istream & );
  void writePerson( ostream & );
};

void Mega::readPerson( istream &in ) {
  getline( in, name );
  in >> age;
  in.ignore(3, '\n');
}

void Mega::writePerson( ostream &out ) {
  out << name << endl;
  out << age << endl;
}

class Person {
  string name;
  int age;

public:
  string getName() { return name; }
  void readPerson( istream & );
  void writePerson( ostream & );
};

void Person::readPerson( istream &in ) {
  getline( in, name );
  in >> age;
  in.ignore(3, '\n');
}

void Person::writePerson( ostream &out ) {
  out << name << endl;
  out << age << endl;
}

void requestInfo( ostream &out, string msg ) {
  out << msg << endl;
}

string readAgain( ostream &out, istream &in ) {
  string choice;  

  out << "Do you want to read in another person (yes/no)? " << endl;
  in >> choice;
  in.ignore(3, '\n');
  
  return choice;
}

int findItem( Person pList[], string name ) {
  int pos = -1, index = 0;  

  while( pos == -1 && index < PLIST_SIZE ) {
    if( pList[index].getName() == name ) {
      pos = index;
    }
    index++;
  }

  return pos;
}

int findItem( Customer pList[], string name ) {
  int pos = -1, index = 0;  

  while( pos == -1 && index < PLIST_SIZE ) {
    if( pList[index].getName() == name ) {
      pos = index;
    }
    index++;
  }

  return pos;
}

int findItem( Mega pList[], string name ) {
  int pos = -1, index = 0;  

  while( pos == -1 && index < PLIST_SIZE ) {
    if( pList[index].getName() == name ) {
      pos = index;
    }
    index++;
  }

  return pos;
}

template<typename T>
void personChoice(ifstream &pfile, ofstream &opfile, string choice, bool fileRead, string msg, T item[])
{
  int index = 0;
  opfile.open("operson.txt");
  choice = "yes";

  if (fileRead) {
    item[index].readPerson(pfile);
    if (!pfile) {
      choice = "no";
    }
  }

  while (choice != "no" && index < PLIST_SIZE) {
    if (!fileRead) {
      requestInfo(cout, msg);
      item[index].readPerson(cin);
    }

    item[index].writePerson(opfile);

    index++;
    if (!fileRead) {
      choice = readAgain(cout, cin);
    } else {
      item[index].readPerson(pfile);
      if (!pfile) {
        choice = "no";
      }
    }
  }

  if (fileRead) {
    pfile.close();
  }
  opfile.close();

  cout << "Which person are you looking for? " << endl;
  getline(cin, choice);

  if ((index = findItem(item, choice)) != -1) {
    cout << "Found your person: " << endl;
    item[index].writePerson(cout);
  } else {
    cout << "Couldn't find your person: " << choice << endl;
  }
}

int main() {
  Person pList[PLIST_SIZE];
  Customer cList[PLIST_SIZE];
  Mega mList[PLIST_SIZE];
  string choice;
  string pTypeChoice;
  int index = 0;
  bool fileRead = false;
  ifstream pfile;
  ofstream opfile;

  cout << "Would you like to read the data from a file (yes/no)? " << endl;
  cin >> choice;
  cin.ignore(3, '\n');

  if (choice == "yes") {
    fileRead = true;
    pfile.open("iperson.txt");
    
    if (!pfile) {
      cerr << "Can't open person.txt for read." << endl;
      return 1;
    }
    pfile >> pTypeChoice;
    pfile.ignore(3, '\n');
    
  } else {
    cout << "What type of Person? (person/customer/mega)" << endl;
    cin >> pTypeChoice;
    cin.ignore(3, '\n');
  }

  if (pTypeChoice == "person") {
    personChoice(pfile, opfile, choice, fileRead, "Please enter your name followed by your age.", pList);
  } else if(pTypeChoice == "customer"){
    personChoice(pfile, opfile, choice, fileRead, "Please enter your name followed by your age then shipping rate.", cList);
  } else {   
    personChoice(pfile, opfile, choice, fileRead, "Please enter your name followed by your age.", mList);
  }

  return 0;
}