/**
 * file: proj6-modularMain3.cpp
 * author: Wesley Anastasi
 * course: CSI 1440
 * assignment: project 6
 * due date: 11/14/2022
 *
 * date modified: 11/13/2022
 * - created file
 * 
 * modular Main
 */

#include <iostream>
#include <fstream>

using namespace std;

const int PLIST_SIZE = 10;

class Person {
protected:
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

class Customer : public Person {
protected:
  double shippingRate;

public:
  Customer();
  double getShippingRate();
  void readPerson( istream & );
  void writePerson( ostream & );
};

Customer::Customer() {
  shippingRate = 5.0;
}

double Customer::getShippingRate() {
  return shippingRate;
}

void Customer::readPerson( istream & in ) {
  Person::readPerson(in);
  in >> shippingRate;
  cin.ignore(3, '\n');
}

void Customer::writePerson( ostream & out ) {
  Person::writePerson(out);
  out << shippingRate << endl;
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

string pChoiceTypeFunction(ifstream &in)
{
  string output;
  in >> output;
  in.ignore(3, '\n');
  return output;
}

string getPersonType()
{
  string output;
  cout << "What type of Person? (person/customer)" << endl;
  cin >> output;
  cin.ignore(3, '\n');
  return output;
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
  string name, choice;
  string pTypeChoice;
  int age;
  bool fileRead = false;
  ifstream pfile;
  ofstream opfile;

  cout << "Would you like to read the data from a file? " << endl;
  cin >> choice;
  cin.ignore(3, '\n');

  if( choice == "yes" ) {
    fileRead = true;
    pfile.open("iperson.txt");
    if( !pfile ) {
      cerr << "Can't open person.txt for read." << endl;
      return 1;
    }

    pTypeChoice = pChoiceTypeFunction(pfile);

  }
  else
  {
    pTypeChoice = getPersonType();
  }


  if (pTypeChoice == "person")
  {
    personChoice(pfile, opfile, choice, fileRead, "Please enter your name followed by your age.", pList);
  }
  else
  {
    personChoice(pfile, opfile, choice, fileRead, "Please enter your name followed by your age then shipping rate", cList);
  }

  return 0;
}